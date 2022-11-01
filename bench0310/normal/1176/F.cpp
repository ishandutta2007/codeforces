#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
	long long dp[n+1][10];
	for(int o=0;o<=n;o++) for(int i=0;i<10;i++) dp[o][i]=-1;
	dp[0][0]=0;
	for(int o=1;o<=n;o++)
    {
        int k;
        scanf("%d",&k);
        vector<long long> v[4];
        for(int i=0;i<k;i++)
        {
            int c;
            long long d;
            scanf("%d%I64d",&c,&d);
            v[c].push_back(d);
        }
        for(int i=1;i<=3;i++) sort(v[i].begin(),v[i].end(),greater<long long>());
        for(int i=0;i<10;i++) dp[o][i]=dp[o-1][i];
        long long one=0,two=0,three=0;
        //One card
        for(int i=1;i<=3;i++) for(int j=0;j<(int)v[i].size();j++) one=max(one,v[i][j]);
        for(int i=0;i<10;i++)
        {
            if(dp[o-1][i]!=-1)
            {
                if(i==9) dp[o][(i+1)%10]=max(dp[o][(i+1)%10],dp[o-1][i]+2*one);
                else dp[o][(i+1)%10]=max(dp[o][(i+1)%10],dp[o-1][i]+one);
            }
        }
        //Two cards
        if(v[1].empty()) continue;
        one=v[1][0];
        if(v[1].size()>=2) two=v[1][1];
        if(v[2].size()>=1) two=max(two,v[2][0]);
        if(two==0) continue;
        if(one<two) swap(one,two);
        for(int i=0;i<10;i++)
        {
            if(dp[o-1][i]!=-1)
            {
                if(i==8||i==9) dp[o][(i+2)%10]=max(dp[o][(i+2)%10],dp[o-1][i]+2*one+two);
                else dp[o][(i+2)%10]=max(dp[o][(i+2)%10],dp[o-1][i]+one+two);
            }
        }
        //Three cards
        if(v[1].size()<3) continue;
        one=v[1][0];
        two=v[1][1];
        three=v[1][2];
        for(int i=0;i<10;i++)
        {
            if(dp[o-1][i]!=-1)
            {
                if(i==7||i==8||i==9) dp[o][(i+3)%10]=max(dp[o][(i+3)%10],dp[o-1][i]+2*one+two+three);
                else dp[o][(i+3)%10]=max(dp[o][(i+3)%10],dp[o-1][i]+one+two+three);
            }
        }
    }
    long long res=0;
    for(int i=0;i<10;i++) res=max(res,dp[n][i]);
    printf("%I64d\n",res);
	return 0;
}