#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n,k,i,t,j,m;
char c[N];
long long ans,s;
struct str{
	int l,r;
}p[N],a[N];
bool cmp(str a,str b)
{
	return a.r-a.l>b.r-b.l;
}
bool cmp2(str a,str b)
{
	return a.r<b.r;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&n);
	scanf("%s",c+1);
	for(i=1;i<=n;++i)
		if(c[i]=='1')
		{
			for(j=i;c[j]=='1';++j);
			p[++k]=(str){i,j-1};
			i=j;
		}
	sort(p+1,p+1+k,cmp);
	for(i=1;i<=n;++i)
	{
		int las=0;
		for(j=1;j<=k;++j)
			if(p[j].r-p[j].l+1>=i)
				a[j]=p[j];
			else
				break;
		m=j-1;
		sort(a+1,a+1+m,cmp2);
		s=las=0;
		for(j=1;j<=m;++j)
		{
			if(las!=0)
				s+=1ll*(i+a[j].l+i-1-las)*(a[j].l-las)/2;
			else
				s+=1ll*(a[j].l+i-2)*(a[j].l+i-1)/2;
			las=a[j].r-i+2;
			s+=1ll*(a[j].r-a[j].l+2-i)*(i-1);
		}
		if(m!=0)
			s+=1ll*(i+n-las+1)*(n-a[m].r)/2;
		else
			s=1ll*n*(n+1)/2;
		//cout<<s<<endl;
		ans+=1ll*n*(n+1)/2-s;
	}
	cout<<ans;
}