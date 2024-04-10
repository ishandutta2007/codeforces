
// Problem : G. Subset with Zero Sum
// Contest : Good Bye 2019
// URL : https://codeforces.com/contest/1270/problem/G
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		int N;
		cin >> N;
		vector<int> nxt(N+1);
		for(int i = 1; i<=N; i++){
			cin >> nxt[i];
			nxt[i] = i - nxt[i];
		}
		int a = rand()%N+1;
		int b = a;
		do{
			a = nxt[a];
			b = nxt[nxt[b]];
		}
		while(a != b);
		vector<int> ans;
		do{
			ans.emplace_back(a);
			a = nxt[a];
		}
		while(a != b);
		cout << ans.size() << "\n";
		for(int n : ans){
			cout << n << " ";
		}
		cout << "\n";
	}
}