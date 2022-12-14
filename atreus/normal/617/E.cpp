#include <cstring>
#include <algorithm>
#include <map>
#include <stack>
#include <cassert>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <queue>
#include <vector>
#include <iostream>
#include <set>
#define MP make_pair
#define F first
#define PB push_back
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int mod = 1e9 + 7;
const int maxn = 3e5 + 100;
const int inf = 1e9;
const int block = 400;

pair <pii, int> Q[maxn];
int a[maxn];

bool mo (pair <pii, int> fi, pair <pii, int> se) {
	int x = fi.F.F / block, y = se.F.F / block;
	if (x != y)
		return x < y;
	return fi.F.S < se.F.S;
}

unordered_map <int, int> mp;
ll A[maxn];

int main(){ 
	ios::sync_with_stdio(false);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] = a[i] ^ a[i - 1];
	}
	cout << endl;
	for (int i = 1; i <= m; i++) {
		cin >> Q[i].F.F >> Q[i].F.S;
		Q[i].S = i;
	}
	sort (Q + 1, Q + m + 1, mo);

	int L = 1, R = 0;
	mp[0] ++;
	ll ans = 0;
	for (int i = 1; i <= m; i++) {  // ( ... ]
		int l = Q[i].F.F, r = Q[i].F.S, idx = Q[i].S;
		while (L > l) {
			L --;
			ans += mp[(a[L - 1] ^ k)];
			mp[a[L - 1]] ++;
		}
		while (R < r) {
			R ++;
			ans += mp[(a[R] ^ k)];
			mp[a[R]] ++;
		}
		while (L < l) {
			mp[a[L - 1]] --;
			ans -= mp[(a[L - 1] ^ k)];
			L ++;
		}
		while (R > r) {
			mp[a[R]] --;
			ans -= mp[(a[R] ^ k)];
			R --;
		}
		A[idx] = ans;
	}
	
	for (int i = 1; i <= m; i++)
		cout << A[i] << '\n';
	cout << endl;
}