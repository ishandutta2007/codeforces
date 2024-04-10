#include <iostream>
#include <vector>
#include <algorithm>

#define long long long
#define M 10

using namespace std;

long n,p[M],ans=10000000000000ll,f[M];
long a[M],x[M];
bool u[M];
vector<long> d[M];

bool next(void){
    int j=n;
    while (j>0 && p[j]==j-1)
    p[j--]=0;
    if (j==0)
    return 0;
    p[j]++;
    return 1;
}

bool tri(void){
    for (int i=1; i<=n; ++i)
    if (p[i]>0 && a[p[i]]<=a[i])
    return 0;
    return 1;
}

int dv(long x, long i){
    long y=0;
    for (long j=0; j<(int)d[i].size(); ++j)
    while (x%d[i][j]==0){
        x/=d[i][j];
        y++;
    }
    return y;
}

void pre(void){
    for (int i=1; i<=n; ++i){
        long x=a[i];
        for (long j=2; j*j<=x; ++j)
        if (x%j==0){
            while (x%j==0){
                f[i]++;
                x/=j;
            }
            d[i].push_back(j);
        }
        
        if (x>1)
        f[i]++,
        d[i].push_back(x);
    }
    
    for (int i=1; i<=n; ++i)
    if (f[i]==1)
    f[i]=0;
    
}

void con(void){
    for (int i=1; i<=n; ++i)
    x[i]=a[i],u[i]=0;
    
    long v=n;
    int zero=0;
    
    for (int i=1; i<=n; ++i)
    if (p[i]>0){
        u[p[i]]=1;
        if (x[p[i]]%a[i]!=0)
        return;
        x[p[i]]/=a[i];
    }
    else
    zero++;
    
    for (int i=1; i<=n; ++i)
    if (!u[i])
    v+=f[i];
    else
    v+=dv(x[i],i);
    
    if (zero>1)
    v++;
    
    ans=min(ans,v);
}

int main()
{
    cin>>n;
    for (int i=1; i<=n; ++i)
    cin>>a[i];
    
    sort(a+1,a+(n+1));
    reverse(a+1,a+(n+1));
    
    
    pre();
    
    con();
    
    while (next())
    con();
    
    cout<<ans<<"\n";
    
    return 0;
}