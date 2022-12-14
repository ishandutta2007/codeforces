#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <cmath>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <iomanip>
#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

int n, m;

const int maxn = 5e3 + 10;

unordered_map <string, bool> mp;

string s[maxn], to[maxn], to2[maxn], Type[maxn];

int num (int bit, bool x) {
	int cnt = 0;
	mp["?"] = x;
//	cout << "?" << " in bit " << bit << " --> " << mp["?"] << endl;
	for (int i = 1; i <= n; i++) {
		if (to[i][0] == '0' or to[i][0] == '1') {
			mp[s[i]] = (to[i][bit] == '1');
		}
		else {
			if (Type[i] == "AND") {
				mp[s[i]] = (mp[to[i]] & mp[to2[i]]);
			}
			if (Type[i] == "XOR") {
				mp[s[i]] = (mp[to[i]] ^ mp[to2[i]]);
			}
			if (Type[i] == "OR") {
				mp[s[i]] = (mp[to[i]] | mp[to2[i]]);
			}
		}
//		cout << s[i] << " in bit " << bit << " --> " << mp[s[i]] << endl;
		cnt += mp[s[i]];
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		string p;
		cin >> p;
		cin >> to[i];
		if (to[i][0] != '0' and to[i][0] != '1') {
			cin >> Type[i] >> to2[i];
		}
	}
	string t, p;
	for (int i = 0; i < m; i++) {
		int x = num (i, 1);
		int y = num (i, 0);
		if (x > y) {
			t += '1';
			p += '0';
		}
		else if (x == y) {
			t += '0';
			p += '0';
		}
		else {
			t += '0';
			p += '1';
		}	
	}
	cout << p << endl << t << endl;
}