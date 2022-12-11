#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,L,a[100003],pl=0,pr;
double nl=0,nr=L,vl=1,vr=1,ans;
signed main(){
	cin>>T;
	while(T--){
		cin>>n>>L;ans=0;vl=vr=1;pl=0;pr=n+1;
		for(int i=1;i<=n;i++)cin>>a[i];nr=a[n+1]=L;nl=0;
		while(1){
			double tl=(a[pl+1]-nl)/vl,tr=(nr-a[pr-1])/vr,tt=(nr-nl)/(vr+vl);
			if(tt<tl&&tt<tr){
				ans+=tt;
				break;
			}else if(tl<tr){
				pl++;nl=a[pl];vl++;
				nr-=tl*vr;ans+=tl;
			}else{
				pr--;nr=a[pr];vr++;
				nl+=tr*vl;ans+=tr;
			}
		}
		printf("%.15f\n",ans);
	}
	return 0;
}