#include<cstdio>
#include<vector>
#include<map>
#define ll long long
#define CI const int &
#define l(x) x<<1
#define r(x) x<<1|1
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int n,m,k,x[300039],y[300039],flag[300039],z,maxn;
ll now,ans;
struct ques{int x,y;}tmp;
vector<ques> g[1200039];
map<ll,int> s;
inline void swap(int &x,int &y){x^=y^=x^=y;}
struct yyy{int x,y,flag;};
struct dsu{
	int fa[600039],sx[600039],sy[600039],w[600039],sh;
	yyy st[600039],tmp;
	inline int find(int x){return fa[x]==x?x:find(fa[x]);}
	inline void merge(int x,int y){
		int un=find(x),wn=find(y);
		if(un!=wn){
			if(w[un]<w[wn]) swap(un,wn);
			ans+=(ll)sx[un]*sy[wn]+(ll)sx[wn]*sy[un];
			st[++sh]=(yyy){un,wn,w[un]==w[wn]};
			sx[un]+=sx[wn];sy[un]+=sy[wn];fa[wn]=un;w[un]+=(w[un]==w[wn]);
		}
	}
	inline void del(){
		tmp=st[sh];sh--;
		fa[tmp.y]=tmp.y;w[tmp.x]-=tmp.flag;
		sx[tmp.x]-=sx[tmp.y];sy[tmp.x]-=sy[tmp.y];
		ans-=(ll)sx[tmp.x]*sy[tmp.y]+(ll)sx[tmp.y]*sy[tmp.x];
	}
}f;
inline void get(int x,int y,ques tmp,CI l=1,CI r=n,CI now=1){
	if(x<=l&&r<=y){g[now].push_back(tmp);return;}
	int m=l+r>>1;
	if(x<=m)get(x,y,tmp,l,m,l(now));
	if(y>m) get(x,y,tmp,m+1,r,r(now));
}
inline void find(CI l=1,CI r=n,CI now=1){
	int lasttop=f.sh,m;
	for(int i=0;i<g[now].size();i++)tmp=g[now][i],f.merge(tmp.x,tmp.y+maxn);
	if(l!=r)m=l+r>>1,find(l,m,l(now)),find(m+1,r,r(now));
	else printf("%lld ",ans);
	while(f.sh!=lasttop) f.del();
}
int main(){
//	freopen("1.in","r",stdin); 
	register int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++) flag[i]=n;
	for(i=1;i<=n;i++)scanf("%d%d",&x[i],&y[i]),maxn=max(maxn,max(x[i],y[i]));
	for(i=1;i<=n;i++){
		now=(ll)x[i]*maxn+y[i];
		if(s[now]) flag[s[now]]=i-1,s[now]=0,flag[i]=0;
		else s[now]=i;
	}
	for(i=1;i<=2*maxn;i++) f.fa[i]=i,f.w[i]=1;
	for(i=1;i<=maxn;i++) f.sx[i]=f.sy[i+maxn]=1;
	for(i=1;i<=n;i++) if(flag[i]) get(i,flag[i],(ques){x[i],y[i]});
	find();
}