#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <ctime>

#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define ull unsigned long long
#define pll pair < ll, ll >
#define forit(s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()

const int inf = (1ll << 31) - 1;

#define MAXN (int) (1e7)
using namespace std;

int n, m;
vector < int > v[500];
int used[500];
void dfs(int x){
used[x] =  1;
    for(int i = 0;  i < v[x].size(); i++){
        int to = v[x][i];
        if(!used[to]) dfs(to);
    }
}

bool  check(int x, int y){
    int t=x * m + y;
    memset(used, 0, sizeof( used ));
    used[t]  =1;
    dfs(t);
    for(int i = 0; i < n * m; i++) if(!used[i]) return 0;
    return 1;
}


int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif

    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    for(int i = 0; i < n; i++){
        if( s[i] == '>') {
            for(int j = 1; j < m; j++){
                v[i * m + j-1].pb(i * m + j);
            }
        }
        else {
            for(int j = m-1; j >0; j--){
                v[i * m + j].pb(i * m + j-1);
            }
        }
    }
    for(int i = 0; i < m; i++){
        if( t[i] == '^') {
            for(int j = 1; j < n; j++){
                v[j * m + i].pb(j * m-m + i);
            }
        }
        else {
            for(int j = n-1; j >0; j--){
                v[j * m + i-m].pb(j * m + i);
            }
        }
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if( !check(i, j)){
                cout << "NO\n";
                return 0;
            }
        }
    }
    cout << "YES\n";

    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}