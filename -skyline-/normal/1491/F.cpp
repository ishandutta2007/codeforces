#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
using namespace std;
int T,n,a[2005],b[2005];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i)b[i]=1;
		int k=1;
		while(1){
			++k;
			printf("? %d 1\n",k-1);
			for(int i=1;i<k-1;++i)printf("%d ",i);
			printf("%d\n",k-1);
			printf("%d\n",k);
			fflush(stdout);
			int x;
			scanf("%d",&x);
			if(x) break;
		}
		b[k]=0;
		for(int i=k+1;i<=n;++i){
			printf("? 1 1\n%d\n%d\n",k,i);
			fflush(stdout);
			int x;
			scanf("%d",&x);
			if(x)b[i]=0;
		}
		int l=1,r=k-1;
		int cnt=0;
		while(r>l){
			int mi=(l+r)/2;
			printf("? %d 1\n",mi-l+1);
			for(int i=l;i<mi;++i)printf("%d ",i);
			printf("%d\n",mi);
			printf("%d\n",k);
			fflush(stdout);
			int x;
			scanf("%d",&x);
			if(x)r=mi;
			else l=mi+1;
			++cnt;
		}
		b[l]=0;
		int m=0;
		for(int i=1;i<=n;++i)if(b[i])a[++m]=i;
		printf("! %d",m);
		for(int i=1;i<=m;++i)printf(" %d",a[i]);
		printf("\n");
		fflush(stdout);
	}
    return 0;
}