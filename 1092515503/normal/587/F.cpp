#include<bits/stdc++.h>
using namespace std;
const int BBB=316;
typedef long long ll;
int n,m,S,cnt=1;
struct AC_Automaton{int ch[26],fail;}t[100100];
vector<int>v[100100],u[100100];
char s[100100];
void ins(int id){
	for(int x=1,i=0;i<S;i++){
		if(!t[x].ch[s[i]-'a'])t[x].ch[s[i]-'a']=++cnt;
		v[id].push_back(x=t[x].ch[s[i]-'a']);
	}
}
int q[100100],l,r;
void build(){
	for(int i=0;i<26;i++){
		if(t[1].ch[i])t[q[r++]=t[1].ch[i]].fail=1;
		else t[1].ch[i]=1;
	}
	while(l!=r){
		int x=q[l++];
		u[t[x].fail].push_back(x);
		for(int i=0;i<26;i++)
			if(t[x].ch[i])t[q[r++]=t[x].ch[i]].fail=t[t[x].fail].ch[i];
			else t[x].ch[i]=t[t[x].fail].ch[i];
	}
}
int dfn[100100],sz[100100],rev[100100],tot;
void dfs(int x){dfn[x]=++tot,rev[tot]=x,sz[x]=1;for(auto y:u[x])dfs(y),sz[x]+=sz[y];}
ll res[100100],mus[100100];int ql[100100],qr[100100],qp[100100];
int sum[100100];
vector<int>w[100100];
void sfd(int x){for(auto y:u[x])sfd(y),sum[x]+=sum[y];}
void func(int id){
	for(auto x:v[id])sum[x]++;
	sfd(1);
	for(int i=1;i<=n;i++)mus[i]=mus[i-1]+sum[v[i].back()];
	for(auto i:w[id])res[i]=mus[qr[i]]-mus[ql[i]-1];
	memset(sum,0,sizeof(sum));
}
int BLK[100100],lp[100100],lim;

int tag[100100],TAG[100100];
void ADD(int l,int r){
//	printf("[%d,%d]\n",l,r);
	if(BLK[l]==BLK[r]){for(int i=l;i<=r;i++)tag[i]++;return;}
	for(int i=l;i<lp[BLK[l]+1];i++)tag[i]++;
	for(int i=lp[BLK[r]];i<=r;i++)tag[i]++;
	for(int i=BLK[l]+1;i<BLK[r];i++)TAG[i]++;
}
vector<int>z[100100];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%s",s),S=strlen(s),ins(i);
	build(),dfs(1);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&ql[i],&qr[i],&qp[i]);
		if(v[qp[i]].size()>BBB)w[qp[i]].push_back(i);
		else z[ql[i]-1].push_back(-i),z[qr[i]].push_back(i);
	}
	for(int i=1;i<=n;i++)if(v[i].size()>BBB)func(i);
	for(int i=1;i<=cnt;i++)BLK[i]=i/BBB;
	lp[lim=BLK[cnt+1]=BLK[cnt]+1]=cnt+1;
	for(int i=0;i<lim;i++)lp[i]=i*BBB;
	for(int i=1;i<=n;i++){
		ADD(dfn[v[i].back()],dfn[v[i].back()]+sz[v[i].back()]-1);
		for(auto x:z[i]){
			ll sm=0;
			for(auto y:v[qp[abs(x)]])sm+=tag[dfn[y]]+TAG[BLK[dfn[y]]];
			if(x<0)res[-x]-=sm;else res[x]+=sm;
		}
	}
	for(int i=1;i<=m;i++)printf("%lld\n",res[i]);
	return 0;
}