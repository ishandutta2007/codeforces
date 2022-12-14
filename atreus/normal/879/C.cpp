#include <bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int maxn = 5e5 + 100;
const int inf = 1e9;

char ope[maxn];
int x[maxn], a[3];

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> ope[i] >> x[i];
	}
	for (int i = 0; i < 10; i++) {
		bool fi = 0, se = 1;
		for (int j = 0; j < n; j++) {
			bool y = (x[j] & (1 << i)) > 0;	
			if (ope[j] == '|') {
				fi |= y, se |= y;
			}
			else if (ope[j] == '&') {
				fi &= y, se &= y;
			}
			else {
				fi ^= y, se ^= y;
			}

		}
		if (fi == 0) {
			if (se == 0) {
				continue;
			}
			else {
				a[0] += (1 << i);
			}
		}
		else {
			if (se == 0) {
				a[0] += (1 << i);
				a[1] += (1 << i);
			}
			else {
				a[0] += (1 << i);
				a[2] += (1 << i);
			}
		}
	}
	cout << 3 << endl;
	cout << "& " << a[0] << endl << "^ " << a[1] << endl << "| " << a[2] << endl;
}