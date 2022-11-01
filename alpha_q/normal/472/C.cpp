#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int P[N];
pair <string, string> A[N];

int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i].first >> A[i].second;
	for (int i = 1; i <= n; i++) cin >> P[i];
	
	string last = min(A[P[1]].first, A[P[1]].second);
	for (int i = 2; i <= n; i++) {
		string a = A[P[i]].first;
		string b = A[P[i]].second;
		
		if (last > a && last > b) {
			cout << "NO\n";
			return 0;
		}
		
		string c = min(a, b);
		string d = max(a, b);
		
		if (c >= last) last = c;
		else last = d;
	}
	
	cout << "YES\n";
	return 0;
}