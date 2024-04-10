#include<bits/stdc++.h>
#define it register int
#define ct const int
#define il inline
using namespace std;
const int N=1000005;
int n,m,ans[N];
struct ky{
	int x,id;
};
vector<ky> vec[N];
int q[N],top1,top2,a[N],b[N];
bool in[N];
int main(){
	scanf("%d%d",&n,&m);it i,pos=m,x,y;
	for(i=1;i<=n;++i) scanf("%d",&a[i]);
	for(i=1;i<=m;++i) scanf("%d%d",&x,&y),vec[x].push_back((ky){y,i}),vec[y].push_back((ky){x,i}),++b[x],++b[y];
	for(i=0;i<=n;++i) if(a[i]>=b[i]) q[++top2]=i;
	for(i=1;i<=n;++i){
		if(top1>=top2) return puts("DEAD"),0;
		ct top=q[++top1];
		for(const auto &p : vec[top])
			if(!in[p.id]){
				ans[pos--]=p.id,in[p.id]=1,--b[p.x];
				if(b[p.x]==a[p.x]) q[++top2]=p.x;
			}
	}
	puts("ALIVE");
	for(i=1;i<=m;++i) printf("%d ",ans[i]);
	return 0;
}