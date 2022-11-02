#include <bits/stdc++.h>
using namespace std;


#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define pll pair < ll, ll >
#define all(s) s.begin(), s.end()
#define sz(s) (int) s.size()
#define vi vector < int >

const int inf = (1ll << 31) - 1;
const int mod = (int) 1e9 + 7;
struct node{
    int ty, a, b, t, v;
};

node a[11111];

int tb[22][22];
ll dp[22];
int n, m, q;
bool was[22];
ll mat[22][22];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
ll dp2[22];

ll c[22][22], d[22][22];


void power(int t){
    int len = n * m;
    for(int i = 0; i<len;i++){
        for(int j = 0; j < len; j++)
            c[i][j] = (i == j);
    }
    while(t > 0){
        if( t & 1){

            memset(d, 0, sizeof d);
            for(int i = 0; i <len; i++){
                for(int j = 0; j < len; j++){
                    for(int k = 0; k < len ; k++){
                        d[i][j] += c[i][k] * mat[k][j];
                        d[i][j] %= mod;
                    }
                    
                }
            }
            for(int i = 0; i < len; i++)
                for(int j = 0; j < len; j++)
                    c[i][j] = d[i][j];
        }
        
        memset(d, 0, sizeof d);
        for(int i = 0; i <len; i++){
                for(int j = 0; j < len; j++){
                    for(int k = 0; k < len ; k++){
                        d[i][j] += mat[i][k] * mat[k][j];
                        d[i][j] %= mod;
                    }

                }
            }
        for(int i = 0 ;i < len; i++){
            for(int j = 0; j < len; j++)
                mat[i][j] = d[i][j];
        }
        t/=2;
    }
    for(int i = 0 ;i < len; i++){
            for(int j = 0; j < len; j++)
                mat[i][j] = c[i][j];
        }
}
ll ans= 0;

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    scanf("%d %d %d", &n, &m, &q);
    
    dp[0] = 1;
    int prev = 1;
    for(int i = 0; i < q; i++){
        scanf("%d %d %d %d", &a[i].ty, &a[i].a, &a[i].b, &a[i].t);
        a[i].v=(a[i].a * m + a[i].b - m - 1);
        memset(mat, 0, sizeof mat);
        for(int t = 0; t< n; t++){
            for(int j = 0; j < m; j++){
                if(was[t * m + j]) continue;
                mat[t * m + j][t *m + j] = 1;
                for(int k = 0; k < 4; k++){
                    int x = dx[k] + t;
                    int y = dy[k] + j;
                    if( x< 0 || x >= n || y < 0 || y >= m) continue;
                    if(was[x * m + y]) continue;
                    mat[x * m + y][t * m + j] = 1;
                }
            }
        }
        power(a[i].t - prev);
        memset(dp2, 0, sizeof dp2);
        for(int t = 0; t< n * m; t++){
            for(int j = 0; j < n * m ; j++){
                //for(int k = 0; k < n * m; k++){
                dp2[t] = (dp2[t] + mat[j][t] * 1ll * dp[j]) % mod;
                //}
            }
        }
        for(int t = 0; t < n *m ; t++){
            dp[t] = dp2[t];
        }
        if(a[i].ty == 3){
            was[a[i].v] = 0;
        }else if(a[i].ty == 2){
            was[a[i].v] = 1;
        }
        else {
            cout << dp[a[i].v] % mod << "\n";
        }
        prev = a[i].t;
    }
        



    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}