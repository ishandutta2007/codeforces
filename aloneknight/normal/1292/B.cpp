#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=105;
int n,ans=0;ll ax,ay,bx,by,sx,sy,t,x[N],y[N];
inline ll dis(ll sx,ll sy,ll tx,ll ty){return abs(sx-tx)+abs(sy-ty);} 
int main()
{
	scanf("%lld%lld%lld%lld%lld%lld%lld%lld%lld",&x[0],&y[0],&ax,&ay,&bx,&by,&sx,&sy,&t);
	for(n=1;x[n-1]<3e16&&y[n-1]<3e16;n++)x[n]=ax*x[n-1]+bx,y[n]=ay*y[n-1]+by;
	for(n--;n>=0;n--)for(int i=0;i<=n;i++)if(min(dis(sx,sy,x[i],y[i]),dis(sx,sy,x[n],y[n]))+dis(x[i],y[i],x[n],y[n])<=t)ans=max(ans,n-i+1);
	printf("%d\n",ans);return 0;
}