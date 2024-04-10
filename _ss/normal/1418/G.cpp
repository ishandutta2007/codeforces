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
    ll Int(ll l,ll r) { return uniform_int_distribution<ll> (l,r)(mt);}
}

using namespace myrand;
const int N=5e5+10,base=3,mb=36,C=10,base2=729;
const ll inf=1e17;

int xor3_int(int a,int b)
{
    int res=0,pw=1;
    while (a || b)
    {
        int t=a%base+b%base;
        if (t>=base) t-=base;
        res+=pw*t;
        a/=base;
        b/=base;
        pw*=base;
    }
    return res;
}

int res_xor3[base2][base2];

void precal()
{
    for (int i=0;i<base2;i++)
        for (int j=0;j<base2;j++) res_xor3[i][j]=xor3_int(i,j);
}

ll xor3_ll(ll a,ll b)
{
    ll res=0,pw=1;
    while (a || b)
    {
        int t=res_xor3[a%base2][b%base2];
        res+=pw*t;
        a/=base2;
        b/=base2;
        pw*=base2;
    }
    return res;
}

int n,a[N];
ll val[N][C];

void read()
{
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
}

/*struct HASH{
    size_t operator()(const vll&vt)const
    {
        ll res=0;
        for (ll x : vt) res ^= (x>>32);
        return hash<ll>()(res);
    }
};*/

//unordered_map<vll,int,HASH> cnt;
map<vll,int> cnt;

int cnt_num[N];
vll ps[N];

void process()
{
    for (int i=0;i<C;i++)
        for (int j=1;j<=n;j++) val[j][i]=Int(1,inf);
    ps[0].resize(C,0);
    for (int i=1;i<=n;i++)
    {
        ps[i].resize(C);
        for (int j=0;j<C;j++) ps[i][j]=xor3_ll(ps[i-1][j],val[a[i]][j]);
    }
    cnt[ps[0]]++;
    ll res=0;
    for (int i=1,j=0;i<=n;i++)
    {
        int v=a[i];
        cnt_num[v]++;
        while (cnt_num[v]>3)
        {
            cnt[ps[j]]--;
            j++;
            cnt_num[a[j]]--;
        }
        res+=cnt[ps[i]];
        cnt[ps[i]]++;
    }
    cout<<res;
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    precal();
    read();
    process();
    return 0;
}