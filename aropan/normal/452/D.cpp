#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

#define sqr(x) ((x)*(x))

int main()
{
	#ifdef MJUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
	int k;
	cin >> k;
	priority_queue < int, vector <int>, greater <int> >  h[3];
	
	int n[3];
	int t[3];
	for (int i = 0; i < 3; ++i) {
		cin >> n[i];
		for (int j = 0; j < n[i]; ++j) {
			h[i].push(0);
		}
	}
	
	for (int i = 0; i < 3; ++i) {
		cin >> t[i];
	}

	int ans = 0;
	while (k-- > 0) {
		int wait = 0;
		for (int i = 0; i < 3; ++i) {
			int v = h[i].top();
			for (int j = 0; j < i; ++j) {
				v -= t[j];
			}
			wait = max(v, wait);
		}

		for (int i = 0; i < 3; ++i) {
			h[i].pop();
			wait += t[i];
			h[i].push(wait);
		}
		ans = wait;
	}
	cout << ans << endl;
	
	return 0;
}