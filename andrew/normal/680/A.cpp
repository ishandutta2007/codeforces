#include <bits/stdc++.h>
#define ll long long
#define p_b push_back
#define endl "\n"
#define m_p make_pair
#define fi first
#define se second
#define pll pair <ll,ll>
using namespace std;
const ll shl=1;
const ll maxn=1000000;
vector <ll> tt[1000];
set <ll> ss;
map < ll , ll > mp;
string s,s1;
char cc;
ll c,sc,n,m,i,j,a[10000],b[100000],a1,b1,c1,ans,x;
void vout(string s)
{
    cout << s << endl;
    exit(0);
}
int main() {

    // set < ll > :: iterator kek=s.begin;
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    n=5;
    for(i=0;i<5;i++)cin >> a[i];
    sort(a,a+n);
    for(i=0;i<n;i++)
    {
        x=a[i];
        mp[x]++;
        ss.insert(x);
    }
    set <ll> :: iterator it=ss.end();
    set <ll> :: iterator it1=ss.end();
    --it;
    while(1)
    {
        x=*it;
        if(mp[x]>1 && it==ss.begin())
        {
            mp[x]-=(min(mp[x],3ll));
            break;
        }
        if(mp[x]>1)
        {
            it1=it;
            --it1;
            a1=*it1;
            x=*it;
            if(a1*mp[a1]>x*mp[x])
            {
                --it;
                continue;
            }
            mp[x]-=min(mp[x],3ll);
            break;
        }
        if(it==ss.begin())break;
        --it;
    }
    it=ss.begin();
    for(;it!=ss.end();++it)
    {
        x=*it;
        ans+=mp[x]*x;
    }
    cout << ans << endl;
    return 0;
}