#include <iostream>

#define L 3033
#define N 111
#define p 1000000007
#define long long long

using namespace std;

long n,l,a[N],b[N],f[L][N],s[L][N];

void read(void){
    cin>>n>>l;
    for (long i=0; i<n; ++i)
    cin>>a[i]>>b[i];
    for (long i=0; i<n; ++i){
        if (a[i]!=b[i])
        f[0][i]=1;
        s[0][i]=1;
    }
    for (long i=1; i<=l; ++i)
    for (long j=0; j<n; ++j){
        f[i][j]=0;
        s[i][j]=0;
        for (long k=0; k<n; ++k)
        if (k!=j){
            if (a[k]==a[j] && i>=b[k])
            f[i][j]+=s[i-b[k]][k];
            if (b[k]==a[j] && i>=a[k] && a[k]!=b[k])
            f[i][j]+=f[i-a[k]][k];
            f[i][j]%=p;
            if (a[k]==b[j] && i>=b[k])
            s[i][j]+=s[i-b[k]][k];
            if (b[k]==b[j] && i>=a[k] && a[k]!=b[k])
            s[i][j]+=f[i-a[k]][k];
            s[i][j]%=p;
        }
        if (a[j]==b[j])
        f[i][j]=0;
    }
}

int main()
{
    long sum=0;
    read();
    for (long k=0; k<n; ++k){
        if (l>=b[k])
        sum+=s[l-b[k]][k];
        if (l>=a[k])
        sum+=f[l-a[k]][k];
        sum%=p;
    }
    cout<<sum;
    return 0;
}