#include<cstdio>
using namespace std;
int m,k,x,y,z,t;
long long n;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%lld",&n);
		while(n%2==0) n>>=1;
		if(n^1) printf("YES\n");
		else printf("NO\n");
	}
}