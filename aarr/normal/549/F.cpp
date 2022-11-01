#include <iostream>
#include <vector>
#include <map>
using namespace std;


const int N = 1000 * 1000 + 5;
int n, k;
long long ans;

int a[N];
long long ps[N];
int mp[N];
vector <int> vec;


void dq(int l, int r) {
	if (r - l == 1) {
		return;
	}
	int md = (l + r) / 2;
	dq(l, md);
	dq(md, r);
	int t = md - 1;
	int maxi = 0;
	for (int i = md; i < r; i++) {
		maxi = max(maxi, a[i]);
		while (t >= l && a[t] < maxi) {
			mp[(ps[md - 1] - ps[t - 1] + k) % k]++;
			vec.push_back((ps[md - 1] - ps[t - 1] + k) % k);
		//	cout << "47 " << l << " " << r << " " << (ps[md - 1] - ps[t - 1] + k) % k << endl;
			t--;
		}
		ans += mp[(2 * k - ps[i] + ps[md - 1] + maxi) % k];
	}
	for (auto x : vec) {
		mp[x] = 0;
	}
	vec.clear();
	t = md, maxi = 0;
	for (int i = md - 1; i >= l; i--) {
		maxi = max(maxi, a[i]);
		while (t < r && a[t] <= maxi) {
			mp[(ps[t] - ps[md - 1] + k) % k]++;
			vec.push_back((ps[t] - ps[md - 1] + k) % k);
		//	cout << "48 " << l << " " << r << " " << (ps[md - 1] - ps[t - 1] + k) % k << endl;
			t++;
		}
		ans += mp[(2 * k - ps[md - 1] + ps[i - 1] + maxi) % k];
	}	
	for (auto x : vec) {
		mp[x] = 0;
	}
	vec.clear();
}

int main() {
	ios :: sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n  +1; i++) {
		ps[i] = ps[i - 1] + a[i];
		ps[i] %= k;
	}
	dq(1, n + 1);
	cout << ans;
	return 0;
}