#include <iostream>
#include <map>
using namespace std;

const int N = 1005;

int a[N];
long long f[N];
int dp[N][N];
map <int, int> mp;
map <int, pair <int, pair <int, int> > > mp2;
map <pair <int, int>, int> mp3;
int main() {
	int n, ans = 2;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		mp[a[i]]++;
		mp2[a[i]] = {0, {0, 0}};
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j && !mp3[{a[i], a[j]}]) {
				mp3[{a[i], a[j]}] = true;
				int l = 2;
				f[1] = a[i];
				f[2] = a[j];
				
				if (f[1] == f[2]) {
					mp2[a[i]] = {2, {i, j}};
				}
				else {
					mp2[a[i]] = {1, {i, j}};
					mp2[a[j]] = {1, {i, j}};
				}
				for (int k = 3; k <= n; k++) {
					f[k] = f[k - 1] + f[k - 2];
					if (mp[f[k]] == 0)
						break;
					pair <int, int> p = {i, j};
					if (mp2[f[k]].second != p) {
						mp2[f[k]] = {0, {i, j}};
					}
					mp2[f[k]].first++;
					if (mp2[f[k]].first > mp[f[k]])
						break;
					l++;
				}
				ans = max(ans, l);
			}
		}
	}
	cout << ans << endl;
	return 0;
}