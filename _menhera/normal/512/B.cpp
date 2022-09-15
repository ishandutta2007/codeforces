#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;
//dp[i][j] :til ith, gcd:j mincost
map<int,int> dp[301];
int l[301],c[301];
int gcd(int a,int b)
{
	if(a<b) return gcd(b,a);
	if(b==0) return a;
	return gcd(b,a%b);
}
int main()
{
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++) scanf("%d",l+i);
	for(int i=0;i<N;i++) scanf("%d",c+i);
	dp[0][0]=0;
	dp[0][l[0]]=c[0];
	for(int i=1;i<N;i++)
	{
		for(map<int,int>::iterator it=dp[i-1].begin();it!=dp[i-1].end();it++)
		{
			pair<int,int> tmp=*it;
			int gcdval=tmp.first,dpval=tmp.second;
			int v=dp[i][gcd(l[i],gcdval)];
			if(v==0) dp[i][gcd(l[i],gcdval)]=dpval+c[i];
			else dp[i][gcd(l[i],gcdval)]=min(dp[i][gcd(l[i],gcdval)],dpval+c[i]);
			v=dp[i][gcdval];
			if(v==0) dp[i][gcdval]=dpval;
			else dp[i][gcdval]=min(dp[i][gcdval],dpval);
		}
	}
	if(dp[N-1][1]!=0) printf("%d",dp[N-1][1]);
	else printf("-1");
	return 0;
}