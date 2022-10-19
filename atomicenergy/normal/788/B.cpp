#include <iostream>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

typedef long long ll;

bool connected(vector<vector<int>> G, ll z){
	vector<bool> seen;
	vector<int> next;
	for(int i=0; i<G.size(); i++){
		seen.push_back(false);
	}
	seen[z-1] = true;
	next.push_back(z-1);
	while(next.size()){
		ll x = next[next.size()-1];
		next.pop_back();
		for(int i=0; i<G[x].size(); i++){
			if(!seen[G[x][i]]){
				seen[G[x][i]] = true;
				next.push_back(G[x][i]);
			}
		}
	}
	for(int i=0; i<G.size(); i++){
		if(G[i].size()>0 && seen[i]==false) return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	ll n, e;
	cin >> n >> e;
	ll self = 0;
	vector<bool> s;
	vector<vector<int>> G;
	for(ll i=0; i<n; i++){
		vector<int> u;
		G.push_back(u);
		s.push_back(false);
	}
	ll x, y;
	ll z;
	for(ll i=0; i<e; i++){
		cin >> x >> y;
		z = x;
		if(x==y) {
			G[x-1].push_back(x-1);
			self++;
			s[x-1] = true;
		}
		else{
			G[x-1].push_back(y-1);
			G[y-1].push_back(x-1);
		} 
	}
	//cout << n;
	if(!connected(G, z)){
		cout << 0 << endl;
		return 0;
	}
	ll t = 0;
	t += self*(e-self);
	t += (self*(self-1))/2;
	for(int i=0; i<n; i++){
		ll m = G[i].size();
		if(s[i]) m--;
		t+=(m*(m-1))/2;
	}
	cout << t << endl;
	return 0;
}