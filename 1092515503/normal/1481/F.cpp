#include<bits/stdc++.h>
using namespace std;
int n,m,dep[100100],sz[100100],lim,f[450][100100],num[100100],col[100100];
vector<int>v[100100],w;
void dfs(int x){
	sz[dep[x]]++,lim=max(lim,dep[x]);
	for(auto y:v[x])dep[y]=dep[x]+1,dfs(y);
}
vector<int>u[100100],t[100100];
char s[100100];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=2,x;i<=n;i++)scanf("%d",&x),v[x].push_back(i);
	dep[1]=1,dfs(1);
	for(int i=1;i<=lim;i++)num[sz[i]]++;
//	for(int i=1;i<=n;i++)printf("%d:%d\n",i,num[i]);
	for(int i=1;i<=n;i++)if(num[i])w.push_back(i);
	memset(f,-1,sizeof(f)),f[0][0]=0;
	for(int i=0;i<w.size();i++)for(int j=0;j<w[i];j++)for(int k=j,p=0xc0c0c0c0;k<=n;k+=w[i]){
		if(f[i][k]!=-1)p=k;
		if(k-p<=w[i]*num[w[i]])f[i+1][k]=(k-p)/w[i];else f[i+1][k]=-1;
	}
	if(f[w.size()][m]!=-1){
		for(int i=w.size(),j=m;i;i--)
			num[w[i-1]]=f[i][j],
			j-=f[i][j]*w[i-1];
		for(int i=1;i<=lim;i++)if(num[sz[i]])col[i]=1,num[sz[i]]--;
		printf("%d\n",lim);
		for(int i=1;i<=n;i++)putchar(col[dep[i]]?'a':'b');
		return 0;
	}
	for(int i=1;i<=n;i++)if(v[i].empty())t[dep[i]].push_back(i);else u[dep[i]].push_back(i);
	int A=m,B=n-m;
	for(int i=1;i<=lim;i++){
		if(A>=B){
			for(auto x:u[i])s[x]='a';A-=u[i].size();
			for(auto x:t[i])if(A)s[x]='a',A--;else s[x]='b',B--;
		}else{
			for(auto x:u[i])s[x]='b';B-=u[i].size();
			for(auto x:t[i])if(B)s[x]='b',B--;else s[x]='a',A--;
		}
	}
	printf("%d\n%s\n",lim+1,s+1);
	return 0;
}