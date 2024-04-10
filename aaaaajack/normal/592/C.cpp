#include<cstdio>
#include<algorithm>
using namespace std;
inline long long gcd(long long a,long long b){
	while(b){a%=b,a^=b,b^=a,a^=b;}
	return a;
}
int main(){
	long long o,t,w,b,g,ans=-1,lcm;
	scanf("%I64d%I64d%I64d",&t,&w,&b);
	o=t;
	g=gcd(w,b);
	if(t/b>=w/g){
		lcm=w/g*b;
		ans+=t/lcm*min(w,b);
		t%=lcm;
	}
	ans+=min(min(w,b),t+1);
	g=gcd(ans,o);
	ans/=g,o/=g;
	printf("%I64d/%I64d\n",ans,o);
	return 0;
}