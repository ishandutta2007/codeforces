#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)1010)
#define K ((ll)301*1000)

int n,m,k,a[K],b[K],c[K],d[K];
int cnt[26][N][N],down[26][N][N];
ll dp[26][N][N];
string s[N];
char ch[K];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m>>k;
	for(int i=0;i<n;i++)cin>>s[i];
	for(int i=0;i<k;i++)cin>>a[i]>>b[i]>>c[i]>>d[i]>>ch[i],a[i]--,b[i]--,c[i]--,d[i]--,
						down[ch[i]-'a'][a[i]][b[i]]++,down[ch[i]-'a'][a[i]][d[i]+1]--,
						down[ch[i]-'a'][c[i]+1][b[i]]--,down[ch[i]-'a'][c[i]+1][d[i]+1]++;
	ll ans=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			ll res=0,now=0,sum=0,pref=0,all=k;
			for(int p=0;p<26;p++)
			{
				cnt[p][i][j]=down[p][i][j]+(j?cnt[p][i][j-1]:0);
				down[p][i+1][j]+=down[p][i][j];
				res+=abs((s[i][j]-'a')-(p))*cnt[p][i][j];
				all-=cnt[p][i][j];
				sum+=cnt[p][i][j];
				now+=cnt[p][i][j]*p;
			}
			for(int p=0;p<26;p++)
			{
				dp[p][i][j]=res-now-abs((s[i][j]-'a')-(p))*all;
				if(i==0)dp[p][i][j]+=dp[p][i][j-1];
				else if(j==0)dp[p][i][j]+=dp[p][i-1][j];
				else dp[p][i][j]+=dp[p][i-1][j]+dp[p][i][j-1]-dp[p][i-1][j-1];
				sum-=cnt[p][i][j];pref+=cnt[p][i][j];
				now-=sum;now+=pref;
			}
			ans+=res;
		}
	}
	ll res=-(ll)1e18;
	for(int i=0;i<k;i++)
		res=max(res,dp[ch[i]-'a'][c[i]][d[i]]-(a[i]?dp[ch[i]-'a'][a[i]-1][d[i]]:0)-(b[i]?dp[ch[i]-'a'][c[i]][b[i]-1]:0)
			+(a[i] && b[i]?dp[ch[i]-'a'][a[i]-1][b[i]-1]:0));
	cout<<ans-res<<"\n";	
    return 0;
}