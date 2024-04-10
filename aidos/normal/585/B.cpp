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

int n, k;
int dp[110][110][4];
string cur[4];

bool ok(int x, int y, int z){
    if( x+y >= n) return 1;
    int &res = dp[x][y][z];
    if( res != -1) return res;
    if( cur[z][x + y] != '.') return res = 0;
    if( x + y + 1 == n) return res = 1;
    if(cur[z][x + y + 1] != '.') return res=0;
    if( (x + 1 + y +1 >= n||cur[z][x + y + 2] == '.') && ( x + 1 + y + 2>= n || cur[z][x + y + 3] == '.') && ok(x+1, y + 2, z) ) return res = 1;
    for(int t = 0; t < 3; t++){
        if(abs(t - z) == 1){
            if(cur[t][x + y + 1]=='.' && (x + 1 + y + 1 >= n||cur[t][x + y + 2] == '.') &&( x + 1 + y + 2>= n || cur[t][x + y + 3] == '.')&& ok(x+1, y + 2, t) ){
                return res = 1;
            }
        }   
    }
    return res = 0;
}
void solve(){
    cin >> n >> k;
    for(int i = 0; i < 3; i++)
        cin >> cur[i];
    memset(dp, -1, sizeof dp);
    int x = 0;
    while(cur[x][0] != 's') x++;
    cur[x][0] = '.';
    if( ok(0, 0, x) ){
        cout << "YES\n";
    }
    else cout << "NO\n";
}

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        solve();
    }


    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}