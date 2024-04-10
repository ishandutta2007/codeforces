#include<bits/stdc++.h>

using namespace std;
#define ll long long
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
const int N=1e5+10;
const ll mod=1e9+7;
ll base,pw2[N*20],ipw2[N*20],pb[N*20];
int n,q,len_s0,m=0,len_S[N*20];
char T[N*20],S[22][N*20];
vll h[30];

void read()
{
    cin>>n>>q;
    cin>>(S[0]+1)>>(T+1);
    len_S[0]=strlen(S[0]+1);
}

ll bit[30][N*2];

void add(int l,int pos,ll val)
{
    for (int i=pos;i<=n;i+=(i&-i)) bit[l][i]=(bit[l][i]+val)%mod;
}

ll get(int l,int pos)
{
    ll res=0;
    for (int i=pos;i;i-=(i&-i)) res=(res+bit[l][i])%mod;
    return res;
}

void build()
{
    pw2[0]=ipw2[0]=1;
    ipw2[1]=(mod+1)/2;
    for (int i=1;i<=n;i++) pw2[i]=pw2[i-1]*2%mod,ipw2[i]=ipw2[i-1]*ipw2[1]%mod,T[i]-='a'-1;
    for (int i=1;i<=len_S[0];i++) S[0][i]-='a'-1;
    for (int i=1;i<=n;i++) add(T[i],i,pw2[n-i]);
    while (m<n && len_S[m]<=1e6)
    {
        for (int i=1;i<=len_S[m];i++) S[m+1][++len_S[m+1]]=S[m][i];
        S[m+1][++len_S[m+1]]=T[m+1];
        for (int i=1;i<=len_S[m];i++) S[m+1][++len_S[m+1]]=S[m][i];
        m++;
    }
    for (int i=0;i<=m;i++)
    {
        int len=len_S[i];
        h[i].resize(len+5,0);
        for (int j=1;j<=len;j++) h[i][j]=(h[i][j-1]*base+S[i][j])%mod;
    }
    pb[0]=1;
    for (int i=1;i<=len_S[m];i++) pb[i]=pb[i-1]*base%mod;
}

ll get_hash(int l,int r,vll &ha)
{
    return (ha[r]-ha[l-1]*pb[r-l+1]+mod*mod)%mod;
}

ll C[30];

ll solve(char s[],int len,int k)
{
    int d=0;
    while (d<k && len_S[d]<len) d++;
    if (len_S[d]<len) return 0;
    vll hs(len+5,0);
    for (int i=1;i<=len;i++) hs[i]=(hs[i-1]*base+s[i])%mod;
    int cnt=0;
    int len_d=len_S[d];
    for (int i=1;i<=len_d-len+1;i++)
        if (get_hash(i,i+len-1,h[d])==get_hash(1,len,hs)) cnt++;
    for (int i=1;i<=26;i++) C[i]=0;
    for (int i=1;i<=len;i++)
        if (get_hash(len_d-(i-1)+1,len_d,h[d])==get_hash(1,i-1,hs) && get_hash(1,len-i,h[d])==get_hash(i+1,len,hs)) C[s[i]]++;
    ll res=pw2[k-d]*cnt%mod;
    for (int i=1;i<=26;i++)
    {
        ll val=(get(i,k)-get(i,d)+mod)%mod*ipw2[n-k]%mod;
        res=(res+val*C[i])%mod;
    }
    return res;
}

char ST[N*20];

void process()
{
    build();
    for (int i=1,k,len;i<=q;i++)
    {
        cin>>k>>(ST+1);
        len=strlen(ST+1);
        for (int i=1;i<=len;i++) ST[i]-='a'-1;
        cout<<solve(ST,len,k)<<"\n";
    }
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    base=Int(1e8,5e8);
    read();
    process();
    return 0;
}