#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int T;
string s;
vector<int>g[26],ans;

void dfs(int x,int f=-1){
	ans.push_back(x);
	for(int i=0;i<g[x].size();++i)
	if(g[x][i]!=f){
		int y=g[x][i];
		dfs(y,x);
	}
}

int main(){
	cin>>T;
	while(T--){
		cin>>s;
		int n=s.size();
		if(n==1){
			cout<<"YES"<<endl;
			for(int i=0;i<26;++i)cout<<char(i+'a');
			cout<<endl;
			continue;
		}
		ans.clear();
		for(int i=0;i<26;++i)g[i].clear();
		for(int i=0;i<n;++i)s[i]-='a';
		for(int i=0;i<n-1;++i){
			g[s[i]].push_back(s[i+1]);
			g[s[i+1]].push_back(s[i]);
		}
		for(int i=0;i<26;++i){
			sort(g[i].begin(),g[i].end());
			g[i].erase(unique(g[i].begin(),g[i].end()),g[i].end());
		}
		vector<int>p;
		bool flag=1;
		for(int i=0;i<26;++i)
		if(g[i].size()==1){
			p.push_back(i);
		}
		else if(g[i].size()>2){
			flag=0;
		}
		if(!flag||p.size()!=2){
			cout<<"NO"<<endl;
			continue;
		}
		cout<<"YES"<<endl;
		dfs(p[0]);
		for(int i=0;i<26;++i)
		if(!g[i].size()){
			ans.push_back(i);
		}
		for(int i=0;i<26;++i)cout<<char(ans[i]+'a');
		cout<<endl;
	}
}