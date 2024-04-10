#include <iostream>

using namespace std;

#define p 1000000007ll
#define long long long

#define M 1010

long n = 0, x[M], y[M], f[M], m, d[M][M], c[M][M];

long bin(long x, long a){
    long y=1;
    while (a){
        if (a&1)
            y*=x,y%=p;
        x*=x,x%=p;
        a>>=1;
    }
    return y;
}

void pre(void){
    f[0]=1;
    for (int i=1; i<M; ++i)
        f[i]=(i*f[i-1])%p;
    
    for (int i = 0; i < M; ++i)
    c[i][0]=1;
    for (int i=1; i<M ; ++i)
    for (int j=1; j<=i; ++j){
        c[i][j]=c[i-1][j-1]+c[i-1][j];
        if (c[i][j]>=p)
        c[i][j]-=p;
    }
}

void read(void){
    cin >> m;
    for (int i = 1; i <= m ; ++i){
        cin >> x[i];
        n += x[i];
    }
    
    for (int i = 1; i <= m; ++i){
        cin >> y[i];
    }
}
    
void din(void){
    d[0][0]=1;
    for (int i = 0; i <= m; ++i)
    for (int s = 0; s <= n; ++s)
    for (int j = 0; j <= s+x[i] && j<=y[i]; ++j)
    d[i+1][s+x[i]-j]=(d[i+1][s+x[i]-j]+d[i][s]*c[s+x[i]][j])%p;
    
    long ans=d[m+1][0];
    
    ans = (ans*f[n])%p;
    
    for (int i=1; i<=n; ++i)
    ans = (ans*bin(f[x[i]],p-2))%p;
    
    cout << ans << "\n";
}

int main(){
    pre();
    read();
    din();
    return 0;
}