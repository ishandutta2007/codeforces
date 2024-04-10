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
#define each(it,o) for(__typeof(o.begin()) it = o.begin; it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef long long ll; typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pii> vpii;

const int N = 5000;
int d[N],f[N];
int main() {
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    mset(d,0);
    vi r;
    f[0]=1;
    rep(i,n+m) {
        while(d[i]<k||!f[i+1]){
            r.pb(i+1);
            reu(j, i, i+n+m) if((j - i)%(n+m) < n) {
                d[j] ++;
                f[j] |= f[j-1];
            }
        }
    }
    printf("%d\n", r.size());
    rep(i,r.size()) {
        printf("%d ", r[i]);
    }
    puts("");
}