#include<bits/stdc++.h>
#define it register int
#define ct const int
#define il inline
#define P 1000000007
using namespace std;
const int N=2000005;
int T,n,f[N];
int main(){ 
	it i;
	f[0]=0,f[1]=0,f[2]=0,f[3]=1,f[4]=1,f[5]=3;
	for(i=6;i<=2000000;++i) f[i]=(f[i-1]+2ll*f[i-2]+(i%3==0))%P;
	scanf("%d",&T);
	while(T--) scanf("%d",&n),printf("%d\n",f[n]*4ll%P);
	return 0;
}