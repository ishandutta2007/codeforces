#include <bits/stdc++.h>
#define p_b push_back
#define endl "\n"
#define m_p make_pair
#define fi first
#define se second
#define pll pair <ll,ll>
using namespace std;
typedef long long ll;
template <typename T>
T sqr(T x)
{
    return x*x;
}
const ll shl=1;
const ll maxn=1000000;
vector <ll> tt[100010];
set <ll> ss;
map < string , ll > mp;
string s1;
char cc;
ll r,c,sc,n,m,i,j,a[1000000],b[1000000],v[maxn],a1,b1,c1,ans,x,k;
void vout(string s)
{
    cout << s << endl;
    exit(0);
}
multiset <ll> s;
void dfs(ll x)
{
    if(v[x])return;
    b[r]++;
    v[x]=r;
    ll i,nn=tt[x].size();
    for(i=0;i<nn;i++)dfs(tt[x][i]);
    return;
}
int main() {

    // set < ll > :: iterator kek=s.begin;
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    cin >> n;
    for(i=1;i<=n;i++)
    {
        cin >> x;
        if(i!=x){tt[i].p_b(x);tt[x].p_b(i);}
    }
    r=0;
    for(i=1;i<=n;i++)if(!v[i]){r++;dfs(i);};
    //cout << r << endl;
    for(i=1;i<=r;i++)s.insert(b[i]);
    if(s.size()>1)
    {
        multiset <ll> :: iterator it=s.end();
        --it;
        x=*it;
        multiset <ll> :: iterator it1=it;
        --it1;
        s.erase(it);
        x+=*it1;
        s.erase(it1);
        s.insert(x);
    }
    multiset <ll> :: iterator it=s.begin();
    for(;it!=s.end();++it)
    {
        x=*it;
        ans+=x*x;
    }
    cout << ans << endl;
    return 0;
}