#include <bits/stdc++.h>
#define ll long long
#define p_b push_back
#define endl "\n"
#define m_p make_pair
#define fi first
#define se second
#define pll pair <ll,ll>
using namespace std;
vector <ll> tt[1000];
set <ll> s,sv;
ll p[1000000],i,j,n,m,k,sc,dp,x,a[100000],b[100000],a1,b1,c1,ans;
int main() {

    // set < ll > :: iterator kek=s.begin;
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(i=0;i<n;i++)cin >> a[i];

    for(i=0;i<n;i++)
    {
        ll mx1=-1e18,mx2=-1e18,mn1=1e18,mn2=1e18;
        if(i!=0)
        {
            mx1=abs(a[i]-a[0]);
            mn1=abs(a[i]-a[i-1]);
        }
        if(i!=n-1)
        {
           mx2=abs(a[i]-a[n-1]);
           mn2=abs(a[i]-a[i+1]);
        }
        cout << min(mn1,mn2) << " " << max(mx1,mx2) << endl;
    }
    return 0;
}