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
#include <random>
#include <bitset>
#include <cstring>
#include <memory.h>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <memory.h>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long 
#define pii pair <int, int>
#define pll pair <ll, ll>
#define ld double

using namespace std;

const int maxn = (int)2e5 + 10;
int v[maxn];

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		scanf("%d", &n);
		map <int, int> cnt;
		for (int i = 0; i < n; i++) {
			scanf("%d", &v[i]);
			cnt[v[i]]++;
		}

		vector <int> ans;

		int p = 0;
		while (p < n) {
			set <int> cur;
			int x = 0;

			if (cnt[0] == 0) {
				ans.push_back(0);
				p++;
				continue;
			}

			while (p < n && cnt[x] > 0) {
				cnt[v[p]]--;
				cur.insert(v[p]);
				p++;
				while (cur.count(x)) {
					x++;
				}
			}

			ans.push_back(x);
		}

		printf("%d\n", (int)ans.size());

		for (int x : ans) {
			printf("%d ", x);
		}
		printf("\n");
	}
}