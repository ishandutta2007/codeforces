#include<cstdio>
using namespace std;
int main(){
	int i,v[2000],n,m,x,y,ans=0;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%d",&v[i]);
	while(m--){
		scanf("%d%d",&x,&y);
		if(v[x]<v[y]) ans+=v[x];
		else ans+=v[y];
	}
	printf("%d\n",ans);
	return 0;
}