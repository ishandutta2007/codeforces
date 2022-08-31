#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
 
int main(){
	vector <pair<ll,ll>> v[100005];
	ll n,m,k,u,v1,d;
	ll visited[100005];
	cin>>n>>m>>k;
	pair <ll,ll>p;
	for(int i =0;i<m;i++){
		cin>>u>>v1>>d;
		p = make_pair(v1,d);
		v[u].push_back(p);
		p = make_pair(u,d);
		v[v1].push_back(p);
	}
	for(int i =0;i<k;i++){
		cin>>u;
		visited[u] = 1;
	}
	ll min = -1;
	for(int i = 1;i<=n;i++){
		if(visited[i] == 1){
			//cout<<"i"<<i<<endl;
			for(auto x : v[i]){
				if(visited[x.first] == 0){
					//cout<<x.second<<endl;
					d = x.second;
					if(d<min || min == -1) min = d;
				}
			}
		}
	}
	cout<<min;
}