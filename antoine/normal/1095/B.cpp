#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	for(int &x : a)
		cin >>x;
	sort(a.begin(), a.end());
cout << min(a[n-1] - a[1], a[n-2] - a[0]);

	return 0;
}