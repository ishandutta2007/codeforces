
// Problem : C. Jzzhu and Apples
// Contest : Codeforces - Codeforces Round #257 (Div. 1)
// URL : https://codeforces.com/problemset/problem/449/C
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
bool sieve[100005];
vector<pair<int, int>> ans;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 3; i<=N/2; i+=2){
		if(sieve[i]){
			continue;
		}
		int cnt = 0;
		for(int j = i; j<=N; j+=i){
			cnt += !sieve[j];
		}
		vector<int> v;
		if(cnt&1){
			v.push_back(i);
			for(int j = 3*i; j<=N; j+=i){
				if(!sieve[j]){
					sieve[j] = 1;
					v.push_back(j);
				}
			}
		}
		else{
			for(int j = i; j<=N; j+=i){
				if(!sieve[j]){
					sieve[j] = 1;
					v.push_back(j);
				}
			}
		}
		for(int k = 0; k<v.size(); k+=2){
			ans.emplace_back(v[k], v[k+1]);
		}
	}
	vector<int> v;
	for(int i = 2; i<=N; i+=2){
		if(!sieve[i]){
			v.push_back(i);
		}
	}
	for(int i = 1; i<v.size(); i+=2){
		ans.emplace_back(v[i-1], v[i]);
	}
	cout << ans.size() << "\n";
	for(auto p : ans){
		cout << p.first << " " << p.second << "\n";
	}
}