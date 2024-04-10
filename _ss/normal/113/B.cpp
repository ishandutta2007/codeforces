#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define i128 __int128
#define u32 uint32_t
#define u64 uint64_t
#define u128 unsigned __int128
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(),vr.end()
#define vi vector<int>
#define vll vector<ll>
namespace myrand
{
    mt19937 mt(chrono::system_clock::now().time_since_epoch() / chrono::microseconds(1));
    ll Int(ll l,ll r) {return uniform_int_distribution<ll> (l,r)(mt);}
}

using namespace myrand;
const int N=2e3+10;
const u64 Hmod=(1ull<<61)-1,Hbase=Int(N,Hmod-1);

u64 modmul(u64 x,u64 y)
{
#if defined(__LP64__) || defined(_WIN64)
    u128 res=(u128)x*y+1;
    res=(res&Hmod)+(res>>61);
    res=(res&Hmod)+(res>>61);
    return res-1;
#else
    u64 lx=(u32)x,hx=x>>32,ly=(u32)y,hy=y>>32;
    u64 l=lx*ly,m=lx*hy+ly*hx,h=hx*hy;
    u64 res=(l&Hmod)+(l>>61)+((m<<35)>>3)+(m>>29)+(h<<3)+1;
    res=(res&Hmod)+(res>>61);
    res=(res&Hmod)+(res>>61);
    return res-1;
#endif
}

u64 modplus(u64 x,u64 y)
{
    x+=y;
    while (x>=Hmod) x-=Hmod;
    return x;
}

u64 Hnxt(u64 x,char c)
{
    return modplus(modmul(x,Hbase),c);
}

u64 pb[N];

void precal(int x)
{
    pb[0]=1;
    for (int i=1;i<=x;i++) pb[i]=modmul(pb[i-1],Hbase);
}

void build(char S[],u64 H[],int len)
{
    H[0]=0;
    for (int i=1;i<=len;i++) H[i]=Hnxt(H[i-1],S[i]);
}

u64 get_hash(u64 H[],int l,int r)
{
    return modplus(H[r]-modmul(H[l-1],pb[r-l+1]),Hmod);
}

u64 cal_hash(char S[],int len)
{
    u64 res=0;
    for (int i=1;i<=len;i++) res=modplus(modmul(res,Hbase),S[i]);
    return res;
}

char A[N],be[N],en[N];
int n;
u64 HA[N];
int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>(A+1)>>(be+1)>>(en+1);
    n=strlen(A+1);
    precal(n);
    build(A,HA,n);
    int len1=strlen(be+1),len2=strlen(en+1);
    u64 val1=cal_hash(be,len1);
    u64 val2=cal_hash(en,len2);
    int minlen=max(len1,len2);
    unordered_set<ll> st;
    st.reserve(1<<22);
    st.max_load_factor(0.25);
    for (int i=1;i<=n;i++)
        for (int j=i+minlen-1;j<=n;j++)
            if (get_hash(HA,i,i+len1-1)==val1 && get_hash(HA,j-len2+1,j)==val2) st.insert(get_hash(HA,i,j));
    cout<<st.size();
    return 0;
}