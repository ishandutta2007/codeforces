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
#define print2(ar, n, m)	for(int i = 0; i < n; i++){ for(int j = 0; j < m; j++) cout << ar[i][j]; cout << endl; }
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
	int n, m;
	cin >> n >> m;

	ll sum = 0;
	ll ar[n];
	for(int i = 0; i < n; i++){
		cin >> ar[i];
		sum += ar[i];
	}

	vector<ll> vec;
	for(int i = 0; i < m; i++){
		int a;
		cin >> a;
		a--;
		sum -= ar[a];
		vec.push_back(ar[a]);
	}

	sort(vec.rbegin(), vec.rend());

	for(int i = 0; i < (int) vec.size(); i++)
		sum += max(sum, vec[i]);

	cout << sum;



}