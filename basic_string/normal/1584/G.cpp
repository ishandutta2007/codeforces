#include<bits/stdc++.h>
using namespace std;
enum{N=3009};
const double pi=acos(-1);
int n,d,x[N],y[N],f[N];
double jj[N][N];
bool b[N][N];
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int i,j,k=0;
	double al,ar,bl,br,l,r,u,v;
	long long dis;
	cin>>n>>d,memset(b,1,sizeof b);
	for(i=1;i<=n;++i)cin>>x[i]>>y[i];
	for(i=1;i<=n;++i)for(j=1;j<i;++j){
		jj[j][i]=(jj[i][j]=atan2(y[j]-y[i],x[j]-x[i]))-pi;
		if(jj[j][i]<-pi)jj[j][i]+=2*pi;
	}
	for(i=1;i<=n;++i){
		al=bl=-pi,ar=br=pi;
		for(j=1;j<=n;++j)if(j^i){
			if((dis=(y[j]-y[i])*1ll*(y[j]-y[i])+(x[j]-x[i])*1ll*(x[j]-x[i]))>d*1ll*d){
				u=jj[i][j],v=asin(d/sqrt(dis)),l=u-v,r=u+v;
				if(l>=-pi&&r<=pi)al=max(al,l),bl=max(bl,l),ar=min(ar,r),br=min(br,r);
				else if(l<-pi)ar=min(ar,r),bl=max(bl,l+2*pi);
				else ar=min(ar,r-2*pi),bl=max(bl,l);
			}
		}
		for(j=1;j<=n;++j)if(j^i)if(((u=jj[i][j])<al||u>ar)&&(u<bl||u>br))b[i][j]=b[j][i]=0;
	}
	for(i=1;i<n;++i)for(j=i+1;j<=n;++j)if(b[i][j])++k;
	cout<<k;
	return 0;
}