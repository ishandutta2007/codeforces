#include <iostream>
#include <cstdlib>

#define K 18
#define M 36
#define N 140147
#define long long long

using namespace std;

long p[M];
int n,a[M][M],x,s[2][2][2][M][M];

void read(void){
    cin>>n;
    for (int i=1; i<=n; ++i)
    for (int j=1; j<=n; ++j)
    cin>>a[i][j];
    x=(n+1)/2;
}

void pre(void){
    p[0]=1;
    for (int i=1; i<M; ++i)
    p[i]=2*p[i-1];
    
    for (int i=1; i<x; ++i)
    for (int j=1; j<x; ++j)
    for (int xi=0; xi<2; ++xi)
    for (int xj=0; xj<2; ++xj)
    for (int m=0; m<2; ++m){
        int yi=xi==1 ? -1:1;
        int yj=xj==1 ? -1:1;
        int h= m==1  ? -1:1;
        s[xi][xj][m][i][j]=abs(a[i][j]+yi*a[i+x][j]+yj*a[i][j+x]+h*yi*yj*a[i+x][j+x]);
    }
}

void kill(void){
    int ans=0;
    for (int i=1; i<=n; ++i)
    for (int j=1; j<=n; ++j)
    ans+=a[i][j];
    
    
    for (long i=0; i<p[x]; ++i){
        int sum=0;
        long y=0;
        
        for (int j=0; j<x; ++j)
        if (p[j]&i)
        y^=(p[j+x]-p[j]);
        
        y<<=1;
        
        for (int j=1; j<=n; ++j)
        if (p[j]&y)
        sum-=a[x][j];
        else
        sum+=a[x][j];
        
        int ma= (y&p[x])==p[x] ? 1:0;
        
        for (int j=1; j<x; ++j){
            int e[2];
            e[0]=a[j][x]+((y&p[x])==p[x] ? -1:1)*a[j+x][x];
            e[1]=-e[0];
            
            for (int t=0; t<2; ++t)
            for (int k=1; k<x; ++k)
            if (y&p[k])
            e[t]+=s[1][t][ma][j][k];
            else
            e[t]+=s[0][t][ma][j][k];
            
            sum+=max(e[0],e[1]);
        }
        
        ans=max(ans,sum);
    }
    
    cout<<ans<<"\n";
}

int main()
{
    read();
    pre();
    kill();
    return 0;
}