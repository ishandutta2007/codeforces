#include<cstdio>
#define N 100010
using namespace std;
int x[N],y[N],cnt[N]={0};
int main(){
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d%d",&x[i],&y[i]),cnt[x[i]]++;
	for(i=0;i<n;i++) printf("%d %d\n",n-1+cnt[y[i]],n-1-cnt[y[i]]);
	return 0;
}