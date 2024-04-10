#include<bits/stdc++.h>
using namespace std ;

#define ll long long 
#define pb push_back
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define memf(a) memset(a,false,sizeof(a))
#define all(v) v.begin(),v.end()
#define sz(a) (ll)a.size()
#define F first
#define S second
#define INF 2000000000000000000
#define endl "\n"
#define _time_ 1.0 * clock() / CLOCKS_PER_SEC
#define popcount(x) __builtin_popcountll(x)
#define pll pair<ll,ll> 
#define ld long double

const int M=1000000007;
const int MM=998244353;
const long double PI = acos(-1);

ll power(ll b,ll e,ll m)
{
    if(e==0) return 1;
    if(e&1) return b*power(b*b%m,e/2,m)%m;
    return power(b*b%m,e/2,m);
}
ll power( ll b, ll e)
{
    if(e==0) return 1;
    if(e&1) return b*power(b*b,e/2);
    return power(b*b,e/2);
}
template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }
template<typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p)
{ 
    return os<<'('<<p.F<< ","<<p.S<<')'; 
}

struct node
{
    int x,y,w;
    node(int w_,int x_,int y_):w(w_),x(x_),y(y_){}
};

const int N = 1502;
vector<ll> v[N];
int a[N][N];
int p[N],r[N];
int mx[N];
vector<int> el[N];


const int mod = 998244353;
const int root = 565042129;
const int inv_root = 950391366;
const int root_pw = 1<<20 ;
void fft(vector<ll> &a,bool invert)
{
    int n = sz(a);
    for(int i=1,j=0 ; i<n ;++i)
    {
        int bit=n>>1;
        for(;j>=bit;bit>>=1)
            j-=bit;
        j+=bit;
        if(i<j)
            swap(a[i],a[j]);
    }
    for(int len=2;len<=n;len<<=1)
    {
        ll w_len=invert?inv_root:root;
        for(int i=len;i<root_pw;i<<=1)
            w_len=(w_len*w_len)%mod;
        // 2**20 root ko use karke koi bhi 2**i (i<20)root nikala jaa sakta hai bas power
        // raise karke aur yahi kia hai yaha
        // aadhe root power karke aa jaenge baaki unke negative hote hai just .. its that easy bro
        for(int i=0;i<n;i+=len)
        {
            ll w=1;
            for(int j=0;j<len/2;++j)
            {
                ll u=a[i+j],v=a[i+j+len/2]*w%mod;
                a[i+j]=u+v<mod?u+v:u+v-mod;
                a[i+j+len/2]=u-v<0?u-v+mod:u-v;
                w*=w_len;
                w%=mod;
            }
        }
    }
    if(invert){
        ll inv_n=power(n,mod-2,mod);
        for(int i=0;i<n;++i)
        {
            a[i]*=inv_n;a[i]%=mod;
        }
    }
}
void multiply(const vector<ll> &a,const vector<ll> &b,vector<ll> &res)
{
    vector<ll> fa(all(a)),fb(all(b));
    int x=max((int)a.size(),(int)b.size());
    int n=x;
    fa.resize(n),fb.resize(n);
    fft(fa,false);fft(fb,false);
    for(int i=0;i<n;++i)
    {
        fa[i]*=fb[i];
        fa[i]%=mod;
    }
    fft(fa,true);
    res.resize(n);
    for(int i=0;i<n;++i)
        res[i]=fa[i];
}
int parent(int i)
{
    return p[i] = (p[i]==i)?p[i]:parent(p[i]);
}
int cnt = 0;

void merge(int x,int y,int w)
{
    x = parent(x),y = parent(y);
    if(x==y)
    {
        if(mx[x] == w)
        {
            ++v[y][1];
            v[y][1] %= mod;
        }
        return ;
    }
    if(r[x]>r[y])
        swap(x,y);
    if(r[x]==r[y])
        ++r[y];
    amax(mx[y],mx[x]);
    for(auto &j:el[x])
    {
        for(auto &k:el[y])
            amax(mx[y],a[j][k]);
    }
    ++cnt;
    multiply(v[x],v[y],v[y]);
    for(auto &j:el[x])
        el[y].pb(j);
    el[x].clear();
    p[x] = y;
    if(mx[y] == w)
    {
        ++v[y][1];
        v[y][1] %= mod;
    }
}

int _runtimeTerror_()
{
    int n;
    cin>>n;
    int m=1;
    while(m<n+1)
        m<<=1;
    for(int i=1;i<=n;++i)
    {
        el[i].pb(i);
        v[i].resize(m);
        mx[i] = 0;
        p[i] = i,r[i] = 0;
        v[i][1] = 1;
    }
    vector<node> ed;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            int x;
            cin>>x;
            a[i][j] = x;
            ed.pb(node(x,i,j));
        }
    }
    sort(all(ed),[&](node a,node b)
    {
        return a.w<b.w;
    });
    for(auto &j:ed)
    {
        if(j.x<j.y)
            merge(j.x,j.y,j.w);
    }
    int u = parent(1);
    for(int i=1;i<=n;++i)
        cout<<v[u][i]<<" ";
    cout<<"\n";
    assert(cnt<=n);
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef runSieve
        sieve();
    #endif
    #ifdef NCR
        initialize();
    #endif
    int TESTS=1;
    //cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}