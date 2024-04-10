#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin);
#define output freopen("output.txt", "w", stdout);
#define io input; output;
#define x first
#define y second
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x) memset(x, 0, sizeof(x));
#define print2(ar, n, m) for(int i = 0; i < n; i++){ for(int j = 0; j < m; j++) cout << ar[i][j]; cout << endl; }
#define print(ar, n) for(int i = 0; i < n; i++) cout << ar[i] <<  " ";
#define sqr(a) ((a) * (a))
#define endl "\n"
#define mod % 1e9+7
typedef pair<int, int> ii;
typedef long long ll;
typedef long double ld;
const int MAX = 3e4;
const ld E = 1e-11;

int main() {

	sync;

	int n;
	cin >> n;

	vector<int> v, ans;
	bool b1 = false, b2 = false, b3 = false;
	for(int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if(a == 0) {
			ans.push_back(a);
		} else {
			if(!b1 && a == 100) {
				b1 = true;
				ans.push_back(a);
			} else {
				v.push_back(a);
			}
		}
	}

	vector<int> vec;

	for(int i = 0; i < (int) v.size(); i++) {
		if(v[i] < 10 && !b2) {
			b2 = true;
			ans.push_back(v[i]);
		} else if(v[i] % 10 == 0 && !b3) {
			b3 = true;
			ans.push_back(v[i]);
		} else {
			vec.push_back(v[i]);
		}
	}

	if(!b2 && !b3 && (int) vec.size() > 0) {
		ans.push_back(vec[0]);
	}

	cout << ans.size() << endl;
	print(ans, (int) ans.size());

}