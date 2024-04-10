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

int a[1010][1010];
int ri[1010];
int ci[1010];
int main() {
    int n, m, k;
    scanf("%d%d%d",&n,&m,&k);
    rep(i,n)rep(j,m)scanf("%d",&a[i][j]);
    rep(i,n)ri[i]=i;
    rep(i,m)ci[i]=i;
    char c; int x,y;
    while(cin>>c>>y>>x) {
        x--;y--;
        if(c=='c'){
            swap(ci[x],ci[y]);
        }else if(c=='r'){
            swap(ri[x],ri[y]);
        }else {
            printf("%d\n",a[ri[y]][ci[x]]);
        }
    }
    return 0;
}