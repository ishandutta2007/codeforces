//#pragma comment(linker, "/STACK:1000000000")
#pragma GCC optimize("Ofast,no-stack-protector")
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
#include <limits.h>
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
#define ld double
#define pll pair <ll, ll>

using namespace std;

const int maxn = (int)2e5 + 10;
int v[maxn];
vector <int> pr[maxn];
multiset<ll> s[maxn];
vector<ll> vals[maxn];

ll get_ans(int n) {
	ll ans = 0;
	int in = -1;
	for (int x : pr[n]) {
		in++;
		ans = max(ans, *s[in].rbegin() * n / x);
	}
	return ans;
}

int main() {
	for (int i = 2; i < maxn; i++) {
		if (pr[i].empty()) {
			for (int j = i; j < maxn; j += i) {
				pr[j].push_back(i);
			}
		}
	}
	
	int t;
	cin >> t;
	while (t--) {
		int n, q;
		scanf("%d %d", &n, &q);
		
		for (int i = 0; i < n; i++) {
			scanf("%d", &v[i]);
		}
		
		int in = -1;
		for (int x : pr[n]) {
			in++;
			s[in].clear();
			vals[in].clear();
			int st = n / x;
			
			for (int i = 0; i < st; i++) {
				ll cur = 0;
				
				for (int j = i; j < n; j += st) {
					cur += v[j];
				}
				s[in].insert(cur);
				vals[in].push_back(cur);
			}
		}
		
		printf("%lld\n", get_ans(n));
		
		while (q--) {
			int p, y;
			scanf("%d %d", &p, &y);
			p--;
			int in = -1;
			for (int x : pr[n]) {
				in++;
				int st = n / x;
				int ps = p % st;
				s[in].erase(s[in].find(vals[in][ps]));
				vals[in][ps] -= v[p];
				vals[in][ps] += y;
				s[in].insert(vals[in][ps]);
			}
			v[p] = y;
			printf("%lld\n", get_ans(n));
		}
	}
}