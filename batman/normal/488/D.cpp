#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N (101*1000)
#define INF ((ll)1e9)

ll n,s,l,a[N],dp[N];
set <ll> st,st_l;
map <ll,ll> mp,mp_l;


int main()
{
    cin>>n>>s>>l;
    for(int i=1,j=1;i<=n;i++)
    {
        cin>>a[i];
        st.insert(a[i]),mp[a[i]]++;
        while(*st.rbegin()-*st.begin()>s)
        {
            mp[a[j]]--;
            if(mp[a[j]]==0)st.erase(a[j]);
            if(j<=i-l)
            {
                mp_l[dp[j-1]]--;
                if(mp_l[dp[j-1]]<=0)st_l.erase(dp[j-1]);
            }
            j++;
        }
        if(j<=i-l+1)
            mp_l[dp[i-l]]++,st_l.insert(dp[i-l]);
        if(st_l.size())dp[i]=*st_l.begin()+1;
        else dp[i]=INF;
        //cout<<dp[i]<<" "; 
    }
    cout<<((dp[n]>=INF)?-1:dp[n]);
    return 0;
}