#include<bits/stdc++.h>
using namespace std;
char s[600005],b[15];
int k,a[600005],fa[600005];
void dfs(int x,int step)
{
	if(step==k+1)
	{
		a[x]=1;
		return;
	}
	fa[(x<<1)]=fa[(x<<1)|1]=x;
	dfs(x<<1,step+1);
	dfs(x<<1|1,step+1);
	if(s[(1<<k)-x]=='0')a[x]=a[x<<1|1];
	else if(s[(1<<k)-x]=='1')a[x]=a[x<<1];
	else a[x]=a[x<<1]+a[x<<1|1];
}
int main()
{
	cin>>k;
	scanf("%s",s+1);
	dfs(1,1);
	int q;
	cin>>q;
	while(q--)
	{
		int aa;
		scanf("%d%s",&aa,b+1);
		int wz=(1<<k)-aa;
		s[aa]=b[1];
		while(wz)
		{
			if(s[(1<<k)-wz]=='0')a[wz]=a[wz<<1|1];
			else if(s[(1<<k)-wz]=='1')a[wz]=a[wz<<1];
			else a[wz]=a[wz<<1]+a[wz<<1|1];
			wz=fa[wz];
		}
		cout<<a[1]<<endl;
	}
	return 0;
}