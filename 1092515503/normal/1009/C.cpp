#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,x,d1,d2,res,md;
double sef;
signed main(){
	scanf("%lld%lld",&n,&m);
	for(int i=1,a,b;i<=m;i++){
		scanf("%lld%lld",&a,&b);
		x+=a;
		if(b>=0)d1+=b;
		else d2+=b;
	}
	for(int i=0;i<n;i++)res+=i*d1;
	md=n>>1;
	for(int i=0;i<n;i++)res+=abs(i-md)*d2;
	sef=1.0*res/n;
	printf("%.8lf\n",sef+x);
	return 0;
}