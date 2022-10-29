#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
ll x[100],y[100],ax,ay,bx,by,xs,ys,t,T;
int i,j,k,tot,ans;
ll Abs(ll a)
{
	return a>0?a:-a;
}
ll dis(ll xa,ll ya,ll xb,ll yb)
{
	return Abs(xa-xb)+Abs(ya-yb);
}
int main()
{
	scanf("%lld%lld%lld%lld%lld%lld",&x[0],&y[0],&ax,&ay,&bx,&by);
	for(i=0;;++i)
	{
		if((30000000000000000ll-bx)/ax/x[i]==0||(30000000000000000ll-by)/ay/y[i]==0)
			break;
		x[i+1]=x[i]*ax+bx,y[i+1]=y[i]*ay+by;
	}
	tot=i;
	scanf("%lld%lld%lld",&xs,&ys,&T);
	for(i=0;i<=tot;++i)
	{
		t=T;
		if(dis(xs,ys,x[i],y[i])>t)
			continue;
		t-=dis(xs,ys,x[i],y[i]);
		k=1;
		for(j=i-1;j>=0;--j)
		{
			if(dis(x[j+1],y[j+1],x[j],y[j])>t)
				break;
			t-=dis(x[j+1],y[j+1],x[j],y[j]);
			++k;
		}
		ans=max(ans,k);
		t=T;
		t-=dis(xs,ys,x[i],y[i]);
		k=1;
		for(j=i+1;j<=tot;++j)
		{
			if(dis(x[j-1],y[j-1],x[j],y[j])>t)
				break;
			t-=dis(x[j-1],y[j-1],x[j],y[j]);
			++k;
		}
		ans=max(ans,k);
	}
	printf("%d",ans);
	return 0;
}