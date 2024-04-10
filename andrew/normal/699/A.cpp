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
string s,s1,s2,s3;
ll n,m,i,j,k,a[1000000],b[1000000],a1,b1,c1;
int main() {

    // set < ll > :: iterator kek=s.begin;
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    cin >> s;
    for(i=0;i<n;i++)cin >> a[i];
    ll ans=1e18;
    for(i=0;i<n-1;i++)if(s[i]=='R' and s[i+1]=='L')ans=min(ans,(a[i+1]-a[i])/2);

    if(ans==1e18)ans=-1;
    cout << ans << endl;
    return 0;
}