#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll x[66],y[66],ax,ay,bx,by,xs,ys,t,xx,yy,ans;
int main(){
	cin>>x[0]>>y[0]>>ax>>ay>>bx>>by>>xs>>ys>>t;
	for(xx=1;x[xx-1]<=5e16;xx++)x[xx]=ax*x[xx-1]+bx;
	for(yy=1;y[yy-1]<=5e16;yy++)y[yy]=ay*y[yy-1]+by;
	for(ll i=0;i<=min(xx,yy)-1;i++){
		ll calc=abs(xs-x[i])+abs(ys-y[i]);
		if(calc>t)continue;
		for(ll j=i-1;j>=0;j--){
			calc+=abs(x[j+1]-x[j])+abs(y[j+1]-y[j]);
			if(calc>t){
				ans=max(ans,i-j);
				break;
			}
		}
		if(calc>t)continue;
		int pre=0;
		for(ll j=i+1;;j++){
			calc+=abs(x[j]-x[pre])+abs(y[j]-y[pre]);
			if(calc>t){
				ans=max(ans,j);
				break;
			}
			pre=j;
		}
	}
	cout<<ans<<endl;
	return 0;
}