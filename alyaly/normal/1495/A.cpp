#include<bits/stdc++.h>
#define N 200000
using namespace std;
int T,n,a[N+1],b[N+1],pa,pb,p,q;
double ans;
double dis(double xa,double ya,double xb,double yb){
	return sqrt((xb-xa)*(xb-xa)+(yb-ya)*(yb-ya));
}
bool comp(int x,int y){return abs(x)<abs(y);}
signed main(){
	cin>>T;
	while(T--){
		cin>>n;ans=0;pa=pb=0;
		for(int i=1;i<=2*n;i++){
			cin>>p>>q;
			if(p==0)a[++pa]=q;
			else b[++pb]=p;
		}
		sort(a+1,a+pa+1,comp);
		sort(b+1,b+pb+1,comp);
		for(int i=1;i<=n;i++)ans+=dis(a[i],0,0,b[i]);
		printf("%.10f\n",ans);
	}
	return 0;
}