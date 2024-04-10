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
    vi x(n);
    rep(i,n)scanf("%d",&x[i]);
    int m;
    scanf("%d",&m);
    vi y(m);
    rep(i,m)scanf("%d",&y[i]);
    int k;
    scanf("%d",&k);
    vi z(k);
    rep(i,k)scanf("%d",&z[i]);
    int A, B;
    scanf("%d%d",&A,&B);
    //x: r1, y: p1, z: p2
    sort(all(x), greater<int>());
    sort(all(z));
    double w = 0.0;
    double AB = (double)A / B;
    rep(i, m) {
        double t = (sqrt((double)y[i])*x[0]) / sqrt((double)y[i] + z[0] * AB);
        w = max(w, t);
    }
    printf("%.10f\n", w);
    /*
        ((r1^2*pi-r2^2*pi)*p1)/(r2^2*pi*p2) = A/B
        OK: ((3^2*pi-2.683281573000^2*pi)*2) / (2.683281573000^2*pi*1) = 1/2
        r2 = (sqrt(p1)*r1) / sqrt(p1 + p2*x)
        
    */
    return 0;
}