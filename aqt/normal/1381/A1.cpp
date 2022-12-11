
// Problem : A2. Prefix Flip (Hard Version)
// Contest : Codeforces - Codeforces Round #658 (Div. 1)
// URL : https://codeforces.com/contest/1381/problem/A2
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
		int N;
		cin >> N;
		vector<int> a, b;
		for(int n = 0; n<N; n++){
			char c;
			cin >> c;
			a.push_back(c-'0');
		}
		for(int n = 0; n<N; n++){
			char c;
			cin >> c;
			b.push_back(c-'0');
		}
		vector<int> ans;
		for(int n = N-1; n>=0; n--){
			if(a[n] == b[n]){
				continue;
			}
			else if(a[0] != b[n]){
				ans.push_back(n+1);
				reverse(a.begin(), a.begin()+n+1);
				for(int k = 0; k<=n; k++){
					a[k] ^= 1;
				}
			}
			else {
				ans.push_back(1);
				a[0] ^= 1;
				ans.push_back(n+1);
				reverse(a.begin(), a.begin()+n+1);
				for(int k = 0; k<=n; k++){
					a[k] ^= 1;
				}
			}
		}
		cout << ans.size() << " ";
		for(int n : ans){
			cout << n << " ";
		}
		cout << "\n";
		
	}
}