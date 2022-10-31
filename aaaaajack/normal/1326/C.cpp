#include<bits/stdc++.h>
#define N 200100
#define Q 998244353
using namespace std;
int a[N];
int main(){
	int n,k;
	int pre=-1;
	long long a1=0,a2=1;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		if(a[i]>n-k){
			a1+=a[i];
			if(pre>=0) a2*=i-pre;
			a2%=Q;
			pre=i;
		}
	}
	printf("%lld %lld\n",a1,a2);
	return 0;
}