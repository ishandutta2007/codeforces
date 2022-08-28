#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 333333;
int n,a[N],b[N],c[N];
LL k;
int main(){
	int T,i,x;
	scanf("%d",&T);
	while(T--){
		scanf("%d%lld",&n,&k);
		k--;
		for(i=0;i<=n+5;i++)
			a[i]=i,b[i]=0;
		for(i=n;i>=2;i--)
			b[i]=k&1,k>>=1;
		if(k){
			printf("-1\n");
			continue;
		}
		x=1;
		for(i=2;i<=n+1;i++){
			if(!b[i])
				reverse(a+x,a+i),x=i;
		}
		for(i=1;i<=n;i++)
			printf("%d ",a[i]);
		printf("\n");
	}
	return 0;
}