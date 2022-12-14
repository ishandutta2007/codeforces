#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
const int mod = 1e9 + 7;

int main(){
	ios_base::sync_with_stdio(false);
	int tc;
	cin >> tc;
	while (tc--){
		int n;
		string s;
		cin >> n >> s;
		int cnt = 0;
		for (int i = 0; i < n; i++)
			if (s[i] == '0')
				cnt++;
		if ((cnt&1) or s[0] == '0' or s[n-1] == '0'){
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		string A, B;
		bool a = 1;
		int Q = (n - cnt)/2;
		for (int i = 0; i < n; i++){
			if (s[i] == '0'){
				if (a){
					A += '(';
					B += ')';
				}
				else{
					A += ')';
					B += '(';
				}
				a ^= 1;
			}
			else{
				if (Q > 0) {
					A += '(';
					B += '(';
				}
				else {
					A += ')';
					B += ')';
				}
				Q --;
			}
		}
		cout << A << '\n' << B << '\n';
	}
}