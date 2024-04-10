	#include <bits/stdc++.h>

	using namespace std;

	#define pb push_back

	const int INF = 1e9 + 1;
	const long long mod = 998244353;
	const int MAXN = 4e5;

	vector <long long> fact(MAXN);

	void f() {
		fact[0] = 1;
		for (int i = 1; i < MAXN; i++) {
			fact[i] = fact[i - 1] * i;
			fact[i] %= mod;
		}
	}

	int main() {
	#ifdef LOCAL
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#else
	    ios_base::sync_with_stdio(0);
	    cin.tie(0);
	    cout.tie(0);
	#endif
	    f();
	    int n;
	    cin >> n;
	    vector <pair<int, int>> l(n);
	    vector <int> a;
	    vector <int> b;
	    for (auto &c : l) {
	    	cin >> c.first >> c.second;
	    	a.pb(c.first);
	    	b.pb(c.second);
	    }
	    vector <int> cnta(MAXN);
	    vector <int> cntb(MAXN);
	    long long ansa = 1;
	    long long ansb = 1;
	    for (auto &c : a) {
	    	cnta[c]++;
	    }
	    for (auto &c : b) {
	    	cntb[c]++;
	    }
	    for (auto &c : cnta) {
	    	ansa *= fact[c];
	    	ansa %= mod;
	    }
	    for (auto &c : cntb) {
	    	ansb *= fact[c];
	    	ansb %= mod;
	    }
	    long long ansall = fact[n];
	    long long ans = ansa + ansb;
	    ans %= mod;
	    long long ansc = 1;
	    sort(l.begin(), l.end());
	    cntb.assign(MAXN, 0);
	    int right = 0;
	    int MAX = -1;
	    for (int left = 0; left < n; ) {
	    	right = left;
	    	while (right + 1 < n && l[right + 1].first == l[left].first) {
	    		right++;
	    	}
	    	int nowmi = INF, nowma = -1;
	    	for (int i = left; i <= right; i++) {
	    		nowmi = min(nowmi, l[i].second);
	    		nowma = max(nowma, l[i].second);
	    	}
	    	if (nowmi < MAX) {
	    		cout << (ansall - ans + mod) % mod;
	    		return 0;
	    	}
	    	MAX = nowma;
	    	left = right + 1;
	    }
	    int r = 0;
	    for (int i = 0; i < n; ) {
	    	r = i;
	    	while (r + 1 < n && l[r + 1].first == l[i].first) {
	    		r++;
	    	}
	    	for (int j = i; j <= r; j++) {
	    		cntb[l[j].second]++;
	    	}
			for (int j = i; j <= r; j++) {
				ansc *= fact[cntb[l[j].second]];
				ansc %= mod;
	    		cntb[l[j].second] = 0;
	    	}
	    	i = r + 1;
	    }
	    ans -= ansc;
	    ans += mod;
	    ans %= mod;
	    cout << (ansall - ans + mod) % mod;
	    return 0;
	}