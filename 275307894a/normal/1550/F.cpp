#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define re register
#define ll long long
#define db double
#define N 200000
#define K 17
#define mod 1000000000
#define mod2 39989
#define eps (1e-7)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
using namespace std;
int n,m,d,cnt,x,y,z,now,un,wn,A[N+5],fa[N+5],Ans[N+5],S,To[N+5],W[N+5],Fr[N+5];vector<int> F[N+5];
struct ques{int w,id;bool operator <(const ques &s)const{return (w==s.w)?id<s.id:w<s.w;}};set<ques> G; 
I int Getfa(int x){return x==fa[x]?x:fa[x]=Getfa(fa[x]);} set<ques>::it pus;
struct yyy{int to,w,z;};
struct ljb{
	int head,h[N+5];yyy f[N+5<<1];
	I void add(int x,int  y,int z){f[++head]=(yyy){y,z,h[x]};h[x]=head;}
}s;
I void dfs(int x,int last){
	yyy tmp;for(int i=s.h[x];i;i=tmp.z) tmp=s.f[i],tmp.to^last&&(Ans[tmp.to]=max(Ans[x],tmp.w),dfs(tmp.to,x),0);
}
int main(){
//	freopen("1.in","r",stdin);
	re int i,j;scanf("%d%d%d%d",&n,&m,&S,&d);cnt=n;for(i=1;i<=n;i++) scanf("%d",&A[i]),G.insert((ques){A[i],i}),fa[i]=i;
	while(cnt^1){
		for(i=1;i<=n;i++) F[i].clear();for(i=1;i<=n;i++) F[Getfa(i)].push_back(i);//printf("%d\n",cnt);
		for(i=1;i<=n;i++){
			W[i]=1e9;for(j=0;j<F[i].size();j++) now=F[i][j],G.erase((ques){A[now],now});
			for(j=0;j<F[i].size();j++){
				now=F[i][j];pus=G.lower_bound((ques){A[now]-d,0});
				if(pus!=G.end()) (*pus).w-A[now]+d<W[i]&&(W[i]=(*pus).w-A[now]+d,To[i]=(*pus).id,Fr[i]=now);
				if(pus!=G.begin())pus--,A[now]-d-(*pus).w<W[i]&&(W[i]=A[now]-d-(*pus).w,To[i]=(*pus).id,Fr[i]=now);
				pus=G.lower_bound((ques){A[now]+d,0});
				if(pus!=G.end()) (*pus).w-A[now]-d<W[i]&&(W[i]=(*pus).w-A[now]-d,To[i]=(*pus).id,Fr[i]=now);
				if(pus!=G.begin()) pus--,d+A[now]-(*pus).w<W[i]&&(W[i]=d+A[now]-(*pus).w,To[i]=(*pus).id,Fr[i]=now);
			}
			for(j=0;j<F[i].size();j++) now=F[i][j],G.insert((ques){A[now],now});
		}
		for(i=1;i<=n;i++){
			if(!F[i].size()) continue;/*printf("%d %d %d\n",Fr[i],To[i],W[i]);*/un=Getfa(Fr[i]);wn=Getfa(To[i]);un^wn&&(s.add(un,wn,W[i]),s.add(wn,un,W[i]),cnt--,fa[un]=wn);
		}
	}dfs(S,0);while(m--) scanf("%d%d",&x,&y),printf("%s\n",Ans[x]<=y?"Yes":"No");
}