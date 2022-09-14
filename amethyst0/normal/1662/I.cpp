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
int p[maxn];
ll x[maxn];

int main() {
	int n, m;
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &p[i]);
	}
	
	ll ans = 0;

	for (int i = 0; i < m; i++) {
		scanf("%lld", &x[i]);
	}
	
	sort(x, x + m);
	
	ll cur = 0;
	
	for (int i = 0; i < n; i++) {
		if (100 * i < x[0]) {
			cur += p[i];
		}
	}
	
	ans = cur;
	cur = 0;
	
	for (int i = 0; i < n; i++) {
		if (100 * i > x[m - 1]) {
			cur += p[i];
		}
	}
	
	ans = max(ans, cur);
	
	int pos = 0;
	
	for (int i = 0; i < m - 1; i++) {
		ll l = x[i];
		ll r = x[i + 1];
		
		while (pos < n && 100 * pos <= l) {
			pos++;
		}
		
		queue<pair<ll, ll>> q;
		ll sum = 0;
		
		while (pos < n && 100 * pos < r) {
			ll lm = 100 * pos - (r - 100 * pos);
			lm = max(lm, l);
			ll rm = 100 * pos + (100 * pos - l);
			rm = min(rm, r);
			if (lm >= rm) {
				pos++;
				continue;
			}
			
			while (!q.empty() && q.front().second <= lm) {
				sum -= q.front().first;
				q.pop();
			}
			
			sum += p[pos];
			ans = max(ans, sum);
			q.push(mp(p[pos], rm));
			pos++;
		}
	}
	
	cout << ans << '\n';
}