#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#ifdef __GNUC__
#define aut(v, x) __typeof(x) v = (x)
#else
#define aut(v, x) auto v = (x)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
using namespace std;
typedef long long ll; typedef vector<ll> vl; typedef pair<ll,ll> pll; typedef vector<pll> vpll; typedef vector<string> vs;
const int INF = 0x3f3f3f3f; const ll INFL = 0x3f3f3f3f3f3f3f3fLL;

int g[111][111];
int main() {
    int k;
    cin>>k;
    srand(clock());
//  rer(n, 1, 100) {
    int n = 100;
        ll x = 0;
        mset(g, 0);
        rep(ttt, 1000000) {
            int t = rand()%n, u = rand()%n;
            if(t == u) continue;
            if(!g[t][u] && x < k) {
                rep(i, n) if(g[t][i] && g[i][u]) x ++;
                g[t][u] = g[u][t] = 1;
            }else if(g[t][u] && x > k){
                rep(i, n) if(g[t][i] && g[i][u]) x --;
                g[t][u] = g[u][t] = 0;
            }
//          cout<<x<<endl;
            if(x == k) {
                cout << n << endl;
                rep(i, n) {
                    rep(j, n) cout << "01"[g[i][j]];
                    cout << endl;
                }
                return 0;
            }
        }
//  }
    return 0;
}