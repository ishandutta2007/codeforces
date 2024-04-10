#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define mt make_tuple
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long double ld;
namespace fastio{
	#define FILE_SIZE 1<<23
	char rbuf[FILE_SIZE],*p1=rbuf,*p2=rbuf,wbuf[FILE_SIZE],*p3=wbuf;
	inline char getc(){return p1==p2&&(p2=(p1=rbuf)+fread(rbuf,1,FILE_SIZE,stdin),p1==p2)?-1:*p1++;}
	inline void putc(char x){(*p3++=x);}
	template<typename T> void read(T &x){
		x=0;char c=getchar();T neg=0;
		while(!isdigit(c)) neg|=(c=='-'),c=getchar();
		while(isdigit(c)) x=(x<<3)+(x<<1)+(c^48),c=getchar();
		if(neg) x=-x;
	}
	template<typename T> void recursive_print(T x){
		if(!x) return;
		recursive_print(x/10);putc(x%10+'0');
	}
	template<typename T> void print(T x){
		if(!x) putc('0');if(x<0) putc('-'),x=-x;
		recursive_print(x);
	}
	template<typename T> void print(T x,char c){print(x);putc(c);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
template<typename Tv,int limN,int limM> struct link_list{
	int hd[limN+5],nxt[limM+5],item_n=0;Tv val[limM+5];
	void clear(){memset(hd,0,sizeof(hd));item_n=0;}//be aware of the TC of memset
	void ins(int x,Tv y){val[++item_n]=y;nxt[item_n]=hd[x];hd[x]=item_n;}
};
const int MAXN=2e5;
const ll INF=0x3f3f3f3f3f3f3f3fll;
int n,m=1,k,ban,cur=1,val[MAXN+5],fa[MAXN+5];
vector<pii> to[MAXN+5];
int cst[MAXN+5],asv[MAXN+5];
ll tag[MAXN+5];
map<int,ll> dp[MAXN+5];
multiset<ll> st[MAXN+5];
ll get(int x,int v){return (dp[x].count(v))?dp[x][v]:INF;}
void relax(int x){
	if(dp[x].count(ban)){
		st[x].erase(st[x].find(dp[x][ban]));
		dp[x][ban]=INF;st[x].insert(INF);
	}
}
void dfs(int x){
//	printf("dfs %d\n",x);
	dp[x][val[x]]=0;st[x].insert(0);relax(x);
	for(pii p:to[x]){
		int op=p.fi,id=p.se;
		if(op==1){
			ll v=min((*st[x].begin())+tag[x],INF);tag[x]+=cst[id];
			if(dp[x].count(asv[id])) st[x].erase(st[x].find(dp[x][asv[id]]));
			dp[x][asv[id]]=v-tag[x];st[x].insert(v-tag[x]);
		} else {
			dfs(id);ll nd=get(x,val[id])+tag[x];
			if(dp[x].size()>dp[id].size()){
				for(pair<int,ll> pp:dp[id]){
					int pos=pp.fi;ll v=pp.se+tag[id]+nd,ori=get(x,pos)+tag[x];chkmin(v,INF);
//					printf("%d %d %lld\n",id,pp.fi,v);
					if(dp[x].count(pos)) st[x].erase(st[x].find(dp[x][pos]));
					if(pos==val[id]) dp[x][pos]=v-tag[x];
					else dp[x][pos]=min(v,ori)-tag[x];
					st[x].insert(dp[x][pos]);
				}
			} else if(nd<INF) {
//				printf("%lld\n",nd);
				swap(dp[x],dp[id]);swap(st[x],st[id]);
				swap(tag[x],tag[id]);tag[x]+=nd;
				for(pair<int,ll> pp:dp[id]){
					int pos=pp.fi;ll v=min(pp.se+tag[id],INF);
					if(pos!=val[id]){
						chkmin(v,get(x,pos)+tag[x]);
						if(dp[x].count(pos)) st[x].erase(st[x].find(get(x,pos)));
						dp[x][pos]=v-tag[x];st[x].insert(dp[x][pos]);
					}
				}
			}
		} relax(x);
//		for(pair<int,ll> pp:dp[x]) printf("dp[%d][%d]=%lld\n",x,pp.fi,pp.se+tag[x]);
	}
}
int main(){
	scanf("%d%d",&n,&ban);val[1]=0;
	for(int i=1;i<=n;i++){
		static char buf[10];scanf("%s",buf+1);
		if(buf[1]=='s'){
			int x,v;scanf("%d%d",&x,&v);
			cst[++k]=v;asv[k]=x;to[cur].pb(mp(1,k));
		} else if(buf[1]=='i'){
			int x;scanf("%d",&x);val[++m]=x;
			to[cur].pb(mp(2,m));fa[m]=cur;cur=m;
		} else cur=fa[cur];
	}
//	for(int i=1;i<=m;i++) for(pii p:to[i])
//		printf("%d -> %d %d\n",i,p.fi,p.se);
	dfs(1);printf("%lld\n",(*st[1].begin())+tag[1]);
	return 0;
}
/*
19 1
set 1 2
set 1 10
if 0
end
set 1 8
if 1
set 0 9
set 0 10
if 1
if 0
end
end
set 1 7
set 1 7
set 1 9
set 0 5
set 1 8
set 1 2
end

5 1
set 1 100
if 1
set 1 1000
end
set 1 10000
*/