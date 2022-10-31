#include<stdio.h>
#include<algorithm>
#define it register int
#define ct const int
#define il inline
const int N=1000005;
int T,n,a[N],b[N];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);it i,fl=1;
		for(i=0;i<n;++i) b[i]=0;
		for(i=0;i<n;++i){
			scanf("%d",&a[i]),a[i]=(a[i]+i)%n,a[i]=(a[i]<0?a[i]+n:a[i]);
			if(b[a[i]]) fl=0;
			b[a[i]]=1;
		}
		fl?puts("YES"):puts("NO");
	}
	return 0;
}