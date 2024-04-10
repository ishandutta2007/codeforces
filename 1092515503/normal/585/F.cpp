#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int cnt=1;
struct AC_Automaton{
	int ch[10],fail;
	bool fin;
}t[51000];
void ins(char*u,char*v){
	int x=1;
	while(u!=v){
		if(!t[x].ch[*u-'0'])t[x].ch[*u-'0']=++cnt;
		x=t[x].ch[*u-'0'];
		u++;
	}
	t[x].fin=true;
}
queue<int>q;
void build(){
	for(int i=0;i<10;i++){
		if(t[1].ch[i])t[t[1].ch[i]].fail=1,q.push(t[1].ch[i]);
		else t[1].ch[i]=1;
	}
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=0;i<10;i++){
			int &y=t[x].ch[i],z=t[t[x].fail].ch[i];
			if(y)t[y].fail=z,t[y].fin|=t[z].fin,q.push(y);
			else y=z;
		}
	}
}
int f[100][51000];
char s[1010],ss[1010];
int S,T,hal,res;
int dfs(int pos,int x,bool lim,bool lead){
	if(!lim&&!lead&&f[pos][x]!=-1)return f[pos][x];
	if(t[x].fin){
		int res=0;
		for(int i=pos;i<T;i++)res=(10ll*res+(lim?ss[i]-'0':9))%mod;
		(++res)%=mod;
		if(!lim&&!lead)f[pos][x]=res;
//		printf("FIN:(%d,%d,%d,%d):%d\n",pos,x,lim,lead,res);
		return res;
	}
	if(pos==T)return 0;
	int res=0;
	for(int i=0;i<=(lim?ss[pos]-'0':9);i++)(res+=dfs(pos+1,(lead&&!i)?x:t[x].ch[i],lim&&(i==ss[pos]-'0'),lead&&!i))%=mod;
	if(!lim&&!lead)f[pos][x]=res;
//	printf("(%d,%d,%d,%d):%d\n",pos,x,lim,lead,res);
	return res;
}
int main(){
	scanf("%s",s),S=strlen(s);
	scanf("%s",ss),T=strlen(ss),hal=T>>1;
	for(int i=0;i+hal<=S;i++)ins(s+i,s+i+hal);
//	for(int i=1;i<=cnt;i++)for(int j=0;j<=9;j++)if(t[i].ch[j])printf("%d %d %d\n",i,t[i].ch[j],j);
//	puts("");
	build();
//	for(int i=1;i<=cnt;i++)for(int j=0;j<=2;j++)printf("%d %d %d\n",i,t[i].ch[j],j);
	for(int i=T-1;i>=0;i--)if(ss[i]=='0')ss[i]='9';else{ss[i]--;break;}
	memset(f,-1,sizeof(f));
	res=(mod-dfs(0,1,true,true))%mod;
	scanf("%s",ss);
	(res+=dfs(0,1,true,true))%=mod;
	printf("%d\n",res);
	return 0;
}