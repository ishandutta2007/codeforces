#include<cstdio>
#include<map>
#define N 100100
using namespace std;
int gcd(int x,int y){
	if(y==0) return x;
	return gcd(y,x%y);
}
int a[N],next[N];
long long sum[N];
int main(){
	map<int,long long> m;
	int n,q,i,j,pre;
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d",&a[i]),next[i]=i+1;
	for(i=n-1;i>=0;i--){
		pre=i;
		for(j=i;j<n;j=next[j]){
			a[j]=gcd(a[j],a[pre]);
			if(a[j]==a[pre]) next[pre]=next[j];
			else pre=j;
			m[a[j]]+=(next[j]-j);
		}
	}
	scanf("%d",&q);
	while(q--){
		scanf("%d",&pre);
		printf("%I64d\n",m[pre]);
	}
	return 0;
}