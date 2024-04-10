#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define FILL(i,n) memset(i,n,sizeof i)
#define X first
#define Y second
#define ET cout << "\n"
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(),v.end()
#define pb push_back
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#ifdef bbq
#define debug(...) {\
    fprintf(stderr,"%s - %d (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
    _do(__VA_ARGS__);\
}
#define DB(a,s,e) {for(int _i=s;_i<e;++_i) cerr << a[_i] << " ";cerr << "\n";}
template<typename T>void _do(T &&x){cerr<<x<<endl;}
template<typename T,typename ...S> void _do(T &&x,S &&...t){cerr<<x<<", ";_do(t...);}
template<typename a,typename b> ostream& operator << (ostream &s,const pair<a,b> &p){return s<<"("<<p.X<<","<<p.Y<<")";}
#else
#define debug(...)
#define DB(a,s,e)
#endif

const ll MOD=998244353;

struct matrix
{
    int n,m;
    ll M[2][2];
    matrix(int _n=0,int _m=0):n(_n),m(_m){
        for(int i=0;i<_n;++i)
            for(int j=0;j<_m;++j)
                M[i][j]=0;
    }
    matrix operator*(const matrix &x)const{
        matrix rt(n,x.m);
        for(int i=0;i<rt.n;++i)
            for(int j=0;j<rt.m;++j)
                for(int k=0;k<m;++k)
                    rt.M[i][j]=(rt.M[i][j]+M[i][k]*x.M[k][j])%MOD;
        return rt;
    }
    void print()
    {
        for(int i=0;i<n;++i)
            for(int j=0;j<m;++j)
                cout << M[i][j] << " \n"[j+1==m];
    }
}base(1,2);

ll f[]={1,2,3,4,5,6,7,8,9,10};
ll f2[]={9,8,7,6,5,4,3,2,1,0};

string s;
matrix seg[2000000];

void modify(ll x,ll l,ll r,ll rt)
{
    if(l==r)
    {
        seg[rt]=matrix(2,2);
        seg[rt].M[0][0]=f[s[l-1]-'0'];
        seg[rt].M[0][1]=1;
        if(l>1&&s[l-1]=='1')
            seg[rt].M[1][0]=f2[s[l-2]-'0'];
        else
            seg[rt].M[1][0]=0;
        return;
    }
    int m=(l+r)>>1;
    if(x<=m) modify(x,l,m,rt<<1);
    else modify(x,m+1,r,rt<<1|1);
    seg[rt]=seg[rt<<1]*seg[rt<<1|1];
}

int main()
{
    IOS();
    int n,m,x,d;
    cin >> n >> m >> s;
    reverse(ALL(s));
    base.M[0][0]=1;
    for(int i=0;i<n;++i)
        modify(i+1,1,n,1);
    while(m--)
    {
        cin >> x >> d,s[n-x]=d+'0';
        modify(n-x+1,1,n,1);
        if(n-x+2<=n)
            modify(n-x+2,1,n,1);
        auto ans=base*seg[1];
        cout << ans.M[0][0] << "\n";
    }
}