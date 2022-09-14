//#pragma comment(linker, "/STACK:1000000000")
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
#define ld long double

using namespace std;

const int maxn = (int)2e5 + 10;
int v[maxn];
map <int, int> cnt;
map <int, int> r;

int main() {
	int n, q;

	cin >> n >> q;

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
		cnt[v[i]]++;
		r[v[i]] = i;
	}

	int pos = 0;

	int ans = 0;

	while (pos != n) {
		int rm = pos;
		int ri = r[v[pos]];

		int mins = cnt[v[pos]];
		int tot = cnt[v[pos]];
		set <int> cur;
		cur.insert(v[pos]);

		while (rm <= ri) {
			int x = v[rm];
			rm++;

			if (cur.count(x)) {
				continue;
			}

			cur.insert(x);
			mins = max(mins, cnt[x]);
			tot += cnt[x];
			ri = max(ri, r[x]);
		}

		ans += tot - mins;
		pos = rm;
	}

	cout << ans << endl;

	//system("pause");
}