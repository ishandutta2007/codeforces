#include<cstdio>
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
long long n,m,k,x,y,z,T,ans,tot,pus;
inline long long h(long long x,long long m){
	long long res=0,j;long long i,now;
	for(i=1;i<=min(x+1,m);i=j+1){
		j=m/(m/i);
		res+=(j-i+1)*(m/i);now=m/i;
	}res-=m;
	if(i>x+1) res-=now*(i-x-2);
	for(i=1;i*i<=m&&i<=x;i++){
		res-=m/(i+1);
		res+=i-1;
	}
	return res;
}
int main(){
//	freopen("1.in","r",stdin);
	register int i;
	scanf("%d",&T);
	while(T--){
		scanf("%lld%lld",&x,&y);
		printf("%lld\n",h(y,x));
	}
}