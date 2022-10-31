#include<bits/stdc++.h>
#define it register int
#define ct const int
#define il inline
using namespace std;
const int N=1000005;
#define P 998244353
typedef long long ll;
#define rll register ll
#define cll const ll
int a[N],n,m;
int main(){ 
	scanf("%d",&n),printf("%d\n1 %d %d\n",n+1,n,100000);
	for(it i=1;i<=n;++i)
		scanf("%d",&m),m+=100000,printf("2 %d %d\n",i,m-i+1);
	return 0;
}