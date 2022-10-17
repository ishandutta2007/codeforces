#include <bits/stdc++.h>

using namespace std;

#define f1r(i, a, b) for (int i = a; i < b; i++)
#define f0r(i, a) f1r(i, 0, a)
#define trav(t, a) for (auto& t : a)

#define eb emplace_back
#define pb push_back
#define f first
#define s second
#define mp make_pair
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef double db;

template <class T> bool ckmax(T& a, T b) { return a < b ? a = b, 1 : 0; }
template <class T> bool ckmin(T& a, T b) { return a > b ? a = b, 1 : 0; }

const int N = 12;
const int W = 105;

int n, m, q;

int cost[(1 << N)];
int cnt[(1 << N)];
int ans[(1 << N)];

int val[(1 << N)][W];

int conv(string s) {
    int res = 0;
    f0r(i, n) {
        res += (1 << i) * (s[i] == '1'); 
    }
    return res;
}
int nxor(int x, int y) {
    return (1 << n) - 1 - (x^y);
}
int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m >> q;
    

    vi w(n);
    f0r(i, n) cin >> w[i];

    f0r(msk, (1<<n)) {
        int res = 0;
        f0r(j, n) {
            if ((1<<j)&msk) {
                res += w[j];
            }
        }
        cost[msk] = res;
    }

    vector<string> s(m);
    f0r(i, m) cin >> s[i];

    f0r(i, m) cnt[conv(s[i])]++;

    f0r(msk, (1<<n)) {
        f0r(nmsk, (1<<n)) {
            int nxt = nxor(msk, nmsk);
            if (cost[nxt] < W) {
                val[msk][cost[nxt]] += cnt[nmsk];
            }
        }
    }

    f0r(i, q) {
        string t; int k;
        cin >> t >> k;
        int v = conv(t);
        int ans = 0;
        f0r(i, k+1) {
            ans += val[v][i];
        }
        cout << ans << '\n';

    }



    return 0;
}