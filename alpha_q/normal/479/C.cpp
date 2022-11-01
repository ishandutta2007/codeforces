#include <bits/stdc++.h>

using namespace std;

const int N = 5005;

pair <int, int> A[N];

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> A[i].first >> A[i].second;
	sort (A, A + n);
	
	int last = min(A[0].first, A[0].second);
	for (int i = 1; i < n; i++) {
		if (A[i].second >= last) last = A[i].second;
		else last = A[i].first;
	}
	
	cout << last << endl;
	return 0;
}