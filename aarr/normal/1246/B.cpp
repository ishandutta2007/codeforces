#include <iostream>
#include <vector>
#include <map>
#define int long long
using namespace std;

const int N = 100 * 1000 + 5;
const long long N2 = 1ll * N * N;
int n, k;
long long ans = 0;

int a[N];
int cnt[N];
bool pox[N];
map <vector <int>, int> mp;
vector <int> v;
long long po(int x, int y) {
	if (y == 0)
		return 1;
	long long ans = po(x, y / 2);
	ans *= ans;
	if (ans > N2)
		return 0;
	if (y % 2) {
		ans *= x;
		if (ans > N2)
			return 0;
	}
	return ans;
}
void ad(int x) {
	long long y = po(x, k);
	int i;
	for (i = max(y / N, 1ll); 1ll * i * i < y; i++) {
		if (i > N)  
			break;
		if (y / i > N)
			continue;
		if (y % i == 0) {
		//	cout << "73 " << y << " " << i << " " << y / i << " " << " " << cnt[i] << " " << cnt[y / i] << " " << ans << endl;
			ans += 1ll * cnt[i] * cnt[y / i];
		//	if (1ll * cnt[i] * cnt[y / i] > 0) {
		//		cout << y << " " << i << endl;
		//	}
		}
	}
	if (i * i == y) {
		ans += 1ll * cnt[i] * (cnt[i] - 1) / 2;
	}
}
int32_t main() {
	ios :: sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	if (k == 2) {
		for (int i = 1; i <= n; i++) {
			v.clear();
			int x = a[i];
		//	cout << i << endl;
			for (int j = 2; j * j <= x; j++) {
			//	cout << "26 " << i << " " << j << endl;
				int y = 0;
				while (x % j == 0) {
					y++;
					x /= j;
				}
				if (y % 2 == 1) {
					v.push_back(j);
				}
			}
		//	cout << "47 " << i << endl;
			if (x > 1) {
				v.push_back(x);
			}
			ans += mp[v];
			mp[v]++;
		}
		cout << ans << endl;
		return 0;
	}
	for (int i = 1; i; i++) {
	//	cout << i << " " << po(i, k) << endl;
		if ((long long) po(i, k) >= N2 - 5 || po(i, k) == 0) {
			break;
		}
		ad(i);
	}
	cout << ans << endl;
	return 0;
}