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
ll l,r,c,sc,n,m,i,j,a[10000],b[100000],a1,b1,c1,ans,x;
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
    cin >> n  >> a1;
    for(i=1;i<=n;i++)cin >> a[i];
    if(a[a1]==1)ans++;
    l=a1-1;
    r=a1+1;
    while(1)
    {
        if(l==0 && r==n+1)break;
        if(l==0 && a[r]==1)ans++;else
        if(r==n+1 && a[l]==1)ans++;else if(a[l]==1 && a[r]==1)ans+=2;
        r++;
        l--;
        r=min(r,n+1);
        l=max(l,0ll);
    }
    cout << ans << endl;
    return 0;
}