#include<bits/stdc++.h>
using namespace std;
int a[200005],l[200005],r[200005],d1[200005],d2[200005],bl[200005];
void DO(int i,int j)
{
	if(j+a[j]>r[i])d1[j]=j+a[j],d2[j]=1;
	else d1[j]=d1[j+a[j]],d2[j]=d2[j+a[j]]+1;
}
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	int SS=sqrt(n),ss=(n-1)/SS+1;
	for(int i=1;i<ss;i++)l[i]=(i-1)*SS+1,r[i]=i*SS;
	l[ss]=(ss-1)*SS+1,r[ss]=n;
	for(int i=ss;i>=1;i--)for(int j=r[i];j>=l[i];j--)bl[j]=i,DO(i,j);
	for(int i=1;i<=m;i++)
	{
		int op,ll;
		scanf("%d%d",&op,&ll);
		if(op==1)
		{
			int wz=ll,ans=0;
			while(d1[wz]<=n)ans+=d2[wz],wz=d1[wz];
			while(wz+a[wz]<=n)ans++,wz+=a[wz];
			printf("%d %d\n",wz,ans+1);
		}else
		{
			int rr;
			scanf("%d",&rr);
			a[ll]=rr;
			for(int j=ll;j>=l[bl[ll]];j--)DO(bl[ll],j);
		}
	}
	return 0;
}