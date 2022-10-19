#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define M 507
#define long long long
#define p 1000000007ll

int n,k;
long d[M][M],h[M][M],t[M];

void pre(void){
    t[0]=1;
    for (int i=1; i<M; ++i)
    t[i]=(2*t[i-1])%p;
}

void din(void){
    d[0][0]=1;
    for (int i=1; i<=n; ++i){
        for (int x=0; x<=min(k,i); ++x) 
        for (int y=0; y<=i; ++y){
            int a=i-y;
            int b=y;
            h[x][y]+=t[b]*d[x][y];
            h[x+1][i]+=(t[a+b]-t[b])*d[x][y];
            
            h[x][y]%=p;
            h[x+1][i]%=p;
        }
        
        for (int x=0; x<=min(k,i); ++x)
        for (int y=0; y<=i; ++y)
        d[x][y]=h[x][y],h[x][y]=0;
    }
    
    long ans=0;
    for (int y=0; y<M; ++y)
    ans=(ans+d[k][y])%p;
    if (ans<0)
    ans+=p;
    
    cout<<ans<<"\n";
    
}
    

int main()
{
#ifdef TROLL
    freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
#else
    ios_base::sync_with_stdio(0);
#endif

    cin>>n>>k;
    
    pre();
    
    din();
    
    return 0;
}