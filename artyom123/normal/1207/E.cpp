	#include <bits/stdc++.h>

	using namespace std;

	#define pb push_back

	const int INF = 1e9 + 1;
	
	int main() {
	#ifdef LOCAL
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#else

	#endif
	    cout << '?' << " ";
	    for (int i = 1; i <= 100; i++) {
	    	cout << (i << 7) << " ";
	    }
	    cout << endl;
	    int x1;
	    cin >> x1;
	    int ans = 0;
	    for (int i = 0; i < 7; i++) {
	    	ans |= ((1 << i) & x1);
	    }
	    cout << '?' << " ";
	    for (int i = 0; i < 100; i++) {
	    	cout << i << " ";
	    }
	    cout << endl;
	    cin >> x1;
	    for (int i = 7; i < 14; i++) {
	    	ans |= ((1 << i) & x1);
	    }
	    cout << '!' << " " << ans << endl;
	    return 0;
	}