/*
	Powered by C++11.
	Author : Alex_Wei.
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mem(x,v) memset(x,v,sizeof(x))

const int N=2e5+5;
const int S=26;

int cnt,las,son[N][S],ed[N],fa[N],len[N],buc[N],id[N];
void clear(){
	mem(son,0),mem(ed,0),mem(fa,0),mem(len,0),mem(buc,0);
	cnt=las=1;
} void ins(char s){
	int p=las,cur=++cnt,it=s-'a';
	len[cur]=len[p]+1,las=cur,ed[cur]=1;
	while(!son[p][it])son[p][it]=cur,p=fa[p];
	if(!p)return fa[cur]=1,void();
	int q=son[p][it];
	if(len[p]+1==len[q])return fa[cur]=q,void();
	int cl=++cnt;
	fa[cl]=fa[q],fa[q]=fa[cur]=cl,len[cl]=len[p]+1;
	memcpy(son[cl],son[q],sizeof(son[q]));
	while(son[p][it]==q)son[p][it]=cl,p=fa[p];
} ll build(char *s){
	int n=strlen(s+1); clear();
	for(int i=1;i<=n;i++)ins(s[i]);
	for(int i=1;i<=cnt;i++)buc[len[i]]++;
	for(int i=1;i<=n;i++)buc[i]+=buc[i-1];
	for(int i=cnt;i;i--)id[buc[len[i]]--]=i;
	for(int i=cnt;i;i--)ed[fa[id[i]]]+=ed[id[i]];
	ll ans=0;
	for(int i=1;i<=cnt;i++)ans+=1ll*ed[i]*ed[i]*(len[i]-len[fa[i]]);
	return ans;
}

int n;
char s[N];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%s",s+1),cout<<build(s)<<endl; 
	return 0;
}