
// Problem : E. Decryption
// Contest : Codeforces - Codeforces Round #671 (Div. 2)
// URL : https://codeforces.com/contest/1419/problem/E
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		int n, t;
		cin >> n;
		vector<int> f = {n};
		vector<int> pr;
		t = n;
		for(int i = 2; i<=sqrt(n); i++){
			if(n%i == 0){
				f.push_back(i);
				if(n/i != i){
					f.push_back(n/i);
				}
			}
			if(t%i == 0){
				pr.push_back(i);
				do{
					t/= i;
				}
				while(t%i == 0);
			}
		}
		if(t != 1){
			pr.push_back(t);
		}
		set<int> done;
		if(f.size() == 3 && pr.size() == 2){
			for(int n : f){
				cout << n << " ";
			}
			cout << "\n";
			cout << 1 << "\n";
			continue;
		}
		vector<int> ans;
		for(int i = 0; i<(pr.size() == 2 ? 1 : pr.size()); i++){
			ans.push_back(pr[i]);
			ans.push_back(pr[i] * pr[(i+1)%pr.size()]);
			done.insert(pr[i]);
			done.insert(pr[i] * pr[(i+1)%pr.size()]);
		}
		if(pr.size() == 2){
			ans.push_back(pr.back());
			done.insert(pr.back());
		}
		for(int n : f){
			if(done.count(n)){
				continue;
			}
			for(int p = pr.size()-1; p>=0; p--){
				if(n%pr[p] == 0){
					ans.insert(find(ans.begin(), ans.end(), pr[p])+1, n);
					break;
				}
			}
		}
		for(int n : ans){
			cout << n << " ";
		}
		for(int i = 0; i<ans.size(); i++){
			assert(__gcd(ans[i], ans[(i+1)%ans.size()]) != 1);
		}
		cout << "\n" << 0 << "\n";
	}
}