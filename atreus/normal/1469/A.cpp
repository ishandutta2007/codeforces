#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll maxn = 1e6 + 10;
const ll mod = 1e9 + 7;

int main(){
	ios_base::sync_with_stdio(false);
	int tc;
	cin >> tc;
	while (tc --){
		string s;
		cin >> s;
		int n = s.size();
		if (n & 1){
			cout << "NO\n";
			continue;
		}
		if (s[0] == ')' or s[n-1] == '(')
			cout << "NO\n";
		else
			cout << "YES\n";
	}
}