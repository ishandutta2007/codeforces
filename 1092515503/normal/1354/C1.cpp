#include<bits/stdc++.h>
using namespace std;
const double pi=acos(-1);
int T,n;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		double a=pi/n,res=0,b=0;
		for(int i=1;i<=n;i++,b+=a)res+=fabs(cos(b));
		printf("%.9lf\n",res);
	}
	return 0;
}