#define _GLIBCXX_DEBUG
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <numeric>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <functional>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);(i)++)
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);(i)++)
#if defined(_MSC_VER)
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it,o.begin()); it != (o).end(); it ++)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
using namespace std;
typedef long long ll; typedef vector<int> vi; typedef pair<int,int> pii;

#define INF 0x3f3f3f3f

int main(){
    int n;
    scanf("%d",&n);
    vi a(n);
    rep(i,n)scanf("%d",&a[i]);
    int m;
    scanf("%d",&m);
    vi b(m);
    rep(i,m)scanf("%d",&b[i]);
    int t=-1,c=0;
    rep(i,n)rep(j,m){
        int x=b[j],y=a[i];
        if(x%y!=0)continue;
        int z=x/y;
        if(z>t){
            t=z;
            c=1;
        }else if(z==t) {
            c ++;
        }
    }
    printf("%d\n",c);
    return 0;
}