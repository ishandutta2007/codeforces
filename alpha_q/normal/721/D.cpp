#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

typedef pair <long long, int> pii;

int n;
long long k, x;
pii a[N];
long long res[N];
set <pii> pq;

bool cmp (pii x, pii y) {
	return x.second < y.second;
}

void solve_odd (int move) {
	for (int i = 1; i <= n; ++i) pq.insert(make_pair(abs(a[i].first), i));
	while (move--) {
		pii now = *pq.begin();
		pq.erase(pq.begin());
		now.first += x;
		pq.insert(now);
	} 
	for (pii now : pq) {
		res[a[now.second].second] = now.first;
		// cout << now.first << " " << now.second << endl;
		if (a[now.second].first < 0) res[a[now.second].second] = -res[a[now.second].second];
	}

	for (int i = 1; i <= n; ++i) printf("%lld ", res[i]);
	puts("");
}

int main (int argc, char const *argv[]) {
	scanf("%d %lld %lld", &n, &k, &x);
	for (int i = 1; i <= n; ++i) 
		scanf("%lld", &a[i].first), a[i].second = i;
    sort(a + 1, a + n + 1);

    int neg = 1;
    while (neg <= n and a[neg].first < 0) ++neg;
    --neg;

    if (neg & 1) solve_odd(k);
    else {
    	if (neg == n) {
    		if (abs(a[n].first) > k * x) {
    			a[n].first += k * x;
    			for (int i = 1; i <= n; ++i) res[a[i].second] = a[i].first;
    			for (int i = 1; i <= n; ++i) printf("%lld ", res[i]);
    			puts("");
    		} else {
    			while (a[n].first < 0) a[n].first += x, --k;
    			solve_odd(k);
    		}
    	} else {
    		if (neg == 0) {
    			while (k and a[1].first >= 0) a[1].first -= x, --k;
    			if (k) {
    				sort(a + 1, a + n + 1);
    				// for (int i = 1; i <= n; ++i) cout << a[i].first << " " << a[i].second << endl;
    				solve_odd(k);
    			} else {	
	    			for (int i = 1; i <= n; ++i) res[a[i].second] = a[i].first;
	    			for (int i = 1; i <= n; ++i) printf("%lld ", res[i]);
	    			puts("");
    			}
    		} else if (abs(a[neg].first) <= k * x and a[neg + 1].first < k * x) {
    			if (abs(a[neg].first) > a[neg + 1].first) {
    				while (a[neg + 1].first >= 0) a[neg + 1].first -= x, --k;
    				sort(a + 1, a + n + 1);
    				solve_odd(k);
    			} else {
    				while (a[neg].first < 0) a[neg].first += x, --k;
    				sort(a + 1, a + n + 1);
    				solve_odd(k);
    			}
    		} else if (abs(a[neg].first) <= k * x) {
				while (a[neg].first < 0) a[neg].first += x, --k;
				sort(a + 1, a + n + 1);
				solve_odd(k);
    		} else if (a[neg + 1].first < k * x) {
				while (a[neg + 1].first >= 0) a[neg + 1].first -= x, --k;
				sort(a + 1, a + n + 1);
				solve_odd(k);
    		} else {
    			if (a[neg + 1].first < abs(a[neg].first)) {
    				a[neg + 1].first -= k * x;
	    			for (int i = 1; i <= n; ++i) res[a[i].second] = a[i].first;
	    			for (int i = 1; i <= n; ++i) printf("%lld ", res[i]);
	    			puts("");
    			} else {
    				a[neg].first += k * x;
	    			for (int i = 1; i <= n; ++i) res[a[i].second] = a[i].first;
	    			for (int i = 1; i <= n; ++i) printf("%lld ", res[i]);
	    			puts("");
    			}
    		}
    	}
    }
    return 0;
}