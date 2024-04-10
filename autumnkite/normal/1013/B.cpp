#include <cstdio>
#include <algorithm>
#include <cstring>
const int N=100005;
int n,x,a[N],w[N],b[N],ans;
void upd(int p,int q){
	b[p]=std::min(b[p],q);
}
int main(){
	memset(b,0x3f,sizeof b);
	scanf("%d%d",&n,&x);
	ans=0x3f3f3f3f;
	for (register int i=1;i<=n;++i){
		scanf("%d",a+i),w[i]=(a[i]&x)!=a[i];
		ans=std::min(ans,std::min(w[i]+b[a[i]&x],b[a[i]]));
		upd(a[i],0),upd(a[i]&x,w[i]);
	}
	printf("%d",ans==0x3f3f3f3f?-1:ans);
}