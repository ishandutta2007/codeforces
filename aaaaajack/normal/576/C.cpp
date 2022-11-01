#include<cstdio>
#include<algorithm>
#define N 1001000
#define S 1000
using namespace std;
int x[N],y[N],id[N];
bool cmp(int i,int j){
	return x[i]/S<x[j]/S||(x[i]/S==x[j]/S&&(x[i]/S%2?y[i]>y[j]:y[i]<y[j]));
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		id[i]=i;
		scanf("%d%d",&x[i],&y[i]);
	}
	sort(id+1,id+n+1,cmp);
	for(int i=1;i<=n;i++) printf("%d ",id[i]);
	return 0;
}