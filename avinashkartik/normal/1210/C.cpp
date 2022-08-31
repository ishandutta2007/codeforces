#include<bits/stdc++.h>
#include<algorithm>
#define mod 1000000007;
using namespace std;

int visited[100005]={};

vector<int> v[100005];
long long int gcd[100005];
unordered_map<long long int ,long long int> m[100005];
long long int sum = 0,s;

void dfs(int x){
	for(auto i: v[x]){
		if(!visited[i]){
			m[i][gcd[i]]++;
			for(auto v1 : m[x]){
				//cout<<v1.first<<endl;
				::s = __gcd(gcd[i],v1.first);
				m[i][::s] += v1.second;
			}
			for(auto v1 : m[i]){
				//cout<<x<<" "<<v1.first<<" "<<v1.second<<endl;
				::sum = (sum + v1.first*v1.second)%mod;
			}
			visited[i] = 1;
			dfs(i);
		}
	}
}

int main(){
	int n,k,u,v1;

	cin>>n;

	for(int i = 1 ;i<=n; i++){ cin>>gcd[i]; }

	for(int i = 1 ;i<n; i++){
		cin>>u>>v1;
		v[u].push_back(v1);
		v[v1].push_back(u);
	}

	int flag;
	m[1][gcd[1]]++;
	::sum += gcd[1];
	visited[1] = 1;
	dfs(1);
	::sum = ::sum % mod;
	cout<<(::sum)<<endl;
}