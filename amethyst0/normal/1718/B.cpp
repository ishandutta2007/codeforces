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

int main() {
	int t;
	cin >> t;
	while (t--) {
		set<pii> s;
		
		int k;
		
		scanf("%d", &k);
		ll tot = 0;
		
		for (int i = 0; i < k; i++) {
			int x;
			scanf("%d", &x);
			tot += x;
			s.insert(mp(x, i));
		}
		
		vector<ll> g;
		
		ll prev = 0;
		ll cur = 1;
		ll sum = 0;
		
		while (sum < tot) {
			g.push_back(cur);
			sum += cur;
			swap(cur, prev);
			cur += prev;
		}
		
		if (sum > tot) {
			printf("NO\n");
			continue;
		}
		
		int last = -1;
		
		bool ok = true;
		
		while (!g.empty()) {
			ll x = g.back();
			g.pop_back();
			
			auto it = s.rbegin();
			while (it != s.rend() && it->second == last) {
				it++;
			}
			
			if (it == s.rend()) {
				ok = false;
				break;
			}
			
			if (it->first < x) {
				ok = false;
				break;
			}
			
			auto [cnt, c] = *it;
			last = c;
			s.erase(*it);
			cnt -= x;
			if (cnt) {
				s.insert(mp(cnt, c));
			}
		}
		
		if (ok) {
			assert(s.empty());
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
}