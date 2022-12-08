#include<bits/stdc++.h>

#define maxn 1234567
#define M 998244353

using namespace :: std;
typedef long long ll;
ll c[maxn],n,ans,k,d,fc[maxn],fi[maxn],s,g,C[maxn],p[maxn];

ll pow_(ll x,ll y){
    ll rt=1;
    while (y){
        if (y&1)
           rt=rt*x%M;
        x=x*x%M;
        y>>=1;
    }
    return rt;
}

int main(){
    cin >> n;
    fc[0]=fi[0]=p[0]=1;
    for (int i=1;i<=n;i++) 
        p[i]=p[i-1]*3%M,fc[i]=fc[i-1]*i%M,fi[i]=pow_(fc[i],M-2); g=1;
    for (int i=0;i<=n;i++) C[i]=fc[n]*fi[i]%M*fi[n-i]%M;
    ans=(pow_(p[n],n)-pow_((p[n]-3+M)%M,n))*2%M;
    for (int i=1;i<=n;i++){
        g=-g;
        (s+=g*C[i]*pow_(p[n-i]-1,n))%=M;
        (s-=g*C[i]*pow_(p[n-i],n))%=M;
    }
    s=s*3%M;
    ans=(ans-s)%M;
    cout << (ans+M)%M << endl;
}