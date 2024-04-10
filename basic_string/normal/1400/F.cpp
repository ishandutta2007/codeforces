#include<bits/stdc++.h>
using namespace std;
const int N=5009;
string s;
int m,c[N][9],f[N],id,u[N],v[N];
bool e[N];
queue<int>q;
void ins(const string&s){
	int x=0;
	for(char i:s){
		if(!c[x][--i])c[x][i]=++id;
		x=c[x][i];
	}
	e[x]=1;
}
void dfs(int x,const string&s){
	if(!x)return ins(s);
	for(int i=1;i<=9;++i)if(i<=x&&(m%i||m==i)){
		int j=i,l=s.size(),k=l-1;
		for(;~k;--k)if(j+=s[k],m%j==0&&j<m)goto gg;
		dfs(x-i,s+char(i));
		gg:;
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin>>s>>m,dfs(m,"");
	int i,j,k;
	for(i=0;i<9;++i)if(c[0][i])q.push(c[0][i]);
	while(q.size()){
		i=q.front(),q.pop(),k=f[i],e[i]|=e[k];
		for(j=0;j<9;++j)if(c[i][j])q.push(c[i][j]),f[c[i][j]]=c[k][j];
		else c[i][j]=c[k][j];
	}
	memset(u,9,sizeof u),u[0]=0;
	for(char o:s){
		memcpy(v,u,sizeof v),memset(u,9,sizeof u),j=o-'1';
		for(i=0;i<=id;++i)if(!e[i]&&v[i]<N)u[i]=min(u[i],v[i]+1),k=c[i][j],u[k]=min(u[k],v[i]);
	}
	for(i=0,j=N;i<=id;++i)if(!e[i])j=min(j,u[i]);
	cout<<j;
	return 0;
}