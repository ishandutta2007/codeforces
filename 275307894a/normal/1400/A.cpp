#include<bits/stdc++.h>
using namespace std;
long long n,m,k,t,ans,a[1039];
char s;
int main(){
	register int i;
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		for(i=1;i<=n*2-1;i++){
			s=getchar();
			while(s<'0'||s>'9') s=getchar();
			a[i]=s-'0';
		}
		for(i=1;i<=n*2-1;i+=2) printf("%d",a[i]);
		printf("\n");
	}
}