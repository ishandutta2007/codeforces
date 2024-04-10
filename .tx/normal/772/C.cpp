#include <bits/stdc++.h>
using namespace std;

template<typename T>
void sci(T& t) {
    cin >> t;
}

template<typename T, typename... Ts>
void sci(T& t, Ts&... ts) {
    sci(t);
    sci(ts...);
}

#define scid(vars...) int vars; sci(vars)
#define scidl(vars...) lint vars; sci(vars)
#define scidd(vars...) double vars; sci(vars)
#define scids(vars...) string vars; sci(vars)

template <typename T, typename Cmp=std::greater<T>>
using heap = priority_queue<T, std::vector<T>, Cmp>;

typedef long long lint;

int gcd(int a, int b, int & x, int & y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    int x1, y1;
    int d = gcd (b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

int gcd(int a, int b) {
    int x, y;
    return gcd(a, b, x, y);
}

int back(int v, int m) {
    int x, y;
    int g = gcd(v, m, x, y);
    assert(g == 1);
    return (x % m + m) % m;
}

const int A = 18;

bool bad[222222];
int cnt[222222];
bool good[1 << A];
int pr[A];
int pc = 0;
int dp[1 << A];
int par[1 << A];
int num[1 << A];

vector<int> rems[222222];

int main() {
#ifdef TOXA31
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    scid(n, m);
    for (int i = 0; i < n; i++) {
        scid(x);
        bad[x] = true;
    }

    for (int i = 1; i < m; i++) {
        if (bad[i]) {
            continue;
        }

        int g = gcd(i, m);
        cnt[g]++;
        rems[g].push_back(i);
    }

    int om = m;
    for (int i = 2; i * i <= m; i++) {
        while (m % i == 0) {
            pr[pc++] = i;
            m /= i;
        }
    }

    if (m != 1) {
        pr[pc++] = m;
    }
    m = om;

    for (int msk = 0; msk < (1 << A); msk++) {
        int lst = 1;
        good[msk] = true;
        for (int i = 0; i < A; i++) {
            if ((msk >> i) & 1) {
                if (i >= pc || (lst == 0 && pr[i] == pr[i - 1])) {
                    good[msk] = false;
                    break;
                }
                lst = 1;
            } else {
                lst = 0;
            }
        }

        if (good[msk]) {
            num[msk] = 1;
            for (int i = 0; i < A; i++) {
                if ((msk >> i) & 1) {
                    num[msk] *= pr[i];
                }
            }
        }
    }

    memset(par, -1, sizeof(par));

    for (int msk = 0; msk < (1 << A); msk++) {
        if (!good[msk]) {
            continue;
        }
        dp[msk] = cnt[num[msk]];
        for (int i = 0; i < A; i++) {
            if ((msk >> i) & 1) {
                int pr = msk & ~(1 << i);
                if (dp[pr] + cnt[num[msk]] > dp[msk]) {
                    dp[msk] = dp[pr] + cnt[num[msk]];
                    par[msk] = pr;
                }
            }
        }
    }


    int mx = 0;
    for (int i = 1; i < (1 << A); i++) {
        if (dp[i] > dp[mx]) {
            mx = i;
        }
    }

    vector<int> res;
    while (mx != -1) {
        res.push_back(mx);
        mx = par[mx];
    }

    reverse(res.begin(), res.end());

    int lst = -1;
    int lg = -1;
    vector<int> ans;

    for (int msk : res) {
        int g = num[msk];
        for (int i : rems[g]) {
            if (lst == -1) {
                ans.push_back(i);
                lst = i;
                lg = g;
                continue;
            }

//            int v = lst / lg;
//            int b = back(v, m);
//            lint x = 1LL * b * (i / lg);
//            ans.push_back(x % m);

            int x, y;
            gcd(lst / lg, m / lg, x, y);
            x = (x % m + m) % m;
            lint tx = 1LL * x * i / lg;
            ans.push_back(tx % m);
            lst = i;
            lg = g;
        }
    }

    if (!bad[0]) {
        ans.push_back(0);
    }

    cout << ans.size() << "\n";

    for (int i : ans) {
        cout << i << " ";
    }

    return 0;
}