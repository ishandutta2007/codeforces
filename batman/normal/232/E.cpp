#include <bits/stdc++.h>
using namespace std;
#define N (503)
#define Q (600*1000+10)

int n,m,q,x1[Q],y1[Q],x2[Q],y2[Q];
string s[N];
bitset <Q> ans;
bitset <N> dp[N][N];
vector <int> now;

void solve(int xl=0,int xr=n)
{
	if(xr-xl==1)
	{
		set <int> st;
		for(int j=0;j<m;j++)if(s[xl][j]=='#')st.insert(j);
		for(auto i:now)
			if(x1[i]==xl && x2[i]==xl)
				ans[i]=(st.lower_bound(y1[i])==st.end() || y2[i]<*st.lower_bound(y1[i]));
		return ;
	}
	int mid=(xl+xr)/2;
	for(int i=mid;i>=xl;i--)
		for(int j=m-1;j>=0;j--)
		{
			if(s[i][j]=='#')continue;
			bool flg=0;
			if(i!=mid && s[i+1][j]=='.')dp[i][j]=dp[i+1][j],flg=1;
			if(j!=m-1 && s[i][j+1]=='.')
			{
				if(flg)dp[i][j]|=dp[i][j+1];
				else dp[i][j]=dp[i][j+1],flg=1;
			}
			if(!flg)dp[i][j].reset();
			if(i==mid)dp[i][j][j]=1;
		}
	for(int i=mid;i<xr;i++)
		for(int j=0;j<m;j++)
		{
			if(s[i][j]=='#')continue;
			bool flg=0;
			if(i!=mid && s[i-1][j]=='.')dp[i][j]=dp[i-1][j],flg=1;
			if(j!=0 && s[i][j-1]=='.')
			{
				if(flg)dp[i][j]|=dp[i][j-1];
				else dp[i][j]=dp[i][j-1],flg=1;	
			}
			if(!flg)dp[i][j].reset();
			if(i==mid)dp[i][j][j]=1;
		}
	vector <int> lft,rght;
	for(auto i:now)
	{
		if(x1[i]<mid && mid<=x2[i])
		{
			if(x1[i]==mid)ans[i]=dp[x2[i]][y2[i]][y1[i]];
			else ans[i]=(dp[x1[i]][y1[i]]&dp[x2[i]][y2[i]]).count();
		}
		else if(x2[i]<mid)lft.push_back(i);
		else rght.push_back(i);
	}
	now.swap(lft);solve(xl,mid);
	now.swap(rght);solve(mid,xr);
}

char c[N];

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)scanf(" %s",&c),s[i]=c;
	scanf("%d",&q);
	for(int i=0;i<q;i++)scanf("%d%d%d%d",&x1[i],&y1[i],&x2[i],&y2[i]),x1[i]--,y1[i]--,x2[i]--,y2[i]--,now.push_back(i);
	solve();
	for(int i=0;i<q;i++)
	{
		if(ans[i])printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}