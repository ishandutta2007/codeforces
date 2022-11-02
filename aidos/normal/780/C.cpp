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
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()
#define sz(a) (int)a.size()

const int inf = (1ll << 30) - 1;
const int maxn = (int) 1e5 + 10;
const int mod = (int) 1e9 + 7;
using namespace std;

vector<int> a[300300];
int n;
pii e[300300];
int m = 0;
int ans[300300];
void dfs(int v, int p, int c, int c2){
    
    for(int i = 0; i < a[v].size(); i++){
        int ind = a[v][i];
        int to = e[ind].f ^ e[ind].s ^ v;
        if(to == p) continue;
        c = (c+1) % m;
        if(c2 == c)
            c = (c+1) % m;
        ans[to] = c;
        dfs(to, v, c, ans[v]);
    }
}
void solve(){
    cin >> n;
    for(int i=1; i < n; i++) {
        cin >> e[i].f >> e[i].s;
        a[e[i].f].pb(i);
        a[e[i].s].pb(i);
    }
    for(int i = 1; i <= n; i++) m = max(m, (int)a[i].size() + 1);
    dfs(1, 0, 0, -1);
    cout << m << "\n";
    for(int i = 1; i <= n; i++) cout << ans[i]+1 << " ";
}
int main () {
    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}