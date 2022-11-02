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

int n, m;
vector < int > g[1000 * 1000 + 1000];
char c[1010][1010];
ll dp[1010][1010][4];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
void calc( char cc, int ind){
    deque < pii > q;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            dp[i][j][ind] = ( 1ll << 50);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if( c[i][j] == cc){
                dp[i][j][ind] = 0;
                q.push_back(mp(i, j));
            }
        }
    }
    while( q.size() > 0){
        pii x = q.front();
        q.pop_front();
        for(int i = 0; i < 4; i++){
            int X = dx[i] + x.f;
            int Y = dy[i]  + x.s;
            if( X < 0 || X >= n || Y < 0 || Y>=m) continue;
            if(c[X][Y] == '#') continue;
            ll val = dp[x.f][x.s][ind] + (c[X][Y] == '.');
            if( val < dp[X][Y][ind]){
                dp[X][Y][ind] = val;
                if(c[X][Y] != '.')
                    q.push_front(mp(X,Y));
                else
                    q.push_back(mp(X,Y));
            }
        }
    }
}
ll cur[10];
void calc2(int ind, ll &ans){
    char cc = ind + '1';
    ll mini = 0;
    for(int i = 0; i < 3; i++)
        cur[i] = (1ll<<50);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if( c[i][j] == '.' || c[i][j] == '#' || c[i][j] == cc ) continue;
            cur[c[i][j]-'1'] = min(cur[c[i][j]-'1'] , dp[i][j][ind]);
        }
    }
    for(int i = 0; i < 3; i++)
        mini += cur[i];
    mini -= cur[ind];
    if(mini < ans) ans = mini;
}
int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    scanf("%d %d",  &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%s", &c[i]);
    }
    calc('1', 0);
    calc('2', 1);
    calc('3', 2);
    ll ans = (1ll << 50);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(c[i][j] !='.') continue;
            ll sum  = -2;
            for(int k = 0; k < 3; k++){
                sum += dp[i][j][k];
            }
            if( sum < ans) ans = sum ;
        }
    }

    calc2(0, ans);
    calc2(1, ans);
    calc2(2, ans);
    if( ans > ( 1ll << 40) )ans = -1;
    cout << ans << endl;
    


    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}