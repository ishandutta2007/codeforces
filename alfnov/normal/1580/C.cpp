#pragma GCC optimize(2) 
#include<bits/stdc++.h>
using namespace std;
int x[200005],y[200005];
int tim[200005],cnt[3005][3005];
int n,m,c[200005];
void add(int x,int s)
{
	if(x>m)return;
	c[x]+=s;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
		x[i]=min(x[i],m),y[i]=min(y[i],m);
	}
	int S=min(m+0.0,sqrt(m+0.5)),lst=0;
	for(int l=1;l<=m;l++)
	{
		int op,k;
		scanf("%d%d",&op,&k);
		int aa=3-2*op;
		if(op==1)tim[k]=l;
		if(x[k]+y[k]>S)
		{
			for(int i=tim[k]+x[k];i<=m;i+=x[k]+y[k])
				add(max(i,l),aa),add(max(l,i+y[k]),-aa);
		}else
		{
			for(int i=tim[k]+x[k];i<tim[k]+x[k]+y[k];i++)
				cnt[x[k]+y[k]][i%(x[k]+y[k])]+=aa;
		}
		int ans=lst+c[l];
		lst=ans;
		for(int i=1;i<=S;i++)ans+=cnt[i][l%i];
		printf("%d\n",ans);
	}
	return 0;
}