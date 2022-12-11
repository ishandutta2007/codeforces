#include<bits/stdc++.h>
//#pragma GCC optimize(2)
#define int long long
#include<queue>
#define pi 3.141592653589793238
//#define P 998244353
using namespace std;
int T,n,m,d;
double ans,p,a;
signed main(){
	cin>>T;
	while(T--){
		cin>>m;
		ans=0;
		n=2*m;
		d=m/2+1;
		p=(pi/2+(2.0/n)*pi*(1.0-d))/2.0;
		a=(n-2)*1.0/n*pi;
		for(double i=p;i<=p+a+0.000000001;i+=(2.0/n)*pi){
			ans+=sin(i);
		}
		printf("%.9f\n",ans);
	}
	return 0;
}
/*

*/