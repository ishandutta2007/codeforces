#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
typedef long long i64;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int mod = 1e9 + 7;
const int M = 1000100;

int mul(ll x, ll y) {
    return x * y % mod;
}

int n;
bool used[M];
vector<int> p[M];
vector<int> c[M];
int pred[M];
int b[M];
int cnt[M];
int f[M];
int fun[M];

void sito() {
    fill(pred, pred + M, 1);
    cnt[1]++;
    p[1].push_back(1);
    c[1].push_back(1);
    for (int i = 2; i < M; ++i)
        if (!used[i]) {
            int cl = n / i;
            cnt[cl]++;
            for (int j = i; j < M; j += i) {
                used[j] = true;
                pred[j] *= i;
                p[j].push_back(i);
                c[j].push_back(cl);
            }
        }

    for (int i = 1; i <= n; ++i)
        b[pred[i]]++;
}

void pre() {
    f[0] = 1;
    for (int i = 1; i < M; ++i)
        f[i] = mul(f[i - 1], i);
}

signed main() {
#ifdef LOCAL
    assert(freopen("f.in", "r", stdin));
#endif

    //ios_base::sync_with_stdio(false);

    pre();

    scanf("%d", &n);

    sito();

    fill(fun, fun + M, -1);

    for (int i = 1; i <= n; ++i) {
        int x;
        scanf("%d", &x);
        if (x == 0)
            continue;

        if (c[x] != c[i]) {
            cout << "0\n";
            //cerr << "first" << endl;
            
            return 0;
        }

        b[pred[x]]--;

        for (int j = 0; j < (int) c[x].size(); ++j) {
            int a = p[i][j];
            int b = p[x][j];
            int ca = c[i][j];
            if (fun[a] == -1) {
                fun[a] = b;
                --cnt[ca];
            }

            if (fun[a] != b) {
                cout << "0\n";
                return 0;
            }
        }
    }

    int ans = 1;
    for (int i = 1; i <= n; ++i)
        ans = mul(ans, f[cnt[i]]);
    for (int i = 1; i <= n; ++i)
        ans = mul(ans, f[b[i]]);

    cout << ans << endl;


#ifdef LOCAL
    cerr << "Time: " << clock()/1000 << " ms" << endl;
#endif
}