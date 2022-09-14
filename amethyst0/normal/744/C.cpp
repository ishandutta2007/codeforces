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
//#include <unordered_map>
//#include <random>
//#include <unordered_set>

#define ll long long
#define ld long double
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair
#define ui unsigned ll
#define pll pair <ll, ll>

using namespace std;

const int maxn = 16;
int n;
pair <char, pii> v[maxn];

int get_ans() {
	int x = 0;
	int y = 0;
	int sum = 0;
	int a = 0;
	int b = 0;

	for (int i = 0; i < n; i++) {
		int suma = max(0, v[i].second.first - a);
		int sumb = max(0, v[i].second.second - b);

		int cnt = max(suma - x, sumb - y);

		sum += cnt;
		x += cnt;
		y += cnt;

		x -= suma;
		y -= sumb;

		if (v[i].first == 'R') {
			a++;
		} else {
			b++;
		}
	}

	return sum;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		scanf(" %c %d %d", &v[i].first, &v[i].second.first, &v[i].second.second);
		/*v[i].first = 'R';
		
		if (rand() & 1) {
		    v[i].first = 'B';
		}
		
		v[i].second = mp(rand(), rand());*/
	}

	int ans = (int)1e9;
	int best = ans;

	for (ld t = 1; t < 60; t += 0.00001) {
		int x, y;

		x = rand() % n;
		y = rand() % n;

		swap(v[x], v[y]);

		int now = get_ans();
		best = min(now, best);

		if (now < ans || exp((ans - now) * t) * RAND_MAX >= rand()) {
			ans = now;
		} else {
			swap(v[x], v[y]);
		}
	}

	cout << best + n << endl;

	return 0;
}