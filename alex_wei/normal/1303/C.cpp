#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t,vis[26];
int e[26][26];
string ans;
void dfs(int id){
	vis[id]=1; 
	ans+=id+'a';
	for(int i=0;i<26;i++)if(e[id][i]&&!vis[i])dfs(i);
}
string s;
int main(){
	cin>>t;
	while(t--){
		memset(vis,0,sizeof(vis));
		memset(e,0,sizeof(e));
		cin>>s;
		for(int i=1;i<s.size();i++){
			int u=s[i-1]-'a',v=s[i]-'a';
			e[u][v]=e[v][u]=1;
		}
		int deg[26];
		memset(deg,0,sizeof(deg));
		for(int i=0;i<26;i++)for(int j=0;j<26;j++)if(e[i][j])deg[i]++;
		int pd=0;
		for(int i=0;i<26;i++)if(deg[i]>2)pd=1;
		if(pd){
			puts("NO");
			continue;
		}
		ans="";
		for(int i=0;i<26;i++)if(deg[i]==1&&!vis[i])dfs(i);
		for(int i=0;i<26;i++)if(deg[i]&&ans.find(i+'a')==-1)pd=1;
		if(pd){
			puts("NO");
			continue;
		}
		for(int i=0;i<26;i++)if(!deg[i])ans+=i+'a';
		cout<<"YES\n"<<ans<<endl;
	}
	return 0;
}