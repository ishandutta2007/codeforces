//khodaya khodet komak kon
# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long                                        ll;
typedef long double                                      ld;
typedef pair <int, int>                                  pii;
typedef pair <pii, int>                                  ppi;
typedef pair <int, pii>                                  pip;
typedef pair <pii, pii>                                  ppp;
typedef pair <ll, ll>                                    pll;
 
# define A                                               first
# define B                                               second
# define endl                                            '\n'
# define sep                                             ' '
# define all(x)                                          x.begin(), x.end()
# define kill(x)                                         return cout << x << endl, 0
# define SZ(x)                                           int(x.size())
# define lc                                              id << 1
# define rc                                              id << 1 | 1
# define fast_io                                         ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 3e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 1e9 + 7;//998244353;
const int base = 257;
 
int qq, a[xn], b[xn], cnt[xn];
bool mark[xn];
vector <int> ans;
 
int main(){
    fast_io;

    cin >> qq;
    while (qq --){
        int n, m;
        cin >> n >> m;
        fill(cnt, cnt + n + 1, 0);
        for (int i = 1; i <= n; ++ i)
            cin >> a[i], ++ cnt[(i - a[i] + n) % n];
        ans.clear();
        for (int i = 0; i < n; ++ i){
            if (cnt[i] * 3 < n)
                continue;
            for (int j = 1; j <= n; ++ j)
                b[(j - i + n) % n] = a[j], mark[j] = false;
            b[n] = b[0];
            int res = 0;
            for (int j = 1; j <= n; ++ j){
                if (mark[j])
                    continue;
                int v = j, c = -1;
                while (!mark[v])
                    mark[v] = true, ++ c, v = b[v];
                res += c;
            }
            if (res <= m)
                ans.push_back(i);
        }
        cout << SZ(ans) << sep;
        for (int x : ans)
            cout << x << sep;
        cout << endl;
    }
    return 0;
}