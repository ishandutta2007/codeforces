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
   	int t;
   	cin >> t;
   	while (t--) {
   		int n;
   		cin >> n;
   		int x = 2;
   		while (x * (x - 1) / 2 <= n) {
   			x++;
   		}
   		x--;
   		cout << 1 << 3 << 3;
   		for (int i = 0; i < n - x * (x - 1) / 2; i++) {
   			cout << 7;
   		}
   		for (int i = 0; i < x - 2; i++) {
   			cout << 3;
   		}
   		cout << 7 << "\n";
   	}
   	

    return 0;
}