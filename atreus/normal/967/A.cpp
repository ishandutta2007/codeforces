#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll maxn = 5e5 + 10;
const ll mod = 998244353;

int h[maxn], m[maxn], t[maxn];

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, d;
	cin >> n >> d;
	d++;
	for (int i = 1; i <= n; i++) {
		cin >> h[i] >> m[i];
		t[i] = m[i] + 60 * h[i];
	}
	if (t[1] >= d) {
		cout << 0 << " " << 0 << '\n';
		return 0;
	}
	for (int i = 1; i <= n - 1; i++)
		if (t[i + 1] - t[i] >= 2 * d) {
			cout << (t[i] + d)/60 << " " << (t[i] + d)%60 << '\n';
			return 0;
		}
	cout << (t[n]+d)/60 << " " << (t[n]+d)%60 << '\n';
}