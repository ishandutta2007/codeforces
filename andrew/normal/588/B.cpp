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
const ll MAXN=1123456;
vector <ll> tt[1000];
set <ll> s;
multiset <ll> s2;
map < string , ll > mp;
string s1,s3;
char cc;
ll c,sc,n,m,i,j,a[MAXN],b[MAXN],a1,b1,c1,ans,x,k;
template <typename T>
void vout(T s)
{
    cout << s << endl;
    exit(0);
}
bool check(ll x)
{
    s2.clear();
    while(x>1)
    {
        ll i,k=sqrt(x),fl=0;
        for(i=2;i<=k;i++)if(x%i==0){fl=i;break;}
        if(fl==0)
        {
            s2.insert(x);
            break;
        }
        s2.insert(fl);
        x/=fl;
    }
    while(!s2.empty())
    {
        multiset <ll> :: iterator it=s2.begin();
        x=*it;
        s2.erase(it);
        if(s2.find(x)!=s2.end() && x!=1)return 1;
    }
    return 0;
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    cin >> n;
   k=sqrt(n);
   for(i=1;i<=k;i++)if(n%i==0)
   {
       s.insert(i);
       s.insert(n/i);
   }
   set <ll> :: iterator it=s.begin();
   for(;it!=s.end();++it)if(!check(*it))ans=max(ans,*it);
   cout << ans << endl;
    return 0;
}