#include<cstdio>
using  namespace std;
long long n,m,k,x,y;
int main(){
	scanf("%lld",&n);
	while(n--){
		scanf("%lld%lld",&x,&y);
		if((x&1)!=(y&1)) printf("NO\n");
		else{
			if(y*y<=x) printf("YES\n");
			else printf("NO\n");
		}
	}
}