#include<cstdio>
#include<vector>
#define beg(x) int cur=s.h[x]
#define end cur
#define go cur=tmp.z
#define l(x) x<<1
#define r(x) x<<1|1
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
int n,m,k,x,y,z,siz[500039],in[500039],bg[500039],cnt;
long long d[500039],f[2000039],sum[2000039],ans[500039],w[500039];
struct yyy{int to,z;};
struct ljb{
	int head,h[500039];
	yyy f[500039];
	inline void add(int x,int y){
		f[++head]=(yyy){y,h[x]};
		h[x]=head;
	}
}s;
inline void swap(int &x,int &y){x^=y^=x^=y;}
struct ques{int l,r,id;}tmps;
vector<ques>fs[500039];
inline void push(int now){
	if(!f[now]) return;
	f[l(now)]+=f[now];f[r(now)]+=f[now];sum[l(now)]+=f[now];sum[r(now)]+=f[now];
	f[now]=0;
}
inline void up(int now){sum[now]=min(sum[l(now)],sum[r(now)]);}
inline void get(int x,int y,long long z,int l,int r,int now){
	if(x<=l&&r<=y) {f[now]+=z;sum[now]+=z;return;}
	push(now);int m=l+r>>1;
	if(x<=m) get(x,y,z,l,m,l(now));
	if(y>m) get(x,y,z,m+1,r,r(now));
	up(now);
}
inline long long find(int x,int y,int l,int r,int now){
	if(x<=l&&r<=y) return sum[now];
	push(now);int m=l+r>>1;long long fs1=1e18,fs2=1e18;
	if(x<=m) fs1=find(x,y,l,m,l(now));
	if(y>m) fs2=find(x,y,m+1,r,r(now));
	return min(fs1,fs2);
}
inline void dfs1(int x){
	yyy tmp;siz[x]=1;
	for(beg(x);end;go){
		tmp=s.f[cur];d[tmp.to]=d[x]+w[tmp.to];dfs1(tmp.to);siz[x]+=siz[tmp.to];
	}
	if(!in[x]) get(bg[x],bg[x],d[x],1,cnt,1);
}
inline void dfs2(int x){
	yyy tmp;
	for(beg(x);end;go){
		tmp=s.f[cur];get(1,cnt,w[tmp.to],1,cnt,1);
		get(bg[tmp.to-1]+1,bg[tmp.to+siz[tmp.to]-1],-2*w[tmp.to],1,cnt,1);//printf("%d\n",find(2,3,1,cnt,1));
		dfs2(tmp.to);
		get(1,cnt,-1*w[tmp.to],1,cnt,1);get(bg[tmp.to-1]+1,bg[tmp.to+siz[tmp.to]-1],2*w[tmp.to],1,cnt,1);
	}
	for(int i=0;i<fs[x].size();i++) tmps=fs[x][i],ans[tmps.id]=find(bg[tmps.l-1]+1,bg[tmps.r],1,cnt,1);
}
int main(){
//	freopen("1.in","r",stdin);
	register int i;
	scanf("%d%d",&n,&m);
	for(i=2;i<=n;i++){
	    scanf("%d%lld",&x,&w[i]);
		s.add(x,i);in[x]++;
	} 
	for(i=1;i<=n;i++) bg[i]=bg[i-1]+(!in[i]);cnt=bg[n];
	for(i=1;i<=m;i++) scanf("%d%d%d",&x,&y,&z),fs[x].push_back((ques){y,z,i});
	dfs1(1);
	dfs2(1);
	for(i=1;i<=m;i++) printf("%lld\n",ans[i]);
}