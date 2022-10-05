#include<bits/stdc++.h>
using namespace std;
const int N=2e5+3;
int n,k,l[N],r[N];
char s[N],s2[N];
int p[N],ip[N],id;
bool sm[N],ans[N];
int d[N];
void dfs1(int x){
	if(!x)return;
	dfs1(l[x]);
	p[x]=++id,ip[id]=x;
	dfs1(r[x]);
}
void dfs2(int x){
	if(!x)return;
	if(sm[x])d[x]=1;
	dfs2(l[x]),dfs2(r[x]);
	d[x]=min(d[x],d[l[x]]+1);
}
void dfs3(int x){
	if(!x)return;
	if(d[x]>k)return;
	ans[x]=1,--k;
	dfs3(l[x]),dfs3(r[x]);
}
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int i;
	char la=0;
	cin>>n>>k>>s+1;
	for(i=1;i<=n;++i)cin>>l[i]>>r[i];
	dfs1(1);
	for(i=1;i<=n;++i)s2[i]=s[ip[i]];
	for(i=n;i;--i){
		if(s2[i]<la)sm[ip[i]]=1;
		if(s2[i]!=s2[i-1])la=s2[i];
	}
	memset(d,9,sizeof d);
	dfs2(1);dfs3(1);
	for(i=1;i<=n;++i)if(cout<<s2[i],ans[ip[i]])cout<<s2[i];
	return 0;
}