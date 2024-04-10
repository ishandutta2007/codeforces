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
#include <cassert>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER)
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
using namespace std;
typedef long long ll; typedef vector<int> vi; typedef vector<ll> vl; typedef pair<ll,ll> pll; typedef vector<pll> vpll; typedef vector<string> vs; typedef pair<int,int> pii;
const int INF = 0x3f3f3f3f; const ll INFL = 0x3f3f3f3f3f3f3f3fLL;

int c[55], a[55][55];
int main() {
    int n, s = 0;
    scanf("%d",&n);
    rep(i, n) scanf("%d",&c[i]), s += c[i];
    rep(i, n) rep(j, c[i]) scanf("%d",&a[i][j]);
    vector<pair<pii,pii> > r;
    int x = 1;
    rep(i, n) rep(j, c[i]) {
        if(x == a[i][j]) ;
        else {
            int ii, jj;
            for(ii = 0; ii < n; ii ++) for(jj = 0; jj < c[ii]; jj ++) if(x == a[ii][jj]) goto bb;
bb:;
            r.pb(mp(mp(i+1,j+1),mp(ii+1,jj+1)));
            swap(a[i][j],a[ii][jj]);
        }
        x ++;
    }
    printf("%d\n",r.size());
    each(i, r) {
        printf("%d %d %d %d\n", i->first.first, i->first.second, i->second.first, i->second.second);
    }
    /*
    rep(i, n) {
        rep(j, c[i]) cerr<<a[i][j]<<",";
        cerr<<endl;
    }
    */
    return 0;
}