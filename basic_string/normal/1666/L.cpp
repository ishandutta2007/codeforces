#include<bits/stdc++.h>
using namespace std;
enum{N=200009};
int n,m,s,p[N],q[N];
basic_string<int>g[N];
void dfs(int x,int y,int z){
	if(x==s&&y)return;
	if(p[x]&&q[x]==z)return;
	if(p[x]){
		cout<<"Possible"<<'\n';
		vector<int>v;
		int w=x;
		v.push_back(x);
		while(x!=s)x=p[x],v.push_back(x);
		cout<<v.size()<<'\n';
		reverse(begin(v),end(v));for(auto o:v)cout<<o<<' ';cout<<'\n';
		v={},v.push_back(w),v.push_back(y),x=y;
		while(x!=s)x=p[x],v.push_back(x);
		cout<<v.size()<<'\n';
		reverse(begin(v),end(v));for(auto o:v)cout<<o<<' ';cout<<'\n';
		exit(0);
	}
	p[x]=y,q[x]=z;
	if(!z)for(int i:g[x])dfs(i,x,i);
	else for(int i:g[x])dfs(i,x,z);
}
int main(){ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m>>s;
	int i,j;
	while(m--)cin>>i>>j,g[i]+=j;
	dfs(s,0,0);
	cout<<"Impossible";
}