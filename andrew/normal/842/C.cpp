#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
#define fi first
#define se second
#define p_b push_back
#define m_p make_pair
#define endl "\n"
#define pll pair<ll,ll>
const ll maxn=1000000;
string ans;
map <ll,ll> mp;
set <ll> s;
vector <ll> tt[1000000];
char cc;
ll xx,stn,a[maxn],b[maxn],c,a1,b1,c1,n,r,m,x,i,j,sc,k,v[maxn];
template <typename T>
T sqr(T a)
{
    return a*a;
}
ll gcd(ll a,ll b)
{
    while(a>0 && b>0)a>b?a%=b:b%=a;
    return a+b;
}
void vout(string s)
{
    cout << s << endl;
    exit(0);
}
void dfs(ll x,ll kek)
{
    if(v[x])return;
    v[x]=1;
    stn++;
    kek=__gcd(kek,a[x]);
    if(stn==1)kek=0;
    set <ll> :: iterator it=s.begin();
    for(;it!=s.end();++it)
    {
        xx=*it;
        if(a[x]%xx==0)mp[xx]++;
    }
    b[x]=kek;
    it=s.end();
    --it;
    while(1)
    {
        if(mp[*it]>=stn-1)
        {
            b[x]=max(b[x],*it);
            break;
        }
        if(it==s.begin())break;
        --it;
    }
    ll i;
    ll nn=tt[x].size();
    for(i=0;i<nn;i++)dfs(tt[x][i],kek);
    it=s.begin();
     for(;it!=s.end();++it)
    {
        xx=*it;
        if(a[x]%xx==0)mp[xx]--;
    }
    stn--;
}
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(i=1;i<=n;i++)cin >> a[i];
    for(i=1;i<n;i++)
    {
        cin >> a1 >> b1;
        tt[a1].p_b(b1);
        tt[b1].p_b(a1);
    }
    for(i=1;i<=a[1];i++)if(a[1]%i==0)s.insert(i);
    dfs(1,0);
    for(i=1;i<=n;i++)cout << b[i] << " ";
    cout << endl;
    return 0;
}