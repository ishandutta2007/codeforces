#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define MAX 300001
#define ms(x) memset(x, 0, sizeof(x));
#define input freopen("input.txt", "r", stdin);
#define ll long long
#define ld long double
#define sqr(a) ( (a) * (a) )
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
const ld E = 1e-9;

int main() {

	ll n, s;
	cin >> n >> s;

	ll sum = 0;
	ll ar[n];
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
		sum += ar[i];
	}

	for (int i = 0; i < n; i++)
		cout << max(s - sum + ar[i] - 1, (ll) 0) + max(ar[i] - s + n - 1, (ll) 0) << " ";

}