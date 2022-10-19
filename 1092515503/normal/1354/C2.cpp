#include<bits/stdc++.h>
using namespace std;
const double pi=acos(-1);
int T,n;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		double a=pi/n,res=0,b=0,qwq=0;
		for(int i=1;i<=n;i++,b+=a)res+=fabs(cos(b)),qwq=max(qwq,cos(b)+sin(b));
		res/=2;
		printf("%.9lf\n",res*qwq*sqrt(2));
	}
	return 0;
}