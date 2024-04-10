#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define ll long long
#define pii pair <int, int>
#define fs first
#define sc second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector <int> a(2e5 + 1), b(n);
    forn (i, 0, n) {
    	cin >> b[i];
    	a[b[i]]++;
    }
    int mx = -1, idx;
    forn (i, 0, 2e5 + 1) 
    	if (a[i] > mx)
    		mx = a[i], idx = i;
    forn (i, 0, n) {
    	if (b[i] == idx) {
    		idx = i;
    		break;
    	}
    }

    vector <vector <int>> ans;
    forn (i, idx + 1, n) {
    	if (b[i] > b[i - 1])
    		ans.pb({2, i + 1, i});
    	if (b[i] < b[i - 1])
    		ans.pb({1, i + 1, i});
    	b[i] = b[i - 1];
    }
    for (int i = idx - 1; i >= 0; i--) {
    	if (b[i] > b[i + 1])
    		ans.pb({2, i + 1, i + 2});
    	if (b[i] < b[i + 1])
    		ans.pb({1, i + 1, i + 2});
    	b[i] = b[i + 1];
    }
    cout << sz(ans) << "\n";
    for (auto i : ans)
    	cout << i[0] << " " << i[1] << " " << i[2] << "\n";
    return 0;
}