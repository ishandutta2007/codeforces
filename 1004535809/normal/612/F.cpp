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
	x=0;char c=getchar();T neg=1;
	while(!isdigit(c)){if(c=='-') neg=-1;c=getchar();}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	x*=neg;
}
const int MAXN=2000;
int n,x,a[MAXN+5],key[MAXN+5],hs[MAXN+5],num=0;
vector<int> pos[MAXN+5];
int dp[MAXN+5][MAXN+5];
int p[MAXN+5],pt=0;
int dist(int x,int y){return (y<x)?(n-x+y):(y-x);}
struct data{
	int a,b,c,d,dir;
	data(){}
	data(int _a,int _b,int _c,int _d,int _dir){a=_a;b=_b;c=_c;d=_d;dir=_dir;}
};
data pre[MAXN+5][MAXN+5];
void getmin(int x,int y,int z,data q){
	if(dp[x][y]>z) dp[x][y]=z,pre[x][y]=q;
}
void solve(int x,int y){
	memset(p,0,sizeof(p));
	pt=0;ffe(it,pos[x]) p[++pt]=*it;
	int pp=1;
	for(int i=1;i<=pt;i++) if(p[i]>y){pp=i;break;}
	int cur=pp,mx=dist(y,p[pp]),mxpl=y,mxpr=p[pp];
	for(int i=1;i<=pt;i++){
		getmin(x,p[cur],dp[x-1][y]+n+dist(y,p[cur])-(mx<<1),data(y,mxpl,mxpr,p[cur],1));
		if(cur==pt){if(dist(p[pt],p[1])>mx) mx=dist(p[pt],p[1]),mxpl=p[pt],mxpr=p[1];cur=1;}
		else{if(dist(p[cur],p[cur+1])>mx) mx=dist(p[cur],p[cur+1]),mxpl=p[cur],mxpr=p[cur+1];cur++;}
	}
	cur=pp-1;if(cur==0) cur=pt;mx=dist(p[cur],y),mxpl=y,mxpr=p[cur];
	for(int i=1;i<=pt;i++){
		getmin(x,p[cur],dp[x-1][y]+n+dist(p[cur],y)-(mx<<1),data(y,mxpl,mxpr,p[cur],-1));
		if(cur==1){if(dist(p[pt],p[1])>mx) mx=dist(p[pt],p[1]),mxpl=p[1],mxpr=p[pt];cur=pt;}
		else{if(dist(p[cur-1],p[cur])>mx) mx=dist(p[cur-1],p[cur]),mxpl=p[cur],mxpr=p[cur-1];cur--;}
	}
}
int now;
void findway(int x,int y){
	if(dp[x][y]==0) return;
	findway(x-1,pre[x][y].a);
	memset(p,0,sizeof(p));pt=0;
	ffe(it,pos[x]) p[++pt]=*it;
	vector<int> vv;int pp=1,cur;
	for(int i=1;i<=pt;i++) if(p[i]>pre[x][y].a){pp=i;break;}
	cur=pp;
	if(pre[x][y].b!=pre[x][y].a){
		if(pre[x][y].dir==1){
			while(p[cur]!=pre[x][y].b){
				vv.pb(p[cur]);cur++;if(cur>pt) cur=1;
			}
			vv.pb(pre[x][y].b);
		} else {
			cur--;if(cur==0) cur=pt;
			while(p[cur]!=pre[x][y].b){
				vv.pb(p[cur]);cur--;if(cur<=0) cur=pt;
			}
			vv.pb(pre[x][y].b);
		}
	}
	cur=pp;
	if(pre[x][y].dir==1){
		cur--;if(cur<=0) cur=pt;
	}
	if(pre[x][y].dir==1){
		while(p[cur]!=pre[x][y].c){
			vv.pb(p[cur]);cur--;if(cur<=0) cur=pt;
		} vv.pb(pre[x][y].c);
	} else {
		while(p[cur]!=pre[x][y].c){
			vv.pb(p[cur]);cur++;if(cur>pt) cur=1;
		} vv.pb(pre[x][y].c);
	}
//	printf("%d %d %d %d %d %d %d\n",x,y,pre[x][y].a,pre[x][y].b,pre[x][y].c,pre[x][y].d,pre[x][y].dir);
//	ffe(it,vv) printf("%d ",*it);printf("\n");
	ffe(it,vv){
		if(dist(now,*it)<=n-dist(now,*it)) printf("+%d\n",dist(now,*it));
		else printf("-%d\n",n-dist(now,*it));
		now=*it;
	}
}
int main(){
	scanf("%d%d",&n,&x);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),key[i]=a[i];
	sort(key+1,key+n+1);key[0]=-0x3f3f3f3f;
	for(int i=1;i<=n;i++) if(key[i]!=key[i-1]) hs[++num]=key[i];
	for(int i=1;i<=n;i++) a[i]=lower_bound(hs+1,hs+num+1,a[i])-hs;
	for(int i=1;i<=n;i++) if(i!=x||a[i]!=1) pos[a[i]].pb(i);
	memset(dp,63,sizeof(dp));
	if(!pos[1].empty()) dp[0][x]=0;
	else dp[1][x]=0;
	for(int i=1;i<=num;i++) for(int j=1;j<=n;j++){
		if(i!=1&&a[j]!=i-1) continue;
		if(i==1&&j!=x) continue;
		solve(i,j);
	}
//	for(int i=1;i<=num;i++) for(int j=1;j<=n;j++){
//		if(a[j]==i) printf("%d %d %d\n",i,j,dp[i][j]);
//	}
	int mn=0x3f3f3f3f,pp=0;
	for(int i=1;i<=n;i++) if(mn>dp[num][i]) mn=dp[num][i],pp=i;
	printf("%d\n",mn);
	if(a[x]==1) printf("+0\n");
	now=x;findway(num,pp);
	return 0;
}