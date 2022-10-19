#include<bits/stdc++.h>
using namespace std;
int n,S,cnt=1,lim,dfn[1001000],sz[1001000],res,num[1001000],len[1001000];
char s[1001000];
struct AC_Automaton{int fa,ch[26];}t[1001000];
vector<int>u[1001000],v[1001000]; 
void ins(int id){
	int x=1;
	for(int i=0;i<S;i++){
		if(!t[x].ch[s[i]-'a'])t[x].ch[s[i]-'a']=++cnt;
		u[id].push_back(x=t[x].ch[s[i]-'a']);
	}
	num[x]=x,len[x]=S;
}
queue<int>q;
void build(){
	for(int i=0;i<26;i++)
		if(t[1].ch[i])t[t[1].ch[i]].fa=1,q.push(t[1].ch[i]);
		else t[1].ch[i]=1;
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=0;i<26;i++)
			if(t[x].ch[i])t[t[x].ch[i]].fa=t[t[x].fa].ch[i],q.push(t[x].ch[i]);
			else t[x].ch[i]=t[t[x].fa].ch[i];
	}
}
void dfs(int x){dfn[x]=++lim,sz[x]=1;for(auto y:v[x]){if(!num[y])num[y]=num[x];dfs(y),sz[x]+=sz[y];}}
int stk[1001000],L[1001000],R[1001000],tp;
int bit[1001000],tot[1001000];
void ADD(int x,int y){while(x<=cnt)bit[x]+=y,x+=x&-x;}
int SUM(int x){int ret=0;while(x)ret+=bit[x],x-=x&-x;return ret;} 
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%s",s),S=strlen(s),ins(i);
	build();
	for(int i=2;i<=cnt;i++)v[t[i].fa].push_back(i);
	dfs(1);
//	for(int i=2;i<=cnt;i++)if(num[t[i].fa]!=num[i])printf("%d->%d\n",num[t[i].fa],num[i]);
	for(int i=1;i<=n;i++){
//		printf("%d:\n",i);
		for(auto x:u[i])ADD(dfn[x],1);
		for(int j=0,x;j<u[i].size();j++)if(x=num[(j+1==u[i].size())?t[u[i][j]].fa:u[i][j]]){
			int l=j-len[x]+1,r=j;
			while(tp&&L[tp]>=l)tot[stk[tp--]]--;
//			printf("[%d,%d]:%d\n",l,r,x);
			stk[++tp]=x,L[tp]=l,R[tp]=r,tot[x]++;
		}
//		for(int j=1;j<=tp;j++)printf("%d[%d,%d,%d]\n",stk[j],L[j],R[j],tot[stk[j]]);
		for(int j=1;j<=tp;j++){
			if(SUM(dfn[stk[j]]+sz[stk[j]]-1)-SUM(dfn[stk[j]]-1)==tot[stk[j]])res++;
			tot[stk[j]]=0;
		}
		tp=0;
		for(auto x:u[i])ADD(dfn[x],-1);
//		printf("RRR:%d\n",res);
	}
	printf("%d\n",res);
	return 0;
}
/*
5
ab
aba
bab
ababa
babab

6
ab
dab
cda
bcdab
cdabgh
abcdabghcda
*/