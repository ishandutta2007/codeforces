#include<cstdio>
#define N 4010
using namespace std;
int v[N],d[N],p[N],c[N];
int main(){
	int n,ans=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d%d",&v[i],&d[i],&p[i]);
	}
	for(int i=0;i<n;i++){
		if(p[i]>=0){
			c[ans++]=i;
			int cry=0;
			for(int j=i+1;j<n;j++){
				if(p[j]<0) continue;
				p[j]-=cry+v[i];
				if(p[j]<0&&cry<1e7) cry+=d[j];
				if(v[i]) v[i]--;
			}
		}
	}
	printf("%d\n",ans);
	for(int i=0;i<ans;i++) printf("%d ",c[i]+1);
	return 0;
}