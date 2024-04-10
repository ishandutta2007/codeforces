#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N (101*1000)
#define INF ((ll)1e9)
#define MOD ((ll)1e9+7)

ll n,k,v[N][30],p=1,dp[N];

void dfs(ll x)
{
	
	ll cnt=0;
	for(int i=0;i<26;i++)
		if(v[x][i])
			cnt++,dfs(v[x][i]);
	//cout<<cnt<<" ";			
	if(cnt==0)
		dp[x]=1;
	
	else
	{
		ll num[4]={};
		for(int i=0;i<26;i++)
			if(v[x][i])
				num[dp[v[x][i]]]++;
		
		if(num[2])
			dp[x]=3;		
		else if(num[3]==cnt)
			dp[x]=2;
		else if(!num[1])
			dp[x]=1;
		else if(!num[0])
			dp[x]=0;
		else
			dp[x]=3;	
	}	
	//cout<<dp[x]<<" ";		
}

int main()
{
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		string s;
		cin>>s;
		ll ex=0;
		for(int j=0;j<s.size();j++)
		{
			if(v[ex][s[j]-'a'])
				ex=v[ex][s[j]-'a'];
			else v[ex][s[j]-'a']=p,ex=p++;	
		}
	}
	dfs(0);
	ll cnt=0,num[4]={};
	for(int i=0;i<26;i++)
		if(v[0][i])
			cnt++,num[dp[v[0][i]]]++;
	if(num[2])
		return cout<<"First",0;
	if(num[3]==cnt)
		return cout<<"Second",0;
	if(!num[1])
		return cout<<"Second",0;
	if(!num[0])
		return cout<<((k%2)?"First":"Second"),0;
	cout<<"First";						
    return 0;
}