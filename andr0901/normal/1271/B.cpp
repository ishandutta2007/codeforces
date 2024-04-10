#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

//vector string deque break continue
#define forn(i, s, f) for (int i = (int)s; i < (int)f; i++)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pf push_front
#define pb push_back
#define pop_f pop_front
#define pop_b pop_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

int n;

void solve(vector <int>& a) {
	vector <int> ans;
    forn (i, 0, n - 1) {
    	if (!a[i]) {
    		ans.pb(i + 1);
    		a[i] ^= 1;
    		a[i + 1] ^= 1;
    	}
    	/*for (int j : a)
    		cout << j << " ";
    	cout << "\n";*/
    }
    if (!a[n - 1])
    	return;
    else {
    	cout << ans.size() << "\n";
    	for (int i : ans)
    		cout << i << " ";
    	exit(0);
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    string s;
    cin >> n >> s;
    vector <int> a(n);
    forn (i, 0, sz(s))
    	a[i] = s[i] == 'W';
    solve(a);
    forn (i, 0, n)
    	a[i] = s[i] != 'W';
    solve(a);
    cout << -1;
    return 0;
}