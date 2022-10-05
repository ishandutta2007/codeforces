#include<bits/stdc++.h>
using namespace std;
const int N=1e6+3;
string s;
queue<int>q;
basic_string<int>v[N],g[N];
int id,t[N],l[N],r[N],c[N][26],f[N],e[N],len[N],st[N],tp,b[N],e2[N],ed[N];
void dfs(int x){
	l[x]=++id;
	for(int i:g[x])dfs(i);
	r[x]=id;
}
void add(int x,int y){for(x=l[x];x<=id;x+=x&-x)t[x]+=y;}
int sum(int x){int r=0;for(;x;x-=x&-x)r+=t[x];return r;}
int get(int x){return sum(r[x])-sum(l[x]-1);}
int main(){
	int n,i,j,x,id=0,ans=0;
	ios::sync_with_stdio(0),cin.tie(0),cin>>n;
	for(i=1;i<=n;++i){
		cin>>s,x=0;
		for(char o:s){
			if(j=o-'a',!c[x][j])c[x][j]=++id;
			x=c[x][j],v[i]+=x;
		}
		e2[x]=ed[i]=x,len[x]=s.size();
	}
	for(i=0;i<26;++i)if(c[0][i])q.push(c[0][i]);
	while(q.size()){
		if(i=q.front(),q.pop(),x=f[i])e[i]=e2[x]?e2[x]:e[x];
		for(j=0;j<26;++j)if(c[i][j])q.push(c[i][j]),f[c[i][j]]=c[x][j];else c[i][j]=c[x][j];
	}
	for(i=1;i<=id;++i)g[f[i]]+=i;
	for(dfs(0),i=1;i<=n;++i){
		x=0;
		for(auto o=v[i].rbegin();o!=v[i].rend();++o){
			if(e2[*o])j=e2[*o]==ed[i]?e[*o]:e2[*o];else j=e[*o];
			if(--x,!j)continue;
			if(!b[j])b[j]=1,st[++tp]=j,add(j,1);
			if(len[j]<=x)b[j]=-1;else x=len[j];
		}
		for(j=1;j<=tp;++j)if(b[x=st[j]]==1&&get(x)==1)++ans;
		for(j=1;j<=tp;++j)b[x=st[j]]=0,add(x,-1);
		tp=0;
	}
	cout<<ans;
	return 0;
}