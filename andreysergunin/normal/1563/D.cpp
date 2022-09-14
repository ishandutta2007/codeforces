#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")
 
#include <bits/stdc++.h>
 
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
using ld = long double; 
// using ld = __float128;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using uint = unsigned int;
using ull = unsigned long long;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
// default_random_engine generator;

void solve();
void precalc();

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout); 
#endif 

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(12) << fixed;
    cerr << setprecision(12) << fixed;

    int tests = 1;
    cin >> tests;

    precalc();
    for (int test = 1; test <= tests; ++test) {
        // cout << "Case #" << test << ": ";
        solve();
    }

#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}

// ----------------------------------------------------------------- 

const int P = 998244353;
void mul(int &a, int b)  {
    a = ll(a) * b % P;
}

const int MAXN = 200200;
const int MAGIC = 500;
const int MAXM = MAXN / MAGIC + 1;

struct Data {
    int len;
    bool flag;
};

vector<Data> arr[MAXM];
int sum[MAXM];

void rebuild() {
    vector<Data> a;
    for (int i = 0; i < MAXM; ++i) {
        for (const Data &x : arr[i]) {
            a.push_back(x);
        }
        arr[i].clear();
        arr[i].shrink_to_fit();
        sum[i] = 0;
    }
    for (int i = 0; i < sz(a); ++i) {
        arr[i / MAGIC].push_back(a[i]);
        sum[i / MAGIC] += a[i].len;
    }
}

int get() {
    int cnt = 0;
    for (int i = 0; i < MAXM; ++i) {
        for (const Data &x : arr[i]) {
            cnt += x.flag;
        }
    }
    return cnt;
}

void print() {
    for (int i = 0; i < MAXM; ++i) {
        for (const Data &x : arr[i]) {
            cerr << x.len << " " << x.flag << endl;
        }
    }
    cerr << endl;
}

void add(int pos, int len) {
    for (int i = 0; i < MAXM; ++i) {
        if (pos < sum[i]) {
            for (int j = 0; j < sz(arr[i]); ++j) {
                if (pos < arr[i][j].len) {
                    arr[i][j].len -= pos;
                    bool flag = (pos > 0) && arr[i][j].flag;
                    arr[i][j].flag = true;
                    arr[i].insert(arr[i].begin() + j, Data{len + pos, flag});
                    sum[i] += len;
                    break;
                } else {
                    pos -= arr[i][j].len;
                }
                assert(j + 1 != sz(arr[i]));
            }
            if (sz(arr[i]) >= 2 * MAGIC) {
                rebuild();
            }
            break;
        } else {
            pos -= sum[i];
        }
        assert(i + 1 != MAXM);
    }
}

int last() {
    for (int i = MAXM - 1; i >= 0; --i) {
        if (sz(arr[i]) > 0) {
            return i;
        }
    }
    assert(false);
}

int fact[2 * MAXN], inv[2 * MAXN], rfact[2 * MAXN];

void precalc() {
    inv[1] = 1;
    for (int i = 2; i < 2 * MAXN; ++i) {
        inv[i] = ll(P - P / i) * inv[P % i] % P;
    }

    fact[0] = rfact[0] = 1;
    for (int i = 1; i < 2 * MAXN; ++i) {
        fact[i] = fact[i - 1];
        mul(fact[i], i);
        rfact[i] = rfact[i - 1];
        mul(rfact[i], inv[i]);
    }
}

void solve() {  
    for (int i = 0; i < MAXM; ++i) {
        arr[i].clear();
        arr[i].shrink_to_fit();
        sum[i] = 0;
    }

    int n, m;
    cin >> n >> m;
    vector<pii> p(m);
    for (auto &[x, y] : p) {
        cin >> x >> y;
        --x; --y;
    }

    if (m == 0) {
        arr[0].push_back({n, 0});
        sum[0] = n;
    } else {
        arr[0].push_back({p[0].first, 0});
        sum[0] = p[0].first;
    }
    
    // print();

    for (int i = 0; i < m; ++i) {
        auto [x, y] = p[i];
        add(y, 1);
        int z = (i == m - 1 ? n : p[i + 1].first);

        int j = last();
        arr[j].back().len += (z - x - 1);
        sum[j] += (z - x - 1);
        // print();
    }

    // int sum = 0;
    // for (int i = 0; i < MAXM; ++i) {
    //     for (const Data &x : arr[i]) {
    //         sum += x.len;
    //     }
    // }
    // assert(sum == n);


    int cnt = get();

    // cout << 2 * n - cnt - 1 << " " << n << endl;

    int res = fact[2 * n - cnt - 1];
    mul(res, rfact[n]);
    mul(res, rfact[n - cnt - 1]);

    cout << res << endl;

}