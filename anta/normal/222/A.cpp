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
#include <bitset>
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
typedef long long ll; typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pii> vpii;
const int INF = 0x3f3f3f3f; const ll INFL = 0x3f3f3f3f3f3f3f3fLL;

int main() {
    int n, k;
    scanf("%d%d",&n,&k);
    k--;
    vi v;
    rep(i,n){int x;scanf("%d",&x);v.pb(x);}
    int t = v[k];
    reu(i, k, n) {
        if(t != v[i]) {
            puts("-1");
            return 0;
        }
    }
    int u = 0;
    for(int i = n-1; i >= 0; i --) if(t == v[i]) u ++; else break;
    int j = 0;
    while(u != n) {
        if(v[j+k] == t) u ++;
        v.pb(v[j+k]);
        j ++;
    }
    printf("%d\n", j);
    return 0;
}