#include <bits/stdc++.h>

using namespace std;

#define int long long

struct fl {
	int f, t, c;	
};

int n, m, k, pref[1000001], suff[1000001], post[1000001], sost[1000001];
vector<fl> a[1000001];
vector<int> opt;

main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 0; i < m; i++) {
		int d, f, t, c;
		cin >> d >> f >> t >> c;
		a[d].push_back({f, t, c});
	}

	post[1] = n;
	opt.assign(n + 1, -1);
	for(int i = 2; i <= 1000000; i++) {
		pref[i] = pref[i - 1];
		post[i] = post[i - 1];
		for(fl x : a[i - 1])
			if(x.f == 0) continue;
			else if(opt[x.f] == -1) {
				post[i]--;
				opt[x.f] = x.c;
				pref[i] += x.c;
			} else if(x.c < opt[x.f]) {
				pref[i] -= opt[x.f];
				opt[x.f] = x.c;
				pref[i] += x.c;
			}
	}

	sost[1000000] = n;
	opt.assign(n + 1, -1);
	for(int i = 999999; i >= 1; i--) {
		suff[i] = suff[i + 1];
		sost[i] = sost[i + 1];
		for(fl x : a[i + 1])
			if(x.t == 0) continue;
			else if(opt[x.t] == -1) {
				sost[i]--;
				opt[x.t] = x.c;
				suff[i] += x.c;
			} else if(x.c < opt[x.t]) {
				suff[i] -= opt[x.t];
				opt[x.t] = x.c;
				suff[i] += x.c;
			}
	}

	int ans = 1000LL * 1000 * 1000 * 1000 * 1000 * 1000;
	for(int i = 1; i <= 1000000; i++)
		if(i + k - 1 <= 1000000 && post[i] == 0 && sost[i + k - 1] == 0)
			ans = min(ans, pref[i] + suff[i + k - 1]);
	cout << (ans == 1000LL * 1000 * 1000 * 1000 * 1000 * 1000 ? -1 : ans);
}