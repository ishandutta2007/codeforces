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
string s1;
set <ll> s;
map <ll,ll> mp;
ll l,r,a[maxn],b[maxn],c,a1,b1,c1,n,m,x,i,j,sc,ans=1e18,k;
template <typename T>
T sqr(T a)
{
    return a*a;
}
void vout(string s)
{
    cout << s << endl;
    exit(0);
}
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    n*=2;
    ll i1;
    for(i=1;i<=n;i++)cin >> a[i];
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)if(i!=j)
    {
        sc=0;
        s.clear();
        l=0;
        r=0;
        for(i1=1;i1<=n;i1++)mp[a[i1]]=0;
        for(i1=1;i1<=n;i1++)if(i1!=i && i1!=j)
        {
            mp[a[i1]]++;
            s.insert(a[i1]);
        }
        for(i1=1;i1<=n;i1++)if(mp[a[i1]]%2==0)
        {
            s.erase(a[i1]);
            mp[a[i1]]=0;
        }else mp[a[i1]]=1;

        while(s.size()>1)
        {
            set <ll> :: iterator it=s.begin();
            x=*it;
            while(mp[x]>0 && s.size()>1)
            {
                if(l==r)break;
                set <ll> :: iterator it1=s.end();
                it1=it;
                ++it1;
                c1=*it1;
                sc+=c1-x;
                if(mp[c1]==mp[x])
                {
                    mp[x]=0;
                    mp[c1]=0;
                    s.erase(x);
                    s.erase(c1);
                    break;
                }
                if(mp[c1]<mp[x])
                {
                    s.erase(c1);
                    mp[x]-=mp[c1];
                    mp[c1]=0;
                    continue;
                }
                mp[c1]-=mp[x];
                mp[x]=0;
                s.erase(x);
                break;
            }
            l++;
        }
        ans=min(ans,sc);
    }
    cout << ans << endl;
return 0;
}