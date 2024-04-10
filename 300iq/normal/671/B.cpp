#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fc first
#define sc second
#define endl '\n'
#define ll long long
#define forn(i, n) for(int i = 0; i < (int) (n); i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

const int INF = (int) 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    int n, k;
    ll S = 0;
    cin >> n >> k;
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	S += a[i];
    }
    int l = 0, r = INF;
    while (l < r - 1) {
    	ll sum = 0;
    	int m = (l + r) / 2;
    	for (int i = 0; i < n; i++) {
    		sum += max(0, a[i] - m);
    	}
    	if (sum <= k) {
    		r = m;
    	} else {
    		l = m;
    	}
    }
    int min_ans = r;
    l = 0, r = INF;	
    while (l < r - 1) {
    	ll sum = 0;
    	int m = (l + r) / 2;
    	for (int i = 0; i < n; i++) {
    		sum += max(0, m - a[i]);
    	}
    	if (sum <= k) {
    		l = m;
    	} else {
    		r = m;
    	}
    }
    r = l;
    l = min_ans;
    cout << (l > r ? l - r : (S % n == 0 ? 0 : 1)) << endl;
}