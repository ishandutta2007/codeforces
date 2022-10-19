#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n,m,k,x,y,z,id[500039],ks,flag[500039],head,un,wn,co[500039],flags,lasthead;
struct yyy{int x,y;}a[500039],s[500039];
inline bool cmp(yyy x,yyy y){return co[x.x]==co[y.x]?co[x.y]<co[y.y]:co[x.x]<co[y.x];}
struct ques{int x,y,flag;};
inline void swap(int &x,int &y){x^=y^=x^=y;}
struct dsu{
	int f[1000039],w[1000039],head;
	ques st[1000039];
	inline int find(int x){return f[x]==x?x:find(f[x]);}
	inline void merge(int x,int y){
		int un=find(x),wn=find(y);
		if(un!=wn){
			if(w[un]<w[wn]) swap(un,wn);
			st[++head]=(ques){un,wn,w[un]==w[wn]};
			f[wn]=un;w[un]+=(w[un]==w[wn]);
		}
	}
	inline void del(){f[st[head].y]=st[head].y;w[st[head].x]-=st[head].flag,head--;}
}g;
int ans;
int main(){
//	freopen("1.in","r",stdin);
	register int i,j;
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=2*n;i++) g.f[i]=i,g.w[i]=1;
	for(i=1;i<=n;i++) scanf("%d",&co[i]);
	for(i=1;i<=m;i++)scanf("%d%d",&a[i].x,&a[i].y);
	for(i=1;i<=m;i++){
		if(co[a[i].x]==co[a[i].y]){
			un=g.find(a[i].x);wn=g.find(a[i].y);
			if(un==wn) flag[co[a[i].x]]=1;
			else g.merge(a[i].x,a[i].y+n),g.merge(a[i].y,a[i].x+n);
		}
	}
	for(i=1;i<=m;i++) if(!flag[co[a[i].x]]&&!flag[co[a[i].y]]&&co[a[i].x]!=co[a[i].y]) s[++head]=a[i];
	for(i=1;i<=head;i++) if(co[s[i].x]>co[s[i].y]) swap(s[i].x,s[i].y);
	for(i=1;i<=k;i++) if(!flag[i]) ks++;
	sort(s+1,s+head+1,cmp); 
	for(i=1;i<=head;i++){
		lasthead=g.head;flags=0;
		for(j=i;j<=head;j++){
			if(co[s[i].x]!=co[s[j].x]||co[s[i].y]!=co[s[j].y]) break;
			un=g.find(s[j].x);wn=g.find(s[j].y);
			if(un==wn) flags=1;
			else g.merge(s[j].x,s[j].y+n),g.merge(s[j].y,s[j].x+n);
		}//printf("%d %d\n",i,j);
		ans+=flags;i=j-1;
		while(g.head!=lasthead) g.del(); 
	}
	printf("%lld\n",(long long)ks*(ks-1)/2-ans);
}