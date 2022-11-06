#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5005,P=1e9+7;
int n,m,mx,a[N],x[N],y[N],c1[N],c2[N];ll ans;
vector<int>V[N];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)scanf("%d%d",&x[i],&y[i]),V[x[i]].push_back(y[i]);
	for(int i=1;i<=n;i++)sort(V[i].begin(),V[i].end());
	for(int i=0;i<=n;i++)
	{
		memset(c1,0,sizeof(c1));memset(c2,0,sizeof(c2));
		for(int x=1;x<=i;x++)c1[a[x]]++;
		for(int x=i+1;x<=n;x++)c2[a[x]]++;
		int ff=i==0,tt=i!=0;ll s=1;
		for(int x:V[a[i]])if(x==c1[a[i]]){ff=1;break;}
		if(!ff)continue;
		for(int j=1;j<=n;j++)
		{
			int sz=V[j].size(),x=0,y=0;
			while(x<sz&&V[j][x]<=c1[j])x++;
			while(y<sz&&V[j][y]<=c2[j])y++;
			if(j==a[i])x=0,y-=(c2[j]>=c1[j]);
			if(!x&&!y)continue;
			if(x>y)swap(x,y); 
			if(!x)s=s*y%P,tt++;
			else if(y==1)s=s*2%P,tt++;
			else s=s*x*(y-1)%P,tt+=2;
		}
		if(tt>mx)mx=tt,ans=0;
		if(tt==mx)ans=(ans+s)%P;
	}
	printf("%d %lld\n",mx,ans);
	return 0;
}