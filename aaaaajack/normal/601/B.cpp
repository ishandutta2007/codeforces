#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#define N 100100
using namespace std;
int a[N],stk[N];
int main(){
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<n-1;i++){
		a[i]=abs(a[i]-a[i+1]);
	}
	while(q--){
		int l,r,sz=1;
		long long tmp=0,res=0;
		scanf("%d%d",&l,&r);
		l--,r--;
		stk[0]=l-1;
		for(int i=l;i<r;i++){
			while(sz>1&&a[i]>=a[stk[sz-1]]){
				sz--;
				tmp+=1LL*(stk[sz]-stk[sz-1])*(a[i]-a[stk[sz]]);
			}
			stk[sz++]=i;
			tmp+=a[i];
			res+=tmp;
		}
		printf("%I64d\n",res);
	}
	return 0;
}