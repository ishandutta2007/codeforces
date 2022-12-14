#include <bits/stdc++.h>
#define p_b push_back
#define endl "\n"
#define m_p make_pair
#define fi first
#define se second
#define pll pair <ll,ll>
using namespace std;
typedef long long ll;
const ll shl=1;
const ll MAXN=10000;
string s,s1;
char cc;
ll l,r,c,sc,n,m,i,j,a1,b1,c1,ans,x,k,dp[MAXN],mx;
pair <pll,ll> a[MAXN];
int main() {


    // set < ll > :: iterator kek=s.begin;
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    cin >> n;
    for(i=0;i<n;i++)
    {
        ll y,p,q;
        cin >>  x >> y >> p >> q;
        l=0;
        r=2*1e18/q;
        ans=1e18;
        while(l<r)
        {
            ll c=(l+r)/2;
            ll p1=p*c,q1=q*c;
            if(p1-x<=q1-y && p1-x>=0 && q1-y>=0)
            {
                r=c;
                ans=min(q1-y,ans);
            }else l=c+1;
        }
        if(ans==1e18)cout << -1;else cout << ans;
        cout << endl;
    }
    return 0;
}