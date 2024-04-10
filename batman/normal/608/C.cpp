#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define INF ((ll)1e9)
#define N (101*1000)

ll n,dp[N],max_dp[N],ans;
pair <ll,ll> a[N];
map <ll,ll> mp;
set <ll> s;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i].first>>a[i].second;
    sort(a+1,a+n+1);
    dp[1]=1;
    s.insert(a[1].first);
    mp[a[1].first]=1;
    for(int i=2;i<=n;i++)
    {
        set <ll>::iterator it=s.lower_bound(a[i].first-a[i].second);
        if(it==s.begin()){dp[i]=1;continue;}
        it--;
        dp[i]=1+dp[mp[*it]];
        s.insert(a[i].first);
        mp[a[i].first]=i;   
    }
    //for(int i=1;i<=n;i++)cout<<dp[i]<<" ";
    for(int i=1;i<=n;i++)max_dp[i]=max(max_dp[i-1],dp[i]);
    cout<<n-max_dp[n];  
    return 0;
}