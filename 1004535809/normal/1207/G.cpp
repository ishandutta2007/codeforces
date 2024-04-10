#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fz(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define ffe(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define pb push_back
#define ppb pop_back
#define mp make_pair
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
typedef pair<int,int> pii;
typedef long long ll;
template<typename T> void read(T &x){
	char c=getchar();T neg=1;
	while(!isdigit(c)){if(c=='-') neg=-1;c=getchar();}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	x*=neg;
}
const int MAXN=4e5;
const int ALPHA=26;
int n,m,ed[MAXN+5];
int ch[MAXN*2+5][ALPHA+2],ncnt=0,fail[MAXN*2+5];
char buf[MAXN+5];
int insert(char *s){
	int len=strlen(s+1),cur=0;
	for(int i=1;i<=len;i++){
		if(!ch[cur][s[i]-'a']) ch[cur][s[i]-'a']=++ncnt;
		cur=ch[cur][s[i]-'a'];
	} return cur;
}
struct graph{
	int hd[MAXN*2+5],to[MAXN*2+5],nxt[MAXN*2+5],ec=0;
	void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
} t,f;
void getfail(){
	queue<int> q;
	for(int i=0;i<=ncnt;i++) for(int j=0;j<ALPHA;j++) if(ch[i][j]) t.adde(i,ch[i][j]);
	for(int i=0;i<ALPHA;i++) if(ch[0][i]) q.push(ch[0][i]);
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=0;i<ALPHA;i++){
			if(ch[x][i]) fail[ch[x][i]]=ch[fail[x]][i],q.push(ch[x][i]);
			else ch[x][i]=ch[fail[x]][i];
		}
	}
	for(int i=1;i<=ncnt;i++) f.adde(fail[i],i);
}
int bgt[MAXN*2+5],edt[MAXN*2+5],tim=0;
void dfsfail(int x){bgt[x]=++tim;for(int e=f.hd[x];e;e=f.nxt[e]) dfsfail(f.to[e]);edt[x]=tim;}
struct query{int x,y;} q[MAXN+5];
int ans[MAXN+5];vector<int> qv[MAXN*2+5];
struct fenwick_tree{
	int t[MAXN*2+5];
	void add(int x,int v){for(int i=x;i<=ncnt+1;i+=(i&(-i))) t[i]+=v;}
	int query(int x){int ret=0;for(int i=x;i;i-=(i&(-i))) ret+=t[i];return ret;}
	int query(int l,int r){return query(r)-query(l-1);}
} tr;
void dfsans(int x){
	tr.add(bgt[x],1);
	for(int e=t.hd[x];e;e=t.nxt[e]) dfsans(t.to[e]);
	ffe(it,qv[x]) ans[*it]=tr.query(bgt[q[*it].y],edt[q[*it].y]);
	tr.add(bgt[x],-1);
}
int main(){
	scanf("%d",&n);ed[0]=0;
	for(int i=1;i<=n;i++){
		int id,opt;scanf("%d",&opt);
		if(opt==1) scanf("%s",buf+1),id=0;
		else scanf("%d%s",&id,buf+1);
		int len=strlen(buf+1),cur=ed[id];
		for(int j=1;j<=len;j++){
			if(!ch[cur][buf[j]-'a']) ch[cur][buf[j]-'a']=++ncnt;
			cur=ch[cur][buf[j]-'a'];
		} ed[i]=cur;
//		printf("%d %d\n",i,cur);
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d%s",&q[i].x,buf+1);
		q[i].x=ed[q[i].x];q[i].y=insert(buf);
//		printf("%d %d\n",q[i].x,q[i].y);
	} getfail();dfsfail(0);
	for(int i=1;i<=m;i++) qv[q[i].x].pb(i);dfsans(0);
	for(int i=1;i<=m;i++) printf("%d\n",ans[i]);
	return 0;
}