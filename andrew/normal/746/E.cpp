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
template <typename T>
void vout(T s)
{
    cout << s << endl;
    exit(0);
}
const ll shl=1;
const ll MAXN=1123456;
set <ll> s,s1;
map < ll , ll > mp;
//string s2,s1,s3;
char cc;
map <ll,ll> ku;
set <pll> sch,snch;
ll d[MAXN],c,sc,n,m,i,j,a[MAXN],b[MAXN],a1,b1,c1,ans,x,k;
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    cin >> n >> m;
    for(i=2;i<=min(m,1000000ll);i+=2)s.insert(i);
    for(i=1;i<=min(m,1000000ll);i+=2)s1.insert(i);
    for(i=0;i<n;i++)
    {
        cin >> a[i];
        s.erase(a[i]);
        s1.erase(a[i]);
        b[a[i]%2]++;
        mp[a[i]]++;
    }
    for(i=0;i<n;i++)if(a[i]%2)
    {
        snch.insert(m_p(-mp[a[i]],a[i]));
        d[i]=ku[a[i]];
        ku[a[i]]=i;
    }else
    {
        sch.insert(m_p(-mp[a[i]],a[i]));
        d[i]=ku[a[i]];
        ku[a[i]]=i;
    }
    if(b[1]>b[0])
    {
        set <pll> :: iterator it;
        while(b[1]>b[0])
        {
            it=snch.begin();
            ll ke=it->se;
            snch.erase(it);
            b[1]--;
            b[0]++;
            if(s.empty())vout(-1);
            i=ku[ke];
            ku[ke]=d[ku[ke]];
            a[i]=*(s.begin());
            s.erase(*(s.begin()));
            mp[ke]--;
            snch.insert(m_p(-mp[ke],ke));
            ans++;
        }
    }else
    {
        set <pll> :: iterator it;
        while(b[1]<b[0])
        {
            it=sch.begin();
            ll ke=it->se;
            sch.erase(it);
            b[1]++;
            b[0]--;
            if(s1.empty())vout(-1);
            i=ku[ke];
            ku[ke]=d[ku[ke]];
            a[i]=*(s1.begin());
            s1.erase(*(s1.begin()));
            mp[ke]--;
            sch.insert(m_p(-mp[ke],ke));
            ans++;
        }
    }
    for(i=0;i<n;i++)if(mp[a[i]]>1)
    {
        if(a[i]%2==1)
        {
            if(s1.empty())vout(-1);
            mp[a[i]]--;
            a[i]=*(s1.begin());
            s1.erase(s1.begin());
        }else
        {
            if(s.empty())vout(-1);
            mp[a[i]]--;
            a[i]=*(s.begin());
            s.erase(s.begin());
        }
        ans++;
    }
    cout << ans << endl;
    for(i=0;i<n-1;i++)cout << a[i] << " ";
    cout << a[i] << endl;
    return 0;
}