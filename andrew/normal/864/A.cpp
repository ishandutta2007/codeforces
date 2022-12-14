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
set <ll> s;
map <ll,ll> mp;
ll a[maxn],b[maxn],c,a1,b1,c1,n,m,x,i,j,sc,ans,k;
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
    for(i=0;i<n;i++)
    {
        cin >> x;
        s.insert(x);
        mp[x]++;
    }
    if(s.size()!=2)vout("NO");
    set <ll> :: iterator it=s.begin();
    a1=*it;
    ++it;
    b1=*it;
    if(mp[a1]!=mp[b1])vout("NO");
    cout << "YES" << endl;
    cout << a1 << " " << b1 << endl;
return 0;
}