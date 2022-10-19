#include<cstdio>
#include<cmath>
#include<algorithm> 
#include<cstring>
using namespace std;
int n,m,k,x,y,z,q[100039],a[100039],dfn[100039],dh,beg[100039],ends[100039],f[100039],l=1,r,ans[100039];
struct ques{int x,y,z,num;}sf[100039],tmp;
inline bool cmp(ques x,ques y){return (x.x/k==y.x/k)?(((x.x/k)&1)?x.y<y.y:x.y>y.y):x.x<y.x;}
struct yyy{int to,z;};
struct ljb{
	int head,h[100039];
	yyy f[200039];
	inline void add(int x,int y){
		f[++head]=(yyy){y,h[x]};
		h[x]=head;
	}
}s;
inline void dfs(int x,int last){
	dfn[++dh]=x;
	beg[x]=dh;
	yyy tmp;
	for(int cur=s.h[x];~cur;cur=tmp.z){
		tmp=s.f[cur];
		if(tmp.to!=last) dfs(tmp.to,x);
	}
	ends[x]=dh;
}
int main(){
//	freopen("1.in","r",stdin);
	memset(s.h,-1,sizeof(s.h));
	register int i;
	scanf("%d%d",&n,&m);
	k=sqrt(n);
	for(i=1;i<=n;i++)scanf("%d",&a[i]);
	for(i=1;i<n;i++) scanf("%d%d",&x,&y),s.add(x,y),s.add(y,x);
	dfs(1,0);
	for(i=1;i<=m;i++) scanf("%d%d",&x,&y),sf[i]=(ques){beg[x],ends[x],y,i};
	sort(sf+1,sf+m+1,cmp);
	for(i=1;i<=m;i++){
		tmp=sf[i];
		while(l>tmp.x){
			l--;
			f[a[dfn[l]]]++;
			q[f[a[dfn[l]]]]++;
		}
		while(r<tmp.y){
			r++;
			f[a[dfn[r]]]++;
			q[f[a[dfn[r]]]]++;
		}
		while(r>tmp.y){
			q[f[a[dfn[r]]]]--;
			f[a[dfn[r]]]--;
			r--;
		}
		while(l<tmp.x){
			q[f[a[dfn[l]]]]--;
			f[a[dfn[l]]]--;
			l++;
		}
		ans[tmp.num]=q[tmp.z];
	}
	for(i=1;i<=m;i++) printf("%d\n",ans[i]);
}