#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int N = 1005;
int n;

int a[N];
bool b[N];
vector <int> ans;


int get() {
	fill(b, b + N, false);
	for (int i = 1; i <= n; i++) {
		b[a[i]] = true;
	}
	for (int i = 0; i <= n; i++) {
		if (!b[i]) {
			return i;
		}
	}
}


int main() {
	ios :: sync_with_stdio(false);
	int t;
	cin >> t;
	for (int ii = 0; ii < t; ii++) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		bool b = true;
	/*	for (int i = 2; i <= n; i++) {
			int x = get();
			a[i] = x;
			if (i > 1 && a[i] < a[i - 1]) {
				b = false;
			}
			ans.push_back(i);
		}
		if (get() == n) {
			a[n] = n;
			
		}*/
		for (int i = 2; i <= n; i++) {
			if (a[i] < a[i - 1]) {
				b = false;
			}
		}
		while (!b) {
			int x = get();
			if (x == n) {
				int y = 0;
				for (int i = 1; i <= n; i++) {
					if (a[i] != i - 1) {
						y = i;
					}
 				}
 				a[y] = x;
 				ans.push_back(y);
			}
			else {
				a[x + 1] = x;
				ans.push_back(x + 1); 
			}
			b = true;
			for (int i = 2; i <= n; i++) {
				if (a[i] < a[i - 1]) {
					b = false;
				}
			}
		//	for (int i = 1; i <= n; i++) {
			//	cout << "73 " << i << " " << a[i] << endl;
		//	}
		}
		if (ans.size() > n * 2) {
			int x = 0;
		//	n /= x;
		}
		cout << ans.size() << '\n';
		for (auto x : ans) {
			cout << x << " ";
		}
		cout << '\n';
		ans.clear();
	}
	
	return 0;
}