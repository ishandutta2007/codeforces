#include<cstdio>
#define mod 1000000007
using namespace std;
int t;
long long siz,n,m,k,front,last,ans;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%lld",&m);
		front=m/2;last=(m%4)/2;siz=m/4+1;
		front+=last;ans=siz;
		if(front%2==0)front/=2;
		else ans/=2; 
		printf("%lld\n",((front)%mod*(ans%mod)%mod+siz)%mod);
	}
}