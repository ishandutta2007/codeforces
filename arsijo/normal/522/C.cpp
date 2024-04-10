/*
 *      Author: arsijo;
 */

#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
//#define files(x) freopen(x ".dat", "r", stdin); freopen(x ".sol", "w", stdout);
#define input freopen("input.txt", "r", stdin);
#define ll long long
#define ui unsigned int
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x) memset(x, 0, sizeof(x));
#define ld long double
#define mod % 1000000007

int main() {

	sync;

	int t;
	cin >> t;
	while(t--) {

		int m, n;
		cin >> m >> n;

		int ar[n], u[n];
		int mini = INT_MAX;
		bool bol[n];
		for(int i = 0; i < n; i++) {
			cin >> ar[i];
			u[i] = 0;
			bol[i] = false;
		}

		bool e = false;

		int g = 0;

		for(int i = 1; i < m; i++) {
			int a, b;
			cin >> a >> b;
			if(b == 1) {
				if(!e) {
					e = true;
					int h = INT_MAX;
					for(int i = 0; i < n; i++)
					if(ar[i] <= g) {
						h = min(ar[i], h);
						u[i] = 1;
					}
				}
			}
			if(a == 0)
			g++;
			else {
				if(e)
				u[a - 1]--;
				ar[a - 1]--;
			}
		}

		int h = INT_MAX;
		for(int i = 0; i < n; i++)
		if(u[i] == 1) {
			h = min(ar[i], h);
		}
		if(h != INT_MAX && h > 0)
		g -= h;

		for(int i = 0; i < n; i++)
		if(ar[i] - g <= 0 || u[i] == 1)
		cout << 'Y';
		else
		cout << 'N';

		cout << endl;

	}

}