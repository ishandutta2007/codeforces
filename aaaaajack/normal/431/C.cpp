#include<cstdio>
#define Q 1000000007
using namespace std;
int dpn[200]={1},dpb[200]={0};
int main(){
	int i,j,n,k,d;
	scanf("%d%d%d",&n,&k,&d);
	for(i=0;i<=n;i++){
		for(j=i-1;j>=0&&j>=i-k;j--){
			dpn[i]+=dpn[j];
			dpn[i]%=Q;
		}
	}
	for(i=0;i<=n;i++){
		for(j=i-1;j>=0&&j>i-d;j--){
			dpb[i]+=dpb[j];
			dpb[i]%=Q;
		}
		for(j=i-d;j>=0&&j>=i-k;j--){
			dpb[i]+=dpn[j];
			dpb[i]%=Q;
		}
	}
	printf("%d\n",dpb[n]);
}