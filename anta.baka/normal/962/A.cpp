#include <bits/stdc++.h>
using namespace std;
#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
using ll = long long;
const int maxn = 2e5;

int n, a[maxn];
ll s, s1;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i], s += a[i];
	for(int i = 0; i < n; i++) {
		s1 += a[i];
		if(2 * s1 >= s) return cout << i + 1, 0;
	}
}