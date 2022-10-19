#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")

#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long
#define pt pair<int, int>
#define x first
#define y second

const int mod = 998244353;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int n, m;
    cin >> n >> m;
    vector<int> a(n);

    vector<pair<int, int>> w(m);

    for (int i = 0; i < m; ++i) {
    	string s(m ,'0');
    	s[i] = '1';
    	cout << "? " << s << endl;
    	int x;
    	cin >> x;
    	w[i] = {x, i};
    }

    sort(w.begin(), w.end());

    int ans = 0;
    string s(m, '0');
    for (int i = 0; i < m; ++i) {
    	s[w[i].second] = '1';
    	cout << "? " << s << endl;
    	int new_ans;
    	cin >> new_ans;
    	if (new_ans - ans != w[i].first) {
    		s[w[i].second] = '0';
    	} else {
    		ans = new_ans;
    	}
    }

  	cout << "! " << ans << endl;

    return 0;
}