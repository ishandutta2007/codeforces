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

#define MAXN (int) (3e5 + 10)
using namespace std;

int n, a, b;
int c[MAXN], comp[MAXN]; 
map < int, int> m;
bool used[MAXN];
vector < int > v[MAXN], gr[MAXN], dd;
void top(int g){
    used[g] = 1;
    for(int i = 0; i<v[g].size(); i++) if( !used[v[g][i]]) top(v[g][i]);
    dd.pb( g );
}

void dfs(int g, int x){
    comp[g] = x;
    used[g]  =1;
    for(int i = 0; i<gr[g].size(); i++) if( !used[gr[g][i]]) dfs(gr[g][i], x);
}

void dfs2(int g){
    if(used[g]) return;
    used[g]  =1;
    for(int i = 0; i<v[g].size(); i++) if( !used[v[g][i]]) dfs2(v[g][i]);
}


int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif

    cin >> n >> a >> b;
    for(int i = 0; i < n; i++) {
        cin >> c[i];
    }
    for(int i = 0; i < n; i++) m[c[i]] = i;

    for(int i = 0; i < n; i++) {
        if( m.count(a-c[i]) == 0&& m.count( b - c[i]) == 0){
            cout << "NO\n";
            return 0;
        }

    }
    if( a==b){
        for(int i = 0; i < n; i++) {
            if( m.count(a-c[i]) == 0){
                cout << "NO\n";
                return 0;
            }
        }
        cout << "YES\n";
        for(int i = 0; i < n; i++) cout << "0 ";
        return 0;
    }
    int k = n * 2;
    for(int i = 0; i < n; i++){
        int j = i * 2;
        if( m.count( a - c[i] ) == 0){
            v[j^1].pb(j);
        }else {
            int k = m[a-c[i]] * 2;
            v[j^1].pb(k ^ 1);
            v[k].pb(j);
        }
        if( m.count( b - c[i] ) == 0){
            v[j].pb(j^1);
        }else {
            int k = m[b-c[i]] * 2;
            v[j].pb(k );
            v[k^1].pb(j^1);
        }
    }

    for(int i = 0; i <= n; i++){
        if( !used[i * 2] ) top(i * 2);
        if( !used[i * 2 + 1] ) top(i * 2 + 1);
    }
    for(int i = 0; i<=n; i++){
        int j = i * 2 + 1;
        for(int t = 0; t < v[j].size(); t++){
            gr[v[j][t]].pb( j );
        }
        j = i * 2;
        for(int t = 0; t < v[j].size(); t++){
            gr[v[j][t]].pb( j );
        }
    }
    memset(used, 0, sizeof used);
    int sz = 0;
    for(int i = dd.size(); i>0; i--){
        if(!used[dd[i-1]]) dfs(dd[i-1], sz++);
    }

    for(int i = 0; i <= n; i++){
        if( comp[i * 2] == comp[i*2 + 1] ){
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    memset(used, 0, sizeof used);
    for(int i = dd.size(); i>0; i--){
        if(!used[dd[i-1]]) dfs2(dd[i-1]^1);
    }


    for (int i=0; i<n*2; i+=2) {
        printf ("%d ", used[i]);
    }

    




    

    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}