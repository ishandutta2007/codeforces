#include<bits/stdc++.h>
using namespace std;
int main(){
	long long x0,y0,ax,ay,bx,by,xs,ys,t;
	cin>>x0>>y0>>ax>>ay>>bx>>by;
	cin>>xs>>ys>>t;
	long long xm=xs+t,ym=ys+t;
	int n=1;
	long long x[100],y[100];
	x[0]=x0,y[0]=y0;
	while(x[n-1]<=xm&&y[n-1]<=ym&&bx<=xm&&by<=ym&&(xm-bx)/ax>=x[n-1]&&(ym-by)/ay>=y[n-1]){
		x[n]=x[n-1]*ax+bx;
		y[n]=y[n-1]*ay+by;
		n++;
	}
	int ans=0,tmp;
	for(int i=0;i<n;i++){
		tmp=0;
		long long now=abs(x[i]-xs)+abs(y[i]-ys);
		if(now<=t) tmp=1;
		for(int j=i+1;j<n;j++){
			now+=(x[j]-x[j-1])+(y[j]-y[j-1]);
			if(now<=t){
				tmp++;
			}
			else break;
		}
		ans=max(tmp,ans);
		tmp=0;
		now=abs(x[i]-xs)+abs(y[i]-ys);
		if(now<=t) tmp=1;
		for(int j=i-1;j>=0;j--){
			now+=(x[j+1]-x[j])+(y[j+1]-y[j]);
			if(now<=t){
				tmp++;
			}
			else break;
		}
		ans=max(tmp,ans);
	}
	printf("%d\n",ans);
	return 0;
}