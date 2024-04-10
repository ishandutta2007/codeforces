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
const int N=500005;
struct Matrix
{
    ll val[2][2];
    ll n_;
    Matrix (ll n=2) : n_(n)
    {

    }
    void print()
    {
        for(ll i=0;i<n_;++i)
        {
            for(ll j=0;j<n_;++j)
                cout<<val[i][j]<<" ";
            cout<<"\n";
        }
    }
    void set(ll x)
    {
        for(ll i=0;i<n_;++i)
            for(ll j=0;j<n_;++j)
                val[i][j]=x;
    }
    Matrix operator*(const Matrix& b) const 
    {
        ll n=n_;
        Matrix ans(n);
        ans.set(0);
        for(ll i=0;i<n_;++i)
        {
            for(ll j=0;j<n_;++j)
            {
                ans.val[i][j]=0;
                for(ll k=0;k<n_;++k)
                {
                    ans.val[i][j]+=val[i][k]*b.val[k][j];
                    ans.val[i][j]%=MM;
                }

            }
        }
        return ans;
    }
};
Matrix I(ll n)
{
    Matrix Iden(n);
    Iden.set(0);
    for(ll i=0;i<n;++i)
        Iden.val[i][i]=1;
    return Iden;
}
Matrix power(Matrix m,ll pw)
{
    if(pw==0)
        return I(m.n_);
    if(pw==1)
        return m;
    Matrix t=power(m,pw/2);
    t=t*t;
    if(pw&1)
        t=t*m;
    return t;
}

string s;
Matrix get(string t)
{
    Matrix x;
    x.set(0);
    x.val[1][0]=1;
    x.val[0][0]=t[0]-'0'+1;
    if(t[0]!='1' || t[1]=='9')
        return x;
    x.val[0][1]=9-t[1]+'0';
    //x.print();
    //cout<<"Done\n";
    return x;
}


struct node
{
    Matrix p;
}fake;
    // base value is assigned to fake node
struct SEGTREE
{
    SEGTREE(){  }
    node tree[4*N];
    inline node combine(node a,node b)
    {
        node ret;
        ret.p=a.p*b.p;
        return ret;
    }
    inline node make_node(string t)
    {
        node ret;
        ret.p=get(t);
        return ret;
    }
    void buildTree(ll v,ll st,ll en)
    {
        if(st==en)
        {
            string t;
            t+=s[st];t+=s[st+1];
            tree[v]=make_node(t);
            //cout<<"st here "<<st<<"\n";
            //tree[v].p.print();
            //cout<<"---";
            return ;
        }
        ll mid=(st+en)>>1;
        buildTree(v<<1,st,mid);
        buildTree(v<<1 | 1,mid+1,en);
        tree[v]=combine(tree[v<<1],tree[v<<1 | 1]);
    }
    void update(ll v,ll st,ll en,ll in)
    {
        ll mid=(st+en)>>1;
        if(st==en)
        {
            string t;
            t+=s[st];t+=s[st+1];
            tree[v]=make_node(t);

            return ;
        }
        if(in<=mid)
            update(v<<1,st,mid,in);
        else
            update(v<<1 | 1,mid+1,en,in);
        tree[v]=combine(tree[v<<1],tree[v<<1 | 1]);
    }
    node query(ll v,ll st,ll en,ll l,ll r)
    {
        if(en<l || st>r)
            return fake;
        if(st>=l && en<=r)
            return tree[v];
        ll mid=(st+en)>>1;
        return combine(query(v<<1,st,mid,l,r),query(v<<1 | 1,mid+1,en,l,r));
    }
}seg;

int _runtimeTerror_()
{
    int n,m;
    cin>>n>>m;
    cin>>s;
    s='0'+s+'9';
    assert(sz(s)==n+2);
    fake.p=I(2);
    seg.buildTree(1,0,n);
    for(int i=0;i<m;++i)
    {
        int x,d;
        cin>>x>>d;
        s[x]=d+'0';
        seg.update(1,0,n,x);
        seg.update(1,0,n,x-1);
        //cout<<"----\n";
        Matrix ans=seg.tree[1].p;
        cout<<ans.val[0][0]<<"\n";
        //ans.print();
        //cout<<"----\n";
    }
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