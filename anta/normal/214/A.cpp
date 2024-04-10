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
#if defined(_MSC_VER) || __cplusplus > 199711L
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

int main(){
    int n,m;scanf("%d%d",&n,&m);
    int c=0;
    for(int a=0;a*a<=n;a++)for(int b=0;b*b<=m;b++)if(a*a+b==n&&a+b*b==m)c++;
    printf("%d\n",c);
    return 0;
}