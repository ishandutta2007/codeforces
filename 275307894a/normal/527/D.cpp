#include<cstdio>
#include<algorithm>
using namespace std;
int n,x,y,ans,tot=-1e9,pus,tail;
struct yyy{
	int l,r;
}f[500039];
inline bool cmp(yyy x,yyy y){
	return x.r<y.r;
}
int main(){
	register int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d%d",&x,&y),f[i]=(yyy){x-y,x+y};
	sort(f+1,f+n+1,cmp);
	for(i=1;i<=n;i++){
		if(f[i].l>=tot) tot=f[i].r,ans++;
	}
	printf("%d\n",ans);
}