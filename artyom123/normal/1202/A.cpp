#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(), x.end()

const int INF = 1e9 + 1;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif
   	int t;
   	cin >> t;
   	while (t--) {
   		string x, y;
   		cin >> x >> y;
   		reverse(x.begin(), x.end());
   		reverse(y.begin(), y.end());
   		int posy = 0;
   		for (int i = 0; i < y.size(); i++) {
   			if (y[i] == '1') {
   				posy = i;
   				break;
   			}
   		}
   		int posx = 0;
   		for (int i = posy; i < x.size(); i++) {
   			if (x[i] == '1') {
   				posx = i;
   				break;
   			}
   		}
   		cout << posx- posy << "\n";
   	}
    return 0;
}