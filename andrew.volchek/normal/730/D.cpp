#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cassert>
#include <bitset>
#include <fstream>
#include <stack>
#include <cstdlib>

using namespace std;

#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define ld long double

ll CUR = 0;

const int maxn = 2e5+3;
ll usu[maxn], rr[maxn];
ll R;

void upd(int i, int len, int value) {
	if (CUR >= len) {
		CUR -= len;
		return;
	}
	len -= CUR;
	value -= CUR;
	CUR = 0;
	if (value >= 2 * len) {
		usu[i] = len * 2;
	}
	else {
		int y = value - len;
		usu[i] = y * 2;
		len -= y;
		rr[i] = (len - 1) / R + 1;
		CUR = rr[i] * R - len;
	}
}

int main() {
	//srand(time(NULL));
	#ifdef LOCAL	
		//gen();
		freopen("a.in", "r", stdin);
		//freopen("a.out", "w", stdout);
		cout << endl << endl;
	#else
		//freopen("whats.in", "r", stdin);
		//freopen("whats.out", "w", stdout);
	#endif
	//check();
	
	ios_base::sync_with_stdio(false);
	
	int n;
	cin >> n >> R;
	vector < int > a(n), b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	for (int i = 0; i < n; i++) {
		if (a[i] > b[i]) {
			cout << -1 << "\n";
			return 0;
		}
	}
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		upd(i, a[i], b[i]);
		sum += rr[i];
	}
	cout << sum << "\n";
	if (sum <= 1e5) {
		ll cur = 0;
		for (int i = 0; i < n; i++) {
			cur += usu[i];
			for (int t = 0; t < rr[i]; t++) {
				cout << cur << " ";
				cur += R;
			}  
		}
		cout << "\n";
	}
	
	
	return 0;
}