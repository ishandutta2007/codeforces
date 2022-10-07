#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <cstring>
#include <cassert>
#include <ctime>


using namespace std;
#define forn(i, n) for(int i = 0; i < n; i++)
#define forab(i, a, b) for(int i = a; i < b; i++)
#define pb push_back
#define mp make_pair
#define ss second 
#define ff first 

typedef long long ll;
typedef vector < int > vi;

const int maxn = 1e5 + 10;
const int inf = 2e9 + 10;

vi a[maxn];
vi b[maxn];
vi c[maxn];
vi fr[maxn];

int dist[maxn];
set < pair < int, int > > q;



int main(){
   // freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    int n, m, v, u, t, k, d, ans, len, cnt;
    cin >> n >> m;
    forn(i, m){
        scanf("%d %d %d", &v, &u, &t); v--; u--;
        a[v].pb(u);
        b[v].pb(t);
        a[u].pb(v);
        b[u].pb(t);
    }
    forn(i, n){
        scanf("%d", &cnt);
        c[i].resize(cnt + 1);
        forn(j, cnt)
            scanf("%d", &c[i][j]);
        c[i][cnt++] = inf;        
        fr[i].resize(cnt);
        d = inf;
        for(int j = cnt - 1; j >= 0; j--){
            if (j == cnt - 1 || c[i][j + 1] - 1 != c[i][j])
    d = c[i][j] + 1;
            fr[i][j] = d;
        }
        
    }   
    int z = 0;
    if (c[0][0] == 0)
        z = fr[0][0];
   // cerr << z << endl;
    q.insert(mp(z, 0));    
    //memset(dist, 63, sizeof(dist));
    forn(i, n)
        dist[i] = inf;
    ans = inf;
    dist[0] = z;
   
    while(!q.empty()){
       // cerr << "w\n";
        v = q.begin()->ss;
        q.erase(q.begin());
        len = a[v].size();
    //   cerr << "len " << len << endl;
        forn(i, len){
            u = a[v][i];
            t = dist[v] + b[v][i];
            k = lower_bound(c[u].begin(), c[u].end(), t) - c[u].begin();
      //     cerr << "v u: " << v << u << endl;
        //   cerr << "k " << k << endl;
         // cerr << "t " << dist[0] << endl;
           if (u == n - 1){
    ans = min(ans, t);
            }
           if (c[u][k] == t)
    t = fr[u][k];
     //      return 0;
       
           if (dist[u] > t){
    q.erase(mp(dist[u], u));
        dist[u] = t;
    q.insert(mp(dist[u], u));   
           
            }
        }
        
    }
    if (ans == inf)
        cout << -1;
    else
        cout << ans;
    
    
       
   
    return 0;
}