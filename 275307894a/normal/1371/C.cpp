#include<cstdio>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
long long n,m,k,x,y,t,ans1,ans2;
int main(){
	scanf("%lld",&t);
	while(t--){
		scanf("%lld%lld%lld%lld",&n,&m,&x,&y);
		if(min(n,m)<y) printf("No\n");
		else{
			if(n>m) n-=y;
			else m-=y;
			if(n+m>=x) printf("Yes\n");
			else printf("No\n");
		}
	}
}