//CF 919D
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 333333;
int n,m,a[N],c[N],dp[N];
vector<int> v[N];
queue<int> Q;
char ch[N];
int main()
{
	int i,j,k,x,y,ans=0;
	scanf("%d%d%s",&n,&m,ch+1);
	while(m--){
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		c[y]++;
	}
	for(i=1;i<=n;i=i+1)
		if(!c[i])
			Q.push(i);
	j=0;
	while(!Q.empty()){
		x=Q.front();
		Q.pop();
		a[++j]=x;
		i=v[x].size();
		while(i--){
			y=v[x][i];
			c[y]--;
			if(!c[y])
				Q.push(y);
		}
	}
	if(j<n){
		printf("-1");
		return 0;
	}
	for(j='a';j<='z';j=j+1){
		memset(dp,0,sizeof(dp));
		for(i=1;i<=n;i=i+1){
			x=a[i];
			if(ch[x]==j)
				dp[x]++;
			k=v[x].size();
			while(k--){
				y=v[x][k];
				dp[y]=max(dp[y],dp[x]);
			}
			ans=max(ans,dp[x]);
		}
	}
	printf("%d",ans);
	return 0;
}