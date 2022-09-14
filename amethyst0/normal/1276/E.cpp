//#pragma comment(linker, "/STACK:1000000000")
//#pragma GCC optimize("Ofast,no-stack-protector")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <ctime>
#include <random>
#include <bitset>
#include <cstring>
#include <memory.h>
#include <cassert>
 
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long 
#define pii pair <int, int>
#define pll pair <ll, ll>
#define ld double
 
using namespace std;
 
multiset <ll> pos[2];
vector <pll> ans[2];
 
ll gcd(ll a, ll b) {
	return (b == 0 ? a : gcd(b, a % b));
}
 
void make(int it, ll a, ll b) {
	if (a == b) {
		return;
	}
 
	ans[it].push_back(mp(a, b));
	pos[it].erase(pos[it].find(a));
	pos[it].insert(2 * b - a);
}
 
void print(int it) {
	cout << "SET " << it << ": ";
	for (auto itr : pos[it]) {
		cout << itr << ' ';
	}
 
	cout << endl;
}
 
int sum(int it) {
	int x = 0;
	for (auto itr : pos[it]) {
		x += itr & 1;
	}
 
	return x;
}
 
int main() {
	ll a, b, c, d;
	cin >> a >> b >> c >> d;
	pos[0].insert(a);
	pos[0].insert(b);
	pos[0].insert(c);
	pos[0].insert(d);
	ll g0 = gcd(gcd(abs(d - a), abs(c - a)), abs(b - a));
	ll c0 = (abs(b - a) & 1) ^ (abs(c - a) & 1) ^ (abs(d - a) & 1);
 
	cin >> a >> b >> c >> d;
	pos[1].insert(a);
	pos[1].insert(b);
	pos[1].insert(c);
	pos[1].insert(d);
	ll g1 = gcd(gcd(abs(d - a), abs(c - a)), abs(b - a));
	ll c1 = (abs(b - a) & 1) ^ (abs(c - a) & 1) ^ (abs(d - a) & 1);
 
	if (g0 != g1 || c0 != c1) {
		cout << -1 << endl;
		//system("pause");
		return 0;
	}
 
	if (g0 == 0) {
		if ((*pos[0].begin()) != (*pos[1].begin())) {
			cout << -1 << endl;
		}
		else {
			cout << 0 << endl;
		}
 
		//system("pause");
		return 0;
	}
 
	if (((*pos[0].begin()) - (*pos[1].begin())) % g0 != 0) {
		cout << -1 << endl;
		return 0;
	}
 
	ll sd = (*pos[0].begin()) % g0;
	if (sd < 0) {
		sd += g0;
	}
 
	for (int it = 0; it < 2; it++) {
		multiset <ll> nx;
 
		for (ll x : pos[it]) {
			nx.insert((x - sd) / g0);
		}
 
		pos[it] = nx;
	}
 
	for (int it = 0; it < 2; it++) {
		while ((*pos[it].rbegin()) - (*pos[it].begin()) >= 3) {
			auto itr = pos[it].begin();
			ll a = *itr;
			itr++;
			ll b = *itr;
			itr++;
			ll c = *itr;
			itr++;
			ll d = *itr;
 
			ll len = d - a;
			ll x = min(c - a, d - c);
			if (x >= len / 6 && x != 0) {
				make(it, d, c);
			}
			else {
				ll y = min(b - a, d - b);
				if (y >= len / 6 && x != 0) {
					make(it, d, b);
				}
				else {
					if (c - a < len / 6) {
						make(it, b, a);
						make(it, 2 * a - b, c);
					}
					else if (d - b < len / 6) {
						make(it, c, d);
						make(it, 2 * d - c, b);
					}
					else if (b - a < d - c) {
						make(it, b, c);
						make(it, 2 * c - b, d);
					}
					else {
						make(it, c, b);
						make(it, 2 * b - c, a);
					}
				}
			}
		}
	}
 
	//print(0);
	//print(1);
 
	for (int it = 0; it < 2; it++) {
		auto itr = pos[it].begin();
		ll a = *itr;
		itr++;
		ll b = *itr;
		itr++;
		ll c = *itr;
		itr++;
		ll d = *itr;
 
		if (a == b) {
			if (c != a) {
				make(it, b, c);
			}
			else {
				make(it, b, d);
			}
 
			it--;
			continue;
		}
 
		if (d == b) {
			make(it, b, a);
		}
	}
 
	if (sum(0) != sum(1)) {
		cout << -1 << endl;
		return 0;
	}
 
	int it = 0;
 
	if ((*pos[1].begin()) > (*pos[0].begin())) {
		it = 1;
	}
 
	while ((*pos[it].begin()) - (*pos[it ^ 1].begin()) >= 6) {
		ll d = (*pos[it].begin()) - (*pos[it ^ 1].begin());
		int cnt = 0;
		
		ll x = *pos[it].rbegin();
 
		ll sum = 0;
 
		while (true) {
			ll a = *pos[it].begin();
			ll c = *pos[it].rbegin();
			cnt++;
 
			auto itr = pos[it].rbegin();
 
			while ((*itr) == c) {
				itr++;
			}
 
			ll b = *itr;
 
			sum += c - b;
 
			if (2 * (x - b) + (b - (2 * a - c)) > d) {
				cnt--;
				break;
			}
 
			while (pos[it].count(c)) {
				make(it, c, a);
			}
		}
 
		ll cc = *pos[it].rbegin();
 
		auto itr = pos[it].rbegin();
 
		while ((*itr) == cc) {
			itr++;
		}
 
		ll bb = *itr;
 
		ll ds = d - (x - cc);
		sum += bb - (*pos[it].begin());
		sum -= 2;
		ds -= sum;
		int tp = 0;
 
		while (cnt > 0) {
			ll a = *pos[it].begin();
			ll c = *pos[it].rbegin();
 
			auto itr = pos[it].rbegin();
 
			while ((*itr) == c) {
				itr++;
			}
 
			ll b = *itr;
 
			if (ds >= (c - a)) {
				ds -= (c - a);
				while (pos[it].count(c)) {
					make(it, c, a);
				}
 
				while (pos[it].count(b)) {
					make(it, b, a);
				}
 
				tp ^= 1;
			}
			else {
				cnt--;
				if (tp == 0) {
					ds += (b - a);
					ds += (b - a) - (c - b);
					sum -= b - a;
					while (pos[it].count(a)) {
						make(it, a, b);
					}
				}
				else {
					while (pos[it].count(c)) {
						make(it, c, b);
					}
 
					sum -= c - b;
				}
			}
		}
	}
 
	for (int it = 0; it < 2; it++) {
		auto itr = pos[it].begin();
		ll a = *itr;
		itr++;
		ll b = *itr;
		itr++;
		ll c = *itr;
		itr++;
		ll d = *itr;
 
		if (a == b) {
			if (c != a) {
				make(it, b, c);
			}
			else {
				make(it, b, d);
			}
 
			it--;
			continue;
		}
 
		if (d == b) {
			make(it, b, a);
		}
	}
 
	while ((*pos[0].begin()) != (*pos[1].begin())) {
		int cnt = pos[it].count(*pos[it].rbegin());
		ll x = *pos[it].rbegin();
 
		if (cnt == 1) {
			make(it, x, x - 1);
			make(it, x - 1, x - 2);
		}
		else {
			make(it, x, x - 1);
			make(it, x, x - 1);
			make(it, x - 1, x - 2);
			make(it, x - 2, x - 3);
		}
	}
 
	while (!ans[1].empty()) {
		pll g = ans[1].back();
		ans[1].pop_back();
 
		ans[0].push_back(mp(2 * g.second - g.first, g.second));
	}
 
	if (ans[0].size() > 1000) {
		throw 1;
	}
 
	cout << ans[0].size() << endl;
 
	for (pll g : ans[0]) {
		cout << (g.first) * g0 + sd << ' ' << (g.second) * g0 + sd << endl;
	}
 
	//system("pause");
}