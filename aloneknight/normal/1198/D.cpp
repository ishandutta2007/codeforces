#include<bits/stdc++.h>
using namespace std;
const int N=55;
int n,m,f[N][N][N][N];char s[N][N];
int dfs(int a,int b,int c,int d)
{
	if(~f[a][b][c][d])return f[a][b][c][d];
	if(a==c&&b==d)return f[a][b][c][d]=(s[a][b]=='#');
	int res=max(c-a+1,d-b+1);
	for(int i=a;i<c;i++)res=min(res,dfs(a,b,i,d)+dfs(i+1,b,c,d));
	for(int i=b;i<d;i++)res=min(res,dfs(a,b,c,i)+dfs(a,i+1,c,d));
	return f[a][b][c][d]=res;
}
int main()
{
	scanf("%d",&n);memset(f,-1,sizeof(f));
	for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
	printf("%d\n",dfs(1,1,n,n));return 0;
}