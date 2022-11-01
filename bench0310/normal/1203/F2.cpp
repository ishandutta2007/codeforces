#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,r;
	scanf("%d%d",&n,&r);
	vector<pair<int,int>> pos,neg;
	for(int i=0;i<n;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        a=max(a,-b);
        if(b>=0) pos.push_back({a,b});
        else neg.push_back({a,b});
    }
    int cnt=0;
    sort(pos.begin(),pos.end());
    for(pair<int,int> p:pos)
    {
        if(r<p.first) break;
        cnt++;
        r+=p.second;
    }
    sort(neg.begin(),neg.end(),[](pair<int,int> a,pair<int,int> b){return a.first+a.second>b.first+b.second;});
    vector<int> dp(r+1,0);
    int res=0;
    for(pair<int,int> p:neg)
    {
        for(int i=p.first;i<=r;i++)
        {
            dp[i+p.second]=max(dp[i+p.second],dp[i]+1);
            res=max(res,dp[i+p.second]);
        }
    }
    res+=cnt;
    printf("%d\n",res);
	return 0;
}