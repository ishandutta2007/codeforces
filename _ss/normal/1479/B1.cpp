#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(),vr.end()
#define vi vector<int>
#define vll vector<ll>
const int N=1e5+10;
int n,a[N],dp[N];
int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    multiset<int> st;
    //for (int i=1;i<=n;i++) dp[i]=1e9;
    for (int i=0;i<=n;i++) st.insert(dp[i]);
    int bonus=0;
    for (int i=1;i<=n;i++)
    {
        int val=0;
        if (i>1)
        {
            val=dp[a[i]]+bonus;
            st.erase(st.find(dp[a[i]]));
            auto it=st.end();
            it--;
            val=max(val,(*it)+bonus+1);
            st.insert(dp[a[i]]);
        }
        if (a[i]!=a[i-1]) bonus++;
        if (i>1 && val-bonus>dp[a[i-1]])
        {
            st.erase(st.find(dp[a[i-1]]));
            dp[a[i-1]]=val-bonus;
            st.insert(dp[a[i-1]]);
        }
    }
    int res=0;
    for (int i=0;i<=n;i++) res=max(res,dp[i]+bonus);
    cout<<res;
    return 0;
}