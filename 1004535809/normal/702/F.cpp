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
const int MAXN=2e5+5;
int Rand(){return rand()<<15|rand();}
int n,m,ans[MAXN+5];
struct event{int c,q;} a[MAXN+5];
bool cmp(event x,event y){if(x.q!=y.q) return x.q>y.q;return x.c<y.c;}
struct node{
	int ch[2],id,val,key,cntlz,minlz,cnt;
} s[MAXN+5];
int ncnt=0,rt=0;
void pushdown(int k){
	if(s[k].minlz){
		if(s[k].ch[0]) s[s[k].ch[0]].minlz+=s[k].minlz,s[s[k].ch[0]].val-=s[k].minlz;
		if(s[k].ch[1]) s[s[k].ch[1]].minlz+=s[k].minlz,s[s[k].ch[1]].val-=s[k].minlz;
		s[k].minlz=0;
	} if(s[k].cntlz){
		if(s[k].ch[0]) s[s[k].ch[0]].cntlz+=s[k].cntlz,s[s[k].ch[0]].cnt+=s[k].cntlz;
		if(s[k].ch[1]) s[s[k].ch[1]].cntlz+=s[k].cntlz,s[s[k].ch[1]].cnt+=s[k].cntlz;
		s[k].cntlz=0;
	}
}
void split(int k,int val,int &a,int &b){
	if(!k){a=b=0;return;} pushdown(k);
	if(s[k].val<=val) a=k,split(s[k].ch[1],val,s[k].ch[1],b);
	else b=k,split(s[k].ch[0],val,a,s[k].ch[0]);
}
int merge(int x,int y){
	if(!x||!y) return x|y;pushdown(x);pushdown(y);
	if(s[x].key<s[y].key) return s[x].ch[1]=merge(s[x].ch[1],y),x;
	else return s[y].ch[0]=merge(x,s[y].ch[0]),y;
}
void dfsins(int x,int &y,int z){//insert all nodes in subtree x into subtree y, val-=z
	if(!x) return;pushdown(x);
	dfsins(s[x].ch[0],y,z);dfsins(s[x].ch[1],y,z);
	s[x].ch[0]=s[x].ch[1]=0;s[x].val-=z;s[x].cnt++;
	int k1,k2;split(y,s[x].val,k1,k2);y=merge(merge(k1,x),k2);
}
void insert(int x,int id){
	int k1,k2;split(rt,x,k1,k2);
	ncnt++;s[ncnt].id=id;s[ncnt].key=Rand();s[ncnt].val=x;
	rt=merge(merge(k1,ncnt),k2);
}
void dfscalc(int x){
	if(!x) return;pushdown(x);
	ans[s[x].id]=s[x].cnt;dfscalc(s[x].ch[0]);dfscalc(s[x].ch[1]);
}
int main(){
	srand(19260817);scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d",&a[i].c,&a[i].q);
	sort(a+1,a+n+1,cmp);scanf("%d",&m);
	for(int i=1;i<=m;i++){int x;scanf("%d",&x);insert(x,i);}
	for(int i=1;i<=n;i++){
		int k1,k2,k3;split(rt,a[i].c-1,k1,k2);split(k2,a[i].c<<1,k2,k3);
		if(k3){s[k3].val-=a[i].c;s[k3].cnt++;s[k3].minlz+=a[i].c;s[k3].cntlz++;}
		dfsins(k2,k1,a[i].c);rt=merge(k1,k3);
	}
	for(int i=1;i<=m;i++) ans[s[i].id]=s[i].cnt;
	dfscalc(rt);for(int i=1;i<=m;i++) printf("%d ",ans[i]);
	return 0;
}