#include<cstdio>
#include<vector>
#define CI const int &
#define l(x) x<<1
#define r(x) x<<1|1
using namespace std;
int n,m,k,q,co[500039],x[500039],y[500039],xs[500039],ys[500039],flag[500039],f[500039],un,wn;
struct ques{int x,y,k;};
struct yyy{int x,y,k,flag;}st[2000039],tmp;
inline void swap(int &x,int &y){x^=y^=x^=y;}
int sh;
struct dsu{
	int w[1000039],f[1000039],un,wn;
	inline int find(int x){return f[x]==x?x:find(f[x]);}
	inline void merge(int x,int y,int k){
		un=find(x);wn=find(y);
		if(un==wn)return;
		if(w[un]<w[wn]) swap(un,wn);
		f[wn]=un;w[un]+=(w[un]==w[wn]);
		st[++sh]=(yyy){un,wn,k,w[un]==w[wn]}; 
	}
	inline void del(int x,int y,int flag){f[y]=y;w[x]-=flag;}
}g[51];
inline void del(){tmp=st[sh--];g[tmp.k].del(tmp.x,tmp.y,tmp.flag);}
vector<ques> s[2000039];
inline void get(int x,int y,int xs,int ys,int z,CI l=1,CI r=q,CI now=1){
	if(x<=l&&r<=y){s[now].push_back((ques){xs,ys,z});return;}
	int m=l+r>>1;
	if(x<=m) get(x,y,xs,ys,z,l,m,l(now));
	if(y>m) get(x,y,xs,ys,z,m+1,r,r(now));
}
inline void find(CI l=1,CI r=q,CI now=1){
	int m=l+r>>1,i,lasttop=sh;ques tmp;
	for(i=0;i<s[now].size();i++) tmp=s[now][i],g[tmp.k].merge(tmp.x,tmp.y+n,tmp.k),g[tmp.k].merge(tmp.y,tmp.x+n,tmp.k);
	if(l==r){
		un=g[y[l]].find(xs[x[l]]);wn=g[y[l]].find(ys[x[l]]);//printf("%d %d %d %d\n",un,wn,xs[x[l]],ys[x[l]]);
		if(un==wn) {
			if(co[x[l]]&&l!=q) get(l+1,flag[l],xs[x[l]],ys[x[l]],co[x[l]]);
			printf("NO\n");
		}
		else{
			if(l!=q)get(l+1,flag[l],xs[x[l]],ys[x[l]],y[l]),co[x[l]]=y[l];
			printf("YES\n");
		}
	}
	else find(l,m,l(now)),find(m+1,r,r(now));
	while(sh!=lasttop) del();
}
int main(){
//	freopen("1.in","r",stdin);
	register int i,j;
	scanf("%d%d%d%d",&n,&m,&k,&q);
	for(i=1;i<=k;i++){
	    for(j=1;j<=2*n;j++)g[i].f[j]=j,g[i].w[j]=1; 
	}
	for(i=1;i<=m;i++) scanf("%d%d",&xs[i],&ys[i]);
	for(i=1;i<=q;i++) scanf("%d%d",&x[i],&y[i]),flag[i]=q;
	for(i=1;i<=q;i++){
		if(f[x[i]]) flag[f[x[i]]]=i;
		f[x[i]]=i;
	}
	find();
}