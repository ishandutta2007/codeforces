#include<bits/stdc++.h>
using namespace std;
enum{N=200009};
basic_string<int>g[N];
vector<pair<int,int>>ans;
int w[N];
void dfs(int x,int y){
	basic_string<int>v0,v1;
	for(int i:g[x])if(i^y){
		dfs(i,x);
		if(w[i])v1+=i;else v0+=i;
	}
	if(v0.size()==v1.size()||v0.size()==v1.size()-1){
		while(v1.size())if(v0.size()==v1.size())ans.push_back({x,v0.back()}),v0.pop_back();
		else ans.push_back({x,v1.back()}),ans.push_back({v1.back(),w[v1.back()]}),v1.pop_back();
		w[x]=0;
	}else if(v0.size()==v1.size()+1||v0.size()==v1.size()+2){
		while(v0.size()>1)if(v0.size()==v1.size()+2)ans.push_back({x,v0.back()}),v0.pop_back();
		else ans.push_back({x,v1.back()}),ans.push_back({v1.back(),w[v1.back()]}),v1.pop_back();
		w[x]=v0.back();
	}else throw 1;
}
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int T,n,i,j,k;
	for(cin>>T;T--;){
		cin>>n,ans={};
		for(i=1;i<=n;++i)g[i]={};
		for(i=1;i<n;++i)cin>>j>>k,g[j]+=k,g[k]+=j;
		for(i=1;;++i)if(g[i].size()==1)break;
		try{
			dfs(i,0);
			if(!w[i])throw 1;
		}catch(...){cout<<"NO\n";continue;}
		cout<<"YES\n",ans.push_back({i,w[i]});
		for(auto o:ans)cout<<o.first<<' '<<o.second<<'\n';
	}
}