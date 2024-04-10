//#pragma comment(linker,"/stack:200000000")
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
		while(!isdigit(c)) neg|=!(c^'-'),c=getchar();
		while(isdigit(c)) x=(x<<3)+(x<<1)+(c^48),c=getchar();
		if(neg) x=(~x)+1;
	}
	template<typename T> void recursive_print(T x){return (!x)?void():(recursive_print(x/10),putc(x%10^48),void());}
	template<typename T> void print(T x){(!x)&&(putc('0'),0);(x<0)&&(putc('-'),x=~x+1);recursive_print(x);}
	template<typename T> void print(T x,char c){(!x)&&(putc('0'),0);(x<0)&&(putc('-'),x=~x+1);recursive_print(x);putc(c);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const int MAXN=300;
const int MAXV=1000;
const int MAXE=2e5;
const int INF=0x3f3f3f3f; 
int n,m,a[MAXN+5],b[MAXN+5];
int parse(string s){
	if(s=="?") return -1;int x=0;
	for(int i=0;i<s.size();i++) x=x*10+s[i]-'0';
	return x;
}
int cnt[MAXN+5][MAXN+5],mx[MAXN+5],id[MAXN+5][MAXN+5],has[MAXN+5];
int S=999,T=1000,hd[MAXV+5],to[MAXE+5],nxt[MAXE+5],cap[MAXE+5],ec=1;
void adde(int u,int v,int f){
//	printf("%d %d %d\n",u,v,f);
	to[++ec]=v;cap[ec]=f;nxt[ec]=hd[u];hd[u]=ec;
	to[++ec]=u;cap[ec]=0;nxt[ec]=hd[v];hd[v]=ec;
} int dep[MAXV+5],now[MAXV+5];
bool getdep(){
	memset(dep,-1,sizeof(dep));dep[S]=0;
	queue<int> q;q.push(S);now[S]=hd[S];
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int e=hd[x];e;e=nxt[e]){
			int y=to[e],z=cap[e];
			if(z&&!~dep[y]){
				dep[y]=dep[x]+1;
				now[y]=hd[y];q.push(y);
			}
		}
	} return ~dep[T];
}
int getflow(int x,int f){
	if(x==T) return f;int ret=0;
	for(int &e=now[x];e;e=nxt[e]){
		int y=to[e],z=cap[e];
		if(dep[y]==dep[x]+1&&z){
			int w=getflow(y,min(f-ret,z));
			cap[e]-=w;cap[e^1]+=w;ret+=w;
			if(ret==f) return ret;
		}
	} return ret;
}
int dinic(){
	int res=0;
	while(getdep()) res+=getflow(S,INF);
	return res;
}
bool check(){
	memset(cnt,0,sizeof(cnt));memset(mx,0,sizeof(mx));
	memset(has,0,sizeof(has));memset(id,0,sizeof(id));
	memset(hd,0,sizeof(hd));ec=1;int sum=0;m=0;
	for(int i=1;i<=n;i++) if(~a[i]&&~b[i]){
		cnt[a[i]][b[i]]++;
		chkmax(mx[b[i]],a[i]);
	} for(int i=1;i<=n;i++) adde(S,i,1);
	for(int i=1;i<=n;i++) if(~b[i]) has[b[i]]=1;
//	for(int i=1;i<=n;i++) printf("%d%c",mx[i]," \n"[i==n]);
	for(int i=1;i<=n;i++) if(mx[i]||cnt[0][i]||has[i]){
		int need=(cnt[0][i]+i-1)/i*i;
		if(!need) need=i;
		if(need^cnt[0][i]){
			if((id[0][i]=++m)>n) return 0;
//			printf("id[0][%d]=%d\n",i,m);
			adde(m+n,T,need-cnt[0][i]);
			sum+=need-cnt[0][i];
//			printf("%d %d\n",i,need-cnt[0][i]);
		}
		for(int j=1;j<=mx[i];j++) if(!cnt[j][i]){
			if((id[j][i]=++m)>n) return 0;
//			printf("id[%d][%d]=%d\n",j,i,m);
			adde(m+n,T,1);sum++;
		}
	}
	if(sum>n) return 0;
	for(int i=1;i<=n;i++){
		if(~a[i]&&~b[i]) continue;
		else if(~a[i]){
//			printf("%d\n",i);
			for(int j=1;j<=n;j++) if(id[a[i]][j])
				adde(i,id[a[i]][j]+n,1);
		} else if(~b[i]){
//			printf("%d\n",i);
			for(int j=0;j<=n;j++) if(id[j][b[i]])
				adde(i,id[j][b[i]]+n,1);
		} else {
			for(int j=1;j<=m;j++) adde(i,j+n,1);
//			printf("%d\n",i);
		}
	} return (dinic()==sum);
}
void work(){
	for(int i=0;i<=n;i++) for(int j=1;j<=n;j++){
		if(id[i][j]){
			int k=id[i][j];
//			printf("%d %d %d\n",i,j,k);
			for(int e=hd[k+n];e;e=nxt[e]){
//				printf("%d\n",e);
				if(to[e]!=T&&cap[e]){
					int x=to[e];
//					printf("x=%d %d %d\n",x,a[x],b[x]);
					assert(!~a[x]||a[x]==i);
					assert(!~b[x]||b[x]==j);
					a[x]=i;b[x]=j;
//					printf("%d %d\n",a[x],b[x]);
				}
			}
		}
	}
	for(int i=1;i<=n;i++) if(!~a[i]||!~b[i]){
		if(!~a[i]&&!~b[i]) a[i]=0,b[i]=1;
		else if(!~a[i]) a[i]=1;
		else{
			if(!a[i]) b[i]=1;
			else{
				for(int j=1;j<=n;j++) if(mx[j]>=a[i])
					b[i]=j;
			}
		}
	}
//	for(int i=1;i<=n;i++) printf("%d %d\n",a[i],b[i]);
}
vector<int> vec[MAXN+5];
int ans[MAXN+5];
void makegraph(){
	for(int i=1;i<=n;i++) if(!a[i]) vec[b[i]].pb(i);
	for(int i=1;i<=n;i++) if(!vec[i].empty()){
		assert(vec[i].size()%i==0);
		for(int j=0;j<vec[i].size();j+=i){
			for(int k=j;k<j+i-1;k++) ans[vec[i][k]]=vec[i][k+1];
			ans[vec[i][j+i-1]]=vec[i][j];
		}
	}
	for(int i=1;i<=n;i++) if(a[i])
		for(int j=1;j<=n;j++) if(a[j]==a[i]-1&&b[j]==b[i]){
			ans[i]=j;
		}
	for(int i=1;i<=n;i++) printf("%d%c",ans[i]," \n"[i==n]);
}
int main(){
	scanf("%d",&n);int mx=0;
	for(int i=1;i<=n;i++){
		string s,t;cin>>s>>t;
		a[i]=parse(s);b[i]=parse(t);
		if(~a[i]&&!~b[i])
			if(a[i]>a[mx]) mx=i;
	}
	for(int i=1;i<=n;i++){
//		printf("check %d\n",i);
		if(mx) b[mx]=i;
		if(check()) return work(),makegraph(),0;
		if(mx) b[mx]=-1;
	} puts("-1");
	return 0;
}