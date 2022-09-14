/*AMETHYSTS*/
#pragma comment(linker, "/STACK:1000000000")
#include <cstdio>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#include <deque>
#include <stack>
#include <climits>
#include <string>
#include <queue>
#include <memory.h>

#define pb push_back
#define mp make_pair
#define uint unsigned int
#define ll long long
#define pii pair <int, int> 
#define ld double
#define pll pair <ll, ll>

using namespace std;

const int maxn = (int)1e5 + 10;

pair <int, pii> v[maxn];

bool cmp(pair <int, pii> a, pair <int, pii> b) {
	return a.second.first - a.second.second > b.second.first - b.second.second;
}

int n;

ll num;
int s;

ll check(ll a) {
	if (a / s > (num + s - 1) / s) {
		return 0;
	}

	ll b = ((num + s - 1) / s) * s - a;

	if (b < 0) {
		return 0;
	}

	ll ans = 0;

	int p1 = 0;

	while (p1 < n && v[p1].first <= a && v[p1].second.first >= v[p1].second.second) {
		ans += (ll)v[p1].first * v[p1].second.first;
		a -= v[p1].first;
		p1++;
	}

	int p2 = n - 1;

	while (p2 >= 0 && v[p2].first <= b && v[p2].second.first < v[p2].second.second) {
		ans += (ll)v[p2].first * v[p2].second.second;
		b -= v[p2].first;
		p2--;
	}

	ll res = 0;

	for (int i = p1; i <= p2; i++) {
		if (a <= v[i].first) {
			res += a * v[i].second.first;
			res += (v[i].first - a) * v[i].second.second;
			a = 0;
		} else {
			res += (ll)v[i].first * v[i].second.first;
			a -= v[i].first;
		}
	}

	ll res1 = 0;

	for (int i = p2; i >= p1; i--) {
		if (b <= v[i].first) {
			res1 += b * v[i].second.second;
			res1 += (v[i].first - b) * v[i].second.first;
			b = 0;
		} else {
			res1 += (ll)v[i].first * v[i].second.second;
			b -= v[i].first;
		}
	}

	return ans + max(res1, res);
}

int main() {
	cin >> n >> s;
	
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &v[i].first, &v[i].second.first, &v[i].second.second);
		num += v[i].first;
	}

	sort(v, v + n, cmp);

	ll z = 0;

	for (int i = 0; i < n; i++) {
		if (v[i].second.first >= v[i].second.second) {
			z += v[i].first;
		}
	}

	cout << max(check((z / s) * s), check(((z + s - 1) / s) * s)) << endl;

	return 0;
}