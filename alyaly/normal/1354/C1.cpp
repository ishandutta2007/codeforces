#include<bits/stdc++.h>
//#pragma GCC optimize(2)
#define int long long
#include<queue>
#define pi 3.141592653589793238
//#define P 998244353
using namespace std;
int T,n;
double ans,p;
signed main(){
	cin>>T;
	while(T--){
		cin>>n;
		n*=2;
		ans=0;
		p=2.0*pi/n;
		for(double i=pi/2;i>=0;i-=p){
			ans+=2*sin(i);
		}
		ans-=1;
		printf("%.9lf\n",ans);
	}
	return 0;
}
/*

*/