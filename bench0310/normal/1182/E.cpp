#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<vector<ll>> mat;

mat zero(int D)
{
    return mat(D,vector<ll>(D,0));
}

mat id(int D)
{
    mat a=zero(D);
    for(int i=0;i<D;i++) a[i][i]=1;
    return a;
}

mat mul(const mat &a,const mat &b,ll mod)
{
    int D=a.size();
    mat c=zero(D);
    for(int i=0;i<D;i++) for(int j=0;j<D;j++) for(int k=0;k<D;k++) c[i][k]=(c[i][k]+a[i][j]*b[j][k])%mod;
    return c;
}

vector<ll> mul(const mat &a,vector<ll> b,ll mod)
{
    int D=a.size();
    vector<ll> c(D,0);
    for(int i=0;i<D;i++) for(int j=0;j<D;j++) c[i]=(c[i]+a[i][j]*b[j])%mod;
    return c;
}

mat fpow(mat b,ll e,ll mod)
{
    int D=b.size();
    mat res=id(D);
    while(e)
    {
        if(e&1) res=mul(res,b,mod);
        b=mul(b,b,mod);
        e/=2;
    }
    return res;
}

ll fpow(ll b,ll e,ll mod)
{
    ll res=1;
    while(e)
    {
        if(e&1) res=(res*b)%mod;
        b=(b*b)%mod;
        e/=2;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const ll mod=1000000007;
    ll n,one,two,three,c;
    cin >> n >> one >> two >> three >> c;
    mat m=zero(5);
    m[0]={3,-2+(mod-1),0,-1+(mod-1),1};
    for(int i=1;i<5;i++) m[i][i-1]=1;
    vector<ll> p={6,2,0,0,0};
    ll x;
    if(n<=5) x=p[5-n];
    else x=mul(fpow(m,n-5,mod-1),p,mod-1)[0];
    ll res=fpow(c,x,mod);
    m=zero(3);
    m[0]={1,1,1};
    for(int i=1;i<3;i++) m[i][i-1]=1;
    mat pw=fpow(m,n-3,mod-1);
    res=(res*fpow(one,mul(pw,{0,0,1},mod-1)[0],mod))%mod;
    res=(res*fpow(two,mul(pw,{0,1,0},mod-1)[0],mod))%mod;
    res=(res*fpow(three,mul(pw,{1,0,0},mod-1)[0],mod))%mod;
    cout << res << "\n";
    return 0;
}