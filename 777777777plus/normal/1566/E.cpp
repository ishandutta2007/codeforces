#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6+5;

int T,n;
vector<int> g[N];
bool ban[N],leaf[N];
vector<int> ans;

void dfs(int x,int f=-1){
	for(int i=0;i<g[x].size();++i)
	if(g[x][i]!=f){
		dfs(g[x][i],x);
	}
	leaf[x]=1;
	for(int i=0;i<g[x].size();++i)
	if(g[x][i]!=f&&!ban[g[x][i]]){
		leaf[x]=0;
	}
	if(leaf[x])return;
	bool can=1;
	for(int i=0;i<g[x].size();++i)
	if(g[x][i]!=f&&!ban[g[x][i]]&&!leaf[g[x][i]]){
		can=0;
	}
	if(can){
		int cnt=0;
		for(int i=0;i<g[x].size();++i)
		if(g[x][i]!=f&&!ban[g[x][i]]){
			++cnt;
		}
	//	cout<<x<<" "<<cnt<<endl;
		ans.push_back(cnt);
		ban[x]=1;
	}
}

int main(){
//	freopen("c.cpp","r",stdin);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;++i)g[i].clear(),ban[i]=leaf[i]=0;
		for(int i=1,x,y;i<n;++i){
			scanf("%d%d",&x,&y);
			g[x].push_back(y);
			g[y].push_back(x);
		}
		ans.clear();
		dfs(1);
		int cnt=0;
		for(int i=0;i<ans.size();++i)cnt+=ans[i];
		cnt-=ans.size()-1;
		cout<<cnt<<endl;
	}
}