#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 300005;

ll A[N];

int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];
	sort (A + 1, A + 1 + n);
	
	ll Ret = 0;
	for (ll i = 1; i <= n; i++) Ret += abs(i - A[i]);
	cout << Ret << endl;
	return 0;
}