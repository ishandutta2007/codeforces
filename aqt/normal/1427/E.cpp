
// Problem : E. Xum
// Contest : Codeforces - Codeforces Global Round 11
// URL : https://codeforces.com/contest/1427/problem/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

long long basis[65];
vector<pair<pair<long long, long long>, int>> ans;
set<long long> st;
mt19937 rando(chrono::steady_clock::now().time_since_epoch().count());
vector<long long> v;

void add(long long k){
	for(long long b = 60; b>=0; b--){
		if(k>>b&1){
			if(!basis[b]){
				basis[b] = k;
			}
			if(!st.count(basis[b]^k)){
				ans.push_back(make_pair(make_pair(basis[b], k), 1));
				st.insert(basis[b]^k);
				v.push_back(k^basis[b]);
			}
			k ^= basis[b];
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//for(int i = 3; i<=999999; i+=2){
		long long X;
		cin >> X;
		//X = i;
		long long crnt = X;	
		add(X);
		v.push_back(X);
		for(long long k = 1; k<20; k++){
			v.push_back(X<<k);
			ans.push_back(make_pair(make_pair(crnt, crnt), 0));
			crnt *= 2;
			st.insert(crnt);
			add(crnt);
		}
		while(ans.size() <= 100000 && !basis[0]){
			int a = uniform_int_distribution<int>(0, v.size()-1)(rando);
			int b = uniform_int_distribution<int>(0, v.size()-1)(rando);
			if(v[a]+v[b] <= 1000000000000000000LL){
				if(st.count(v[a]+v[b])){
					continue;
				}
				ans.push_back(make_pair(make_pair(v[a], v[b]), 0));
				v.push_back(v[a]+v[b]);
				st.insert(v[a]+v[b]);
				add(v[a]+v[b]);
			}
		}
		if(!basis[0]){
			while(1){}
		}
		//fill(basis, basis+65, 0);
		//v.clear();
		//ans.clear();
		cout << ans.size() << "\n";
		for(auto p : ans){
			if(p.second == 0){
				cout << p.first.first << " + " << p.first.second << "\n";
			}
			else{
				cout << p.first.first << " ^ " << p.first.second << "\n";
			}
		}
	//}
}