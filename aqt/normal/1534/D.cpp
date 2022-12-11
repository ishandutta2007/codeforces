
// Problem : D. Lost Tree
// Contest : Codeforces - Codeforces LATOKEN Round 1 (Div. 1 + Div. 2)
// URL : https://codeforces.com/contest/1534/problem/D
// Memory Limit : 256 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;

vector<int> query(int n){
	cout << "? " << n << endl;
	vector<int> v;
	for(int i = 1; i <= N; i++){
		int k;
		cin >> k;
		v.emplace_back(k);
	}
	return v;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	vector<pair<int, int>> lst;
	auto v= query(1);
	int odd = 0;
	for(int i = 1; i <= N; i++){
		odd += v[i-1] % 2;
	}
	int parity = 1;
	if(N - odd - 1 < odd){
		parity = 0;
	}
	if(!parity){
		for(int i = 1; i <= N; i++){
			if(v[i-1] == 1){
				lst.emplace_back(1, i);
			}
		}
	}
	for(int i = 2; i <= N; i++){
		if(parity == v[i-1] % 2){
			auto t = query(i);
			for(int k = 1; k <= N; k++){
				if(t[k-1] == 1){
					int a = i, b = k;
					if(a > b){
						swap(a, b);
					}
					lst.emplace_back(a, b);
				}
			}
		}
	}
	cout << "!" << endl;
	for(auto e : lst){
		cout << e.first << " " << e.second << endl;
	}
}