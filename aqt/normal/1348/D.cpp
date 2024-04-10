
// Problem : D. Phoenix and Science
// Contest : Codeforces - Codeforces Round #638 (Div. 2)
// URL : https://codeforces.com/contest/1348/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int T;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		int N;
		cin >> N;
		int cur = 1;
		vector<int> amt;
		amt.push_back(1);
		while(cur != N){
			if(1LL*cur + 2LL*((long long)(amt.back())<<1) > 1LL*N){
				int d = N - cur;
				if(d <= amt.back()<<1){
					amt.push_back(d);
					cur = N;
				}
				else{
					amt.push_back(d/2);
					cur += d/2;
					amt.push_back(N-cur);
					cur = N;
				}
			}
			else{
				cur += amt.back()<<1;
				amt.push_back(amt.back()<<1);
			}
		}
		cout << amt.size()-1 << "\n";
		for(int i = 1; i<amt.size(); i++){
			cout << amt[i] - amt[i-1] << " ";
		}
		cout << "\n";
	}
}