#include<bits/stdc++.h>
using namespace std;
int vis[300000];
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) vis[i] = 0;
		bool d1 = 1, d2 = 1;
		for (int i = 0; i < n; i++) {
			char c;
			cin >> c;
			if (c == '<') d1 = 0;
			if (c == '>') d2 = 0;
			if (c == '-') vis[i] = vis[(i+1)%n] = 1;
		}
		if (d1 || d2) cout << n << endl;
		else {
			int cnt = 0;
			for (int i = 0; i < n; i++)
				if (vis[i]) ++cnt;
			cout << cnt << endl;
		}
	}
}