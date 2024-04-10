#include <bits/stdc++.h>

using namespace std;

#define fir first
#define sec second
#define pb push_back
#define int ll

typedef long long ll;

int dp[300000],pred[10];

signed main()
{
    string st;
    cin>>st;

    int now=0;
    int ans=0;

    pred[0]=0;
    pred[1]=-1;
    pred[2]=-1;

    for (int i=1;i<=st.size();i++)
    {
        now+=st[i-1]-'0';
        now%=3;
        dp[i]=max(dp[i],dp[i-1]);
        if (pred[now]!=-1)
        {
            dp[i]=max(dp[i],dp[pred[now]]+1);
        }
        pred[now]=i;
    }

    cout<<dp[st.size()];
}