#include <iostream>

#define M 2013
#define long long long
#define p 1000000007ll

using namespace std;

long d[M][M],n,a[M];
bool u[M],b[M];

void pre(void){
    d[0][0]=1;
    
    for (int i=1; i<M; ++i)
    d[i][0]=(d[i-1][0]*i)%p;
    
    
    for (int s=1; s<M+M; ++s)
    for (int i=0; i<s && i<M; ++i)
    if (s-i<M){
        int j=s-i;
        d[i][j]=0;
        if (i>=1)
        d[i][j]=(d[i][j]+d[i][j-1]*i)%p;
        if (j>=2)
        d[i][j]=(d[i][j]+d[i+1][j-2]*(j-1))%p;
    }
}

void read(void){
    cin>>n;
    int s=0;
    for (int i=1; i<=n; ++i){
        cin>>a[i];
        if (a[i]>0)
        u[a[i]]=1;
        else
        b[i]=1,s++;
    }
    int x=0;
    for (int i=1; i<=n; ++i)
    if (!u[i] && b[i])
    x++;
    cout<<d[s-x][x]<<"\n";
}

int main(){
    pre();
    read();
    return 0;
}