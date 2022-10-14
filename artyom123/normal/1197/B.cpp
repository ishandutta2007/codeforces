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
   	int n;
   	cin >> n;
   	vector <int> a(n);
   	for (auto &c : a) {
   		cin >> c;
   	}
   	int ind = 0;
   	for (int i = 1; i < n; i++) {
   		if (a[i] > a[ind]) {
   			ind = i;
   		}
   	}
   	bool f = true;
   	for (int i = 1; i < ind; i++) {
   		if (a[i] < a[i - 1]) {
   			f = false;
   		}
   	}
   	for (int i = ind + 1; i < n - 1; i++) {
   		if (a[i] < a[i + 1]) {
   			f = false;
   		}
   	}
   	if (f == true) {
   		cout << "YES";
   	} else {
   		cout << "NO";
   	}
    return 0;
}