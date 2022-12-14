#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 200 + 10;

string s[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t --){
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> s[i];
		if (s[0][1] == s[1][0]){
			int cnt = (s[n-1][n-2] == s[0][1]) + (s[n-2][n-1] == s[0][1]);
			cout << cnt << '\n';
			if (s[n-1][n-2] == s[0][1])
				cout << n << " " << n-1 << '\n';
			if (s[n-2][n-1] == s[0][1])
				cout << n-1 << " " << n << '\n';
		}
		else if (s[n-1][n-2] == s[n-2][n-1]){
			int cnt = (s[0][1] == s[n-1][n-2]) + (s[1][0] == s[n-1][n-2]);
			cout << cnt << '\n';
			if (s[0][1] == s[n-1][n-2])
				cout << 1 << " " << 2 << '\n';
			if (s[1][0] == s[n-1][n-2])
				cout << 2 << " " << 1 << '\n';
		}
		else{
			cout << 2 << '\n';
			cout << 1 << " " << 2 << '\n';
			if (s[n-1][n-2] != s[0][1])
				cout << n << " " << n-1 << '\n';
			else
				cout << n-1 << " " << n << '\n';
		}
	}
}