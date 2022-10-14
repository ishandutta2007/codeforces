#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(), x.end()

const int INF = 1e9 + 1;

int a[10][10];

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif
   	string s;
   	cin >> s;
   	for (int x = 0; x < 10; x++) {
   		for (int y = 0; y < 10; y++) {
   			for (int i = 0; i < 10; i++) {
   				for (int j = 0; j < 10; j++) {
   					a[i][j] = INF;
   				}
   			}
   			for (int i = 0; i < 10; i++) {
   				for (int j = 0; j < 10; j++) {
   					if ((i + x) % 10 == j || (i + y) % 10 == j) {
   						a[i][j] = 1;
   					}
   				}
   			}
   			for (int k = 0; k < 10; k++) {
   				for (int i = 0; i < 10; i++) {
   					for (int j = 0; j < 10; j++) {
   						a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
   					}
   				}
   			}
   			int ans = 0;
   			bool f = true;
   			for (int i = 0; i < s.size() - 1; i++) {
   				if (a[s[i] - '0'][s[i + 1] - '0'] == INF) {
   					f = false;
   					break;
   				}
   				ans += a[s[i] - '0'][s[i + 1] - '0'] - 1;
   			}
   			if (f == true) {
   				cout << ans << " ";
   			} else {
   				cout << -1 << " ";
   			}
   		}
   		cout << "\n";
   	}

    return 0;
}