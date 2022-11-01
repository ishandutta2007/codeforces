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

vector < pair < int , int > > f(vector < int > &b) {
	vector < pair < int , int > > ans;
	for (int i = 0; i < (int)b.size(); i++) {
		if (b[i]) {
			ans.pb(mp(b[i], i));
		}
	}
	return ans;
}

vector < int > getmask(const vector < int > &pos, int n) {
	vector < int > a(n);
	for (auto x : pos) {
		a[x] = 1;
	}
	return a;
}

void writemask(const vector < int > &a) {
	for (auto x : a) {
		cout << x;
	}
	cout << "\n";
}

bool solve(vector < int > &a, int x) {
	int n = (int)a.size();
	int sum = 0;
	vector < int > b(a.size());
	for (int i = 0; i < n; i++) {
		if (a[i] < x) {
			return false;
		}
		b[i] = a[i] - x;
		sum += b[i];
	}
	vector < vector < int > > ans;
	if (sum % 2 == 1) {
		if (sum == 1) {
			return false;
		}
		vector < pair < int , int > > un = f(b);
		sort(un.begin(), un.end());
		reverse(un.begin(), un.end());
		if (un.size() < 3) {
			return false;
		}
		b[un[0].snd]--;
		b[un[1].snd]--;
		b[un[2].snd]--;
		ans.pb(getmask({un[0].snd, un[1].snd, un[2].snd}, n));
		sum -= 3;
	}
	int maxi = *max_element(b.begin(), b.end());
	auto un = f(b);
	if (un.size() == 1 || maxi * 2 > sum) {
		return false;
	}
	while (sum > 0) {
		vector < pair < int , int > > un = f(b);
		sort(un.begin(), un.end());
		reverse(un.begin(), un.end());
		b[un[0].snd]--;
		b[un[1].snd]--;
		ans.pb(getmask({un[0].snd, un[1].snd}, n));
		sum -= 2;
	}
	cout << x << "\n";
	cout << ans.size() << "\n";
	for (auto y : ans) {
		writemask(y);
	}
	return true;
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
	cin >> n;
	vector < int > a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 100; i >= 1; i--) {
		if (solve(a, i)) {
			return 0;
		}
	}
	cout << 0 << "\n";
	cout << (n - 1) * 100 << "\n";
	for (int i = 1; i < n; i++) {
		for (int t = 0; t < 100; t++) {
			writemask(getmask({0, i}, n));
		}
	}
	
	return 0;
}