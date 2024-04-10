	#include <bits/stdc++.h>

	using namespace std;

	#define pb push_back

	const int INF = 1e9 + 1;
	const int MAXN = 5e5 + 5;
	const int MAXK = 750;

	int main() {
	#ifdef LOCAL
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#else
	    ios_base::sync_with_stdio(0);
	    cin.tie(0);
	    cout.tie(0);
	#endif
	    vector <int> a(MAXN);
	    vector <vector<int>> ans(MAXK, vector<int>(MAXK));
	    int q;
	    cin >> q;
	    while (q--) {
	    	int type;
	    	cin >> type;
	    	if (type == 1) {
	    		int x, y;
	    		cin >> x >> y;
	    		a[x] += y;
	    		for (int i = 1; i < 750; i++) {
	    			ans[i][x % i] += y;
	    		}
	    	} else {
	    		int x, y;
	    		cin >> x >> y;
	    		if (x < MAXK) {
	    			cout << ans[x][y] << "\n";
	    		} else {
	    			int now = 0;
	    			for (int i = 0; i * x + y <= (int)5e5; i++) {
	    				int ind = i * x + y;
	    				if (ind > 0) {
	    					now += a[ind];
	    				}
	    			}
	    			cout << now << "\n";
	    		}
	    	}
	    }
	    return 0;
	}