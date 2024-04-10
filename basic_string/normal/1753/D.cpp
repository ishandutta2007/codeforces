#include<bits/stdc++.h>
using namespace std;
enum{N=300009};
using ll=long long;
string s[N];
int n,m,p,q;
ll d[N];
vector<pair<int,int>>v[N];
int id(int x,int y){
	return x*m+y;
}
void add(int a,int b,int c,int d,int e){
	if(a<0||a>=n||b<0||b>=m)return;
	if(s[a][b]=='#')return;
	v[id(a,b)].push_back({id(c,d),e});
}
priority_queue<pair<ll,int>>qu;
bool vis[N];
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int i,j,k;
	cin>>n>>m>>p>>q;
	for(i=0;i<n;++i){
		cin>>s[i];
	}
	for(i=0;i<n;++i)for(j=0;j<m;++j){
		if(s[i][j]=='L'){
			add(i,j-1,i,j+1,q);
			add(i,j+2,i,j,q);
			add(i-1,j,i,j+1,p);
			add(i+1,j,i,j+1,p);
			add(i-1,j+1,i,j,p);
			add(i+1,j+1,i,j,p); 
		}else if(s[i][j]=='U'){
			add(i-1,j,i+1,j,q);
			add(i+2,j,i,j,q);
			add(i,j-1,i+1,j,p);
			add(i,j+1,i+1,j,p);
			add(i+1,j-1,i,j,p);
			add(i+1,j+1,i,j,p);
		}
	}
	memset(d,9,sizeof d);
	for(i=0;i<n;++i)for(j=0;j<m;++j)if(s[i][j]=='.')
	d[id(i,j)]=0,qu.push({0,id(i,j)});
	while(qu.size()){
		i=qu.top().second,qu.pop();
		if(vis[i])continue;
		vis[i]=1;
		for(auto o:v[i]){
			if(d[o.first]>d[i]+o.second){
				d[o.first]=d[i]+o.second;
				qu.push({-d[o.first],o.first});
			}
		}
	}
	ll ans=1e18;
	for(i=0;i<n;++i)for(j=0;j<m;++j){
		if(i+1<n)ans=min(ans,d[id(i,j)]+d[id(i+1,j)]);
		if(j+1<m)ans=min(ans,d[id(i,j)]+d[id(i,j+1)]);
	}
	if(ans<ll(1e16))cout<<ans;else cout<<"-1";
}