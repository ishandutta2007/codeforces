#include <bits/stdc++.h>
#define p_b push_back
#define endl "\n"
#define m_p make_pair
#define fi first
#define se second
#define pll pair <ll,ll>
using namespace std;
typedef long long ll;
vector <ll> tt[1000];
ll p[1000000],i,j,n,m,k,sc,s,dp[1000000],x,a[100000],b[100000],a1,b1,c1,ans;
double l,r,c,d,L,v1,v2;
void fout(string s)
{
    cout << s << endl;
    fflush(stdout);
}
int main() {

    // set < ll > :: iterator kek=s.begin;
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(i=0;i<n;i++)cin >> a[i];
    sort(a,a+n);
    reverse(a,a+n);
    ans+=a[0];
    m=a[0]-1;
    for(i=1;i<n;i++)
    {
        x=min(m,a[i]);
        ans+=x;
        m=x-1;
        m=max(m,0ll);
    }
    cout << ans << endl;
    return 0;
}