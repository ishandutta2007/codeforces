#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=100005;
char s[N],t[N];
int f[N][2];
int n,m;
vector<int> vec[26][2];
int get (int op,int x,int xx)
{
	int t=n+1;
	int l=0,r=vec[xx][op].size()-1;
	while (l<=r)
	{
		int mid=(l+r)>>1;
		if (vec[xx][op][mid]>=x) {t=vec[xx][op][mid];r=mid-1;}
		else l=mid+1; 
	}
	return t;
}
int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%s%s",s+1,t+1);
		n=strlen(s+1);m=strlen(t+1);
		f[1][0]=f[1][1]=n+1;
		for (int u=0;u<26;u++) 
		{
			vec[u][0].clear();
			vec[u][1].clear();
		}
		for (int u=1;u<=n;u++)
		{
			int x=s[u]-'a';
			vec[x][u&1].push_back(u);
		}
		for (int u=1;u<=n;u++)
		{
			if (s[u]==t[1])	f[1][u&1]=min(f[1][u&1],u);
		}
	//	printf("%d %d\n",f[1][0],f[1][1]);
		for (int u=2;u<=m;u++)
		{
			f[u][1]=get(1,f[u-1][0],t[u]-'a');
			f[u][0]=get(0,f[u-1][1],t[u]-'a');
		//	printf("%d %d\n",f[u][0],f[u][1]);
		}
		if (f[m][n&1]<=n) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}