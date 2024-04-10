// khodaya khodet komak kon
// Toxicity
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
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}

const int xn = 2e2 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

int n, m, k, a[xn], dp[1 << 7][xn];
bitset <xn> mark[1 << 7][xn];
priority_queue <pii, vector <pii> , greater <pii> > pq;
 
void upd(int mask, int u, int v){
    if (dp[mask][u] + a[v] < dp[mask][v]){
        dp[mask][v] = dp[mask][u] + a[v];
        mark[mask][v] = mark[mask][u]; mark[mask][v][v] = 1;
        pq.push({dp[mask][v], v});
    }
}

int main(){
	InTheNameOfGod
	
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < m; j ++)
            cin >> a[i * m + j];
    memset(dp, 63, sizeof dp);
    for (int i = 0; i < k; i ++){
        int x, y;
        cin >> x >> y;
        -- x, -- y;
        int v = x * m + y;
        dp[1 << i][v] = a[v];
        mark[1 << i][v][v] = 1;
    }
    for (int mask = 1; mask < (1 << k); ++ mask){
        for (int v = 0; v < n * m; ++ v){
            for (int sub = (mask - 1) & mask; sub > 0; sub = (sub - 1) & mask){
                int d = dp[sub][v] + dp[mask ^ sub][v] - a[v];
                if (d < dp[mask][v])
                    dp[mask][v] = d, mark[mask][v] = mark[sub][v] | mark[mask ^ sub][v];
            }
            pq.push({dp[mask][v], v});
        }
        while (!pq.empty()){
            int v = pq.top().B, d = pq.top().A;
            pq.pop();
            if (dp[mask][v] != d)
                continue;
            if (0 <= v - m)
                upd(mask, v, v - m);
            if (v + m < n * m)
                upd(mask, v, v + m);
            if (0 < v % m)
                upd(mask, v, v - 1);
            if (v % m < m - 1)
                upd(mask, v, v + 1);
        }
    }
    int v = 0;
    for (int i = 0; i < n * m; i ++)
        if (dp[(1 << k) - 1][i] < dp[(1 << k) - 1][v])
            v = i;
    cout << dp[(1 << k) - 1][v] << endl;
    for (int i = 0; i < n; i ++, cout << '\n')
        for (int j = 0; j < m; j ++)
            cout << (mark[(1 << k) - 1][v][i * m + j] ? 'X' : '.');

    return 0;
}