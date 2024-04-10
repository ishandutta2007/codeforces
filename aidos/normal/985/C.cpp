#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <ctime>
 
#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define ull unsigned long long
#define pll pair < ll, ll >
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()
#define sz(a) (int)a.size()
 
const int inf = (1ll << 30) - 1;
const int maxn = (int) 1e5 + 10;
const int mod = (int) 1e9 + 7;
using namespace std;
int n, k, l;
int a[100100];
int u[100100];
int main () {
	cin >> n >> k >> l;
	int m = n * k;
	for(int i = 0; i < m; i++) cin >> a[i];
	sort(a, a + m);
	int t = 0;
	while(t < m && a[t] - a[0] <= l) t++;
	if(t < n) {
		cout << 0 << "\n";
		return 0;
	}
	ll ans = 0;
	int z = m-1;
	t--;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < k-1; j++) {
			while(u[z]) z--;
			u[z] = 1;
		}
		while(u[t]) t--;
		ans += a[t];
		u[t] = 1;
	}
	cout << ans << "\n";


    return 0;
}