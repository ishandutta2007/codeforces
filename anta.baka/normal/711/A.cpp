#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

int main() {
	int n;
	cin >> n;
	bool r = false;
	vector<vector<char>> a(n, vector<char>(5));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 5; j++)
			cin >> a[i][j];
		if(!r && a[i][0] == 'O' && a[i][1] == a[i][0]) {
			a[i][0] = '+';
			a[i][1] = '+';
			r = true;
		}
		if(!r && a[i][3] == 'O' && a[i][4] == a[i][3]) {
			a[i][3] = '+';
			a[i][4] = '+';
			r = true;
		}
	}
	if(!r) {
		cout << "NO";
		return 0;
	}
	cout << "YES\n";
	for(int i = 0; i < n; i++, cout << "\n")
		for(int j = 0; j < 5; j++)
			cout << a[i][j];
}