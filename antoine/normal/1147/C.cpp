#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	for(int &x : a)
		cin >> x;

	const int m = *min_element(a.begin(), a.end());
	const int c = count(a.begin(), a.end(), m);

	cout << (c > n/2 ? "Bob" : "Alice");
	return 0;
}