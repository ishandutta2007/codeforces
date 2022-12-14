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
map <ll,ll> mp,mp1;
ll k1,k2,kek,p[10000001],i,j,n,m,m1,k,sc,dp,x,a[1000000],b[100000],a1,b1,c1,ans;
int main() {

    // set < ll > :: iterator kek=s.begin;
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    ll step1=k;
    ll step2=k*k;
    for(i=1;i<=n;i++)
    {
        cin >> a[i];
        mp[a[i]]++;
    }
    for(i=n;i>0;i--)
    {
        if(i!=n)mp1[a[i+1]]++;
        mp[a[i]]--;
        if(a[i]%k==0)ans+=mp[a[i]/k]*mp1[a[i]*k];
    }
    cout << ans << endl;
    return 0;
}