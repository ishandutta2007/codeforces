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
#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define pll pair < ll, ll >
#define forit(s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()
#define Vint vector < int >
#define Vll vector < ll >
#define Vb vector < bool >
#define Vpii vector < pii >
#define Vpll vector < pll >

const int inf = (1ll << 31) - 1;

#define MAXN (int) (1e7)
using namespace std;
vector < int > v[111];
int n,k, a, b, cnt = 0;
int used[111], d[111];
void dfs(int x, int k, int lev= 0){
    used[x] = 1;
    d[x]=lev;
    cnt++;
    for(int i = 0; i < v[x].size(); i++){
        int to = v[x][i];
        if(used[to] == 0) dfs(to, x, lev+1);
        else if(used[to] == 1){
            if(k != to && d[to] % 2 == d[x] % 2) cnt--;
        }
    }
    used[x] = 2;
}
int main () {
    #ifdef LOCAL
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    #endif
    cin >> n >> k;
    for(int i = 0; i < k; i++){
        cin >> a >> b;
        v[a].pb(b);
        v[b].pb(a);
    }
    for(int i = 1; i <= n; i++){
        sort(v[i].begin(), v[i].end());
    }
    for(int i = 1; i <= n; i++){
        if( used[i] == 0 )
            dfs(i, -1);
    }
    if( cnt % 2 == 1 ) cnt--;
    cout << n - cnt << endl;
    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}