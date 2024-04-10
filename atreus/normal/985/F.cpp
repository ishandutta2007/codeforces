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
const int maxn = 2e5 + 100;
const int  mod = 1e9 + 7;
const ll inf = (1ll << 62);
const int base = 31;
ll po[maxn], hsh[30][maxn];
string s[maxn];
set <int> sett[30];

int main(){
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	string mys;
	cin >> mys;
	mys = " " + mys;
	for (int i = 1; i <= n; i++)
		sett[mys[i] - 'a'].insert (i);
	
	po[0] = 1;
	for (int i = 1; i <= n; i++){
		po[i] = po[i - 1] * base;
		po[i] %= mod;
	}
	
	for (int i = 0; i < 26; i++){
		s[i] += " ";
		for (int j = 1; j <= n; j++){
			if ((int)(mys[j] - 'a') == i)
				s[i] += '1';
			else
				s[i] += '0';
		}
	}
	
	for (int i = 0; i < 26; i++){
		for (int j = 1; j <= n; j++){
			hsh[i][j] = hsh[i][j - 1] * base + (s[i][j] - '0');
			hsh[i][j] %= mod;
		}
	}

	for (int i = 1; i <= m; i++){
		int x, y, len;
		cin >> x >> y >> len;
		bool cur = 1;
		for (int j = 0; j < 26; j++){
			auto it = sett[j].lower_bound(x);
			if (it == sett[j].end() or *it > x + len - 1)
				continue;
			int id = (mys[y + (*it - x)] - 'a');
			if ((mod + hsh[j][x + len - 1] - (hsh[j][x - 1] * po[len] % mod)) % mod != (mod + hsh[id][y + len - 1] - (hsh[id][y - 1] * po[len] % mod)) % mod)
				cur = 0;
		}
		if (cur)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}