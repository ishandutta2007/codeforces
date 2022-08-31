#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
using namespace std;
ll INF = 1e18;
 
#define dif(x,y) sqrt((x)*(x)+(y)*(y))
ld pi = acos(-1);

int main(){
    ld x[2],y[2],d[2],r[2],p[2],a,b,ans;
    for(int i=0;i<2;++i) cin>>x[i]>>y[i]>>r[i];
    a = dif(x[1]-x[0],y[1]-y[0]); ans = 0;
    if(a >= r[0]+r[1]) ans = 0;
    else if(a<=abs(r[0]-r[1])){
        if(r[0]<r[1]) b = r[0];
        else b = r[1];
        ans = pi*b*b;
    }
    else{
        b=(r[0]*r[0]-r[1]*r[1])/a;
        d[0]=(a+b)/2;d[1]=(a-b)/2;
        for(int i=0;i<2;++i){
            p[i] = acos(d[i]/r[i])*2;
            ans += (p[i]-sin(p[i]))*r[i]*r[i]/2;
        }
    }
 
    cout<<setprecision(10)<<ans<<endl;
    return 0;
}