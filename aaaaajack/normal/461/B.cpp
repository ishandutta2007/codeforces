#include<cstdio>
#define N 100100
#define Q 1000000007
using namespace std;
int p[N],c[N],all[N],rate[N];
int inv(int x){
	int y=Q-2,r=1;
	while(y){
		if(y&1) r=1LL*r*x%Q;
		x=1LL*x*x%Q;
		y>>=1;
	}
	return r;
}
int main(){
	int n,i;
	scanf("%d",&n);
	for(i=1;i<n;i++) scanf("%d",&p[i]);
	for(i=0;i<n;i++) scanf("%d",&c[i]);
	for(i=0;i<n;i++){
		all[i]=1;
	}
	for(i=n-1;i;i--){
		if(c[i]) rate[p[i]]++;
		else rate[p[i]]=(rate[p[i]]+1LL*rate[i]*inv(1+rate[i])%Q)%Q;
		if(c[i]) all[p[i]]=1LL*all[p[i]]*all[i]%Q;
		else all[p[i]]=1LL*all[p[i]]*all[i]%Q*(1+rate[i])%Q;
	}
	if(c[i]) printf("%d\n",all[0]);
	else printf("%d\n",1LL*all[0]*rate[0]%Q);
	return 0;
}