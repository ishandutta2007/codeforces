#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>
#include<utility>

using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,ans;
bool adj[30][30];
string s,t;
bool vis[30];
vector <int> list;
vector <P> mag;
void dfs(int v){
	vis[v] = true;
	list.push_back(v);
	for(int i=0;i<26;i++){
		if(!vis[i] && adj[v][i]) dfs(i);
	}
}
int main(){
	ios::sync_with_stdio(false);
	memset(vis,false,sizeof(vis));
	cin>>n;
	cin>>s>>t;
	for(int i=0;i<n;i++){
		if(s[i] != t[i]) adj[s[i]-'a'][t[i]-'a'] = adj[t[i]-'a'][s[i]-'a'] = true;
	}
	for(int i=0;i<26;i++){
		if(!vis[i]){
			list.clear();
			dfs(i);
			for(int i=0;i<list.size()-1;i++){
				mag.push_back(make_pair(list[i],list[i+1]));
			}
		} 
	}
	cout<<(int)mag.size()<<endl;
	for(int i=0;i<mag.size();i++){
		cout<<char(mag[i].first+'a')<<" "<<char(mag[i].second+'a')<<endl;
	}
	return 0;
}