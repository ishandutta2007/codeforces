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

	int n, m;
	cin >> n >> m;

	map<int, bool> ma;

	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		ma[a * MAX + b] = true;
	}

	int ans[n];

	for(int i = 1; i <= n; i++){
		ans[i - 1] = i;
		int pos = i - 1;
		while(pos != 0 && ma[ans[pos - 1] * MAX + ans[pos]]){
			swap(ans[pos], ans[pos - 1]);
			pos--;
		}
	}

	print(ans, n);


}