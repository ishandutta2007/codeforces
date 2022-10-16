/*
	Powered by C++11.
	Author : Alex_Wei.
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb emplace_back

const int N=2e6+5;
const int S=26;

int las,cnt;
int son[N][S],len[N],fa[N],ed[N];
int buc[N],id[N],vis[N];
void ins(char s){
	int p=las,cur=++cnt,it=s-'a';
	len[cur]=len[p]+1,ed[cur]++,las=cur;
	while(p&&!son[p][it])son[p][it]=cur,p=fa[p];
	if(!p)return fa[cur]=1,void();
	int q=son[p][it];
	if(len[p]+1==len[q])return fa[cur]=q,void();
	int cl=++cnt;
	fa[cl]=fa[q],fa[q]=fa[cur]=cl,len[cl]=len[p]+1;
	memcpy(son[cl],son[q],sizeof(son[q]));
	while(son[p][it]==q)son[p][it]=cl,p=fa[p];
} void build(char *s){
	int n=strlen(s+1); las=cnt=1;
	for(int i=1;i<=n;i++)ins(s[i]);
	for(int i=1;i<=cnt;i++)buc[len[i]]++;
	for(int i=1;i<=cnt;i++)buc[i]+=buc[i-1];
	for(int i=cnt;i;i--)id[buc[len[i]]--]=i;
	for(int i=cnt;i;i--)ed[fa[id[i]]]+=ed[id[i]];
}

int n;
char s[N];
int main(){
	scanf("%s%d",s+1,&n),build(s);
	for(int i=1;i<=n;i++){
		scanf("%s",s+1);
		ll p=1,l=strlen(s+1),d=0,ans=0;
		vector <int> del; 
		for(int i=1;i<l*2;i++){
			int it=s[i>l?i-l:i]-'a';
			while(p&&!son[p][it])p=fa[p],d=len[p];
			if(p){
				p=son[p][it],d++;
				while(d>l)if((--d)<=len[fa[p]])p=fa[p];
				if(d>=l&&!vis[p])ans+=ed[p],vis[p]=1,del.pb(p);
			} else p=1;
		} cout<<ans<<endl;
		for(int it:del)vis[it]=0;
	}
	return 0;
}