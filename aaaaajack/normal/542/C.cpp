#include<cstdio>
#include<cstring>
#define N 210
using namespace std;
long long lcm(long long a,long long b){
	long long c,ta=a,tb=b;
	while(tb){
		c=ta%tb;
		ta=tb;
		tb=c;
	}
	return a/ta*b; 
}
int step[N],to[N];
int main(){
	int n,i,x,pre;
	long long b=1,l=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&to[i]);
	for(i=1;i<=n;i++){
		memset(step,-1,sizeof(step));
		pre=0;
		for(x=i;step[x]==-1;x=to[x]){
			step[x]=pre;
			pre++;
		}
		b=lcm(b,pre-step[x]);
		if(step[x]>l) l=step[x];
	}
	for(i=1;i*b<l;i++);
	printf("%I64d\n",i*b);
	return 0;
}