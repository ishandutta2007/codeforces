#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

long long int count = 0;
int visited[100001];

vector<int> v[100001];
long long int e = 0;
void dfs(int x){
	for(auto i: v[x]){
		if(!visited[i]){
			//cout<<i<<" "<<endl;
			e += 1;
			visited[i] = 1;
			dfs(i);
		}
	}
}

int main(){
	long long int n,m,k,u,v1,s,t;
	cin>>n>>k;
	for(int i = 0 ;i<k; i++){
		cin>>u>>v1;
		s = min(v1,u);
		t = max(v1,u);
		//cout<<s<<t;
		v[u].push_back(v1);
		v[v1].push_back(u);
	}
	long long int ans=0;
	for(int i = 0 ;i<100001; i++){visited[i] = 0;}
	for(int i = 1 ;i<n+1; i++){
		if(!visited[i]){
			::count++;
			e = 0;
			visited[i] = 1;
			dfs(i);
			ans += e;
		}
	}

	cout<<k-ans<<endl;
}