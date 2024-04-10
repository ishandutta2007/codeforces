
// Problem : A. Omkar and Bad Story
// Contest : Codeforces - Codeforces Round #724 (Div. 2)
// URL : https://codeforces.com/contest/1536/problem/A
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int T;
int N;


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		cin >> N;
		vector<int> v;
		bool neg = 0;
		for(int i = 1; i <= N; i++){
			int n;
			cin >> n;
			if(n < 0){
				neg = 1;
			}
			v.push_back(n);
		}
		if(neg){
			cout << "No\n";
		}
		else{
			for(int i = 0; i <= 200; i++){
				if(find(v.begin(), v.end(), i) == v.end()){
					v.emplace_back(i);
				}
			}
			cout << "Yes\n";
			cout << v.size() << "\n";
			for(int n : v){
				cout << n << " ";
			}
			cout << "\n";
		}
	}
}