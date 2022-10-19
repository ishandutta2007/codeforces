#include<bits/stdc++.h>
using namespace std;
int a[1005],hs[1005],zb[10005];
int mex()
{
	for(int i=0;;i++)if(!hs[i])return i;
}
void del(int x)
{
	hs[x]--;
}
void add(int x)
{
	hs[x]++;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		memset(hs,0,sizeof(hs));
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]),hs[a[i]]++;
		int tot=0;
		for(int i=1;i<=n;)
		{
			if(a[i]==i-1)
			{
				i++;
				continue;
			}
			int tt=mex();
			if(tt==i-1)del(a[i]),add(tt),zb[++tot]=i,a[i]=tt;
			else if(tt!=n)del(a[tt+1]),add(tt),zb[++tot]=tt+1,a[tt+1]=tt;
			else for(int j=1;j<=n;j++)if(a[j]!=j-1)
			{
				del(a[j]),add(tt),zb[++tot]=j,a[j]=tt;
				break;
			}
		}
		cout<<tot<<endl;
		for(int i=1;i<=tot;i++)printf("%d ",zb[i]);
		puts("");
	}
	return 0;
}