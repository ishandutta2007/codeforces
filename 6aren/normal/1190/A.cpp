#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define endl '\n'
#define sp ' '
#define fi first
#define se second

long long n, m, k;
long long p[100005];

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> p[i];
		p[i]--;
	}
	sort(p + 1, p + 1 + m);
	int pivot = 0;
	int ans = 0 ;
	while (1) {
		long long t;
		for (int i = pivot + 2; ; i++) {
			//cout << p[i] << ' ' << pivot << ' ' << k << endl;
			//cout << i << ' ' << (p[i] - pivot) / k << ' ' << (p[i - 1] - pivot) / k  << endl;
			if ((p[i] - pivot) / k != (p[i - 1] - pivot) / k || i == m + 1) {
				pivot = i - 1;
				ans++;
				break;
			}
		}
		if (pivot == m) break;
	}
	cout << ans;
	return 0;
}