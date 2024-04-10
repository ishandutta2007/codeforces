#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define INF (int) 1e9 + 7;
#define left left_fenwick
#define right right_fenwick
#define fc first
#define sc second
#define pb push_back
#define endl '\n'

int main() {
	ios_base::sync_with_stdio(0);
	//ifstream cin("input.txt");
	//ofstream cout("out.txt");
	int n;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	if (a[0] > 1) {
		a[0] = 1;
	}
	for (int i = 1; i < n; i++) {
		a[i] = a[i - 1] + (a[i] > a[i - 1]);
	}
	cout << a[n - 1] + 1 << endl;
}