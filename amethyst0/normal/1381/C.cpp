#pragma comment(linker, "/STACK:1000000000")
#pragma GCC optimize("Ofast,no-stack-protector")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <cassert>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <ctime>
#include <random>
#include <bitset>
#include <limits.h>
#include <fstream>

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define pll pair <ll, ll>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
#define uint unsigned int
#define mp make_pair

const int maxn = (int)1e5 + 10;
int cnt[maxn];
vector <int> pos[maxn];
int ans[maxn];
bool used[maxn];

void print(int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", ans[i] + 1);
	}

	printf("\n");
}

int main() {
	int t;

	cin >> t;

	while (t--) {
		int n, x, y;

		scanf("%d %d %d", &n, &x, &y);
		int del = n - y;
		y -= x;

		for (int i = 0; i <= n; i++) {
			cnt[i] = 0;
			pos[i].clear();
			used[i] = false;
		}

		for (int i = 0; i < n; i++) {
			ans[i] = -1;
			int g;
			scanf("%d", &g);
			g--;
			used[g] = true;
			cnt[g]++;
			pos[g].push_back(i);
		}

		int cl = 0;

		while (used[cl]) {
			cl++;
		}

		set <pii> s;

		for (int i = 0; i <= n; i++) {
			if (cnt[i]) {
				s.insert(mp(cnt[i], i));
			}
		}

		while (x--) {
			pii f = (*s.rbegin());
			s.erase(f);

			ans[pos[f.second].back()] = f.second;
			pos[f.second].pop_back();
			f.first--;
			if (f.first) {
				s.insert(f);
			}
		}

		while (!s.empty() && (*s.rbegin()).first * 2 > y + del) {
			del--;
			pii f = (*s.rbegin());
			s.erase(f);

			ans[pos[f.second].back()] = cl;
			pos[f.second].pop_back();
			f.first--;
			if (f.first) {
				s.insert(f);
			}
		}

		if (del < 0) {
			printf("NO\n");
			continue;
		}
		else {
			printf("YES\n");
		}

		if (s.empty()) {
			print(n);
			continue;
		}

		set <pair <pii, int> > q;

		int pr = s.rbegin()->second;

		for (auto[x, y] : s) {
			if (y == pr) {
				q.insert(mp(mp(x, 1), y));
			}
			else {
				q.insert(mp(mp(x, 0), y));
			}
		}

		vector <int> poses;

		for (int i = 0; i < n; i++) {
			if (del && ans[i] == -1) {
				poses.push_back(i);
				del--;
			}
		}

		int cur = pr;
		int pl = pos[cur].back();
		pos[cur].pop_back();
		pair <pii, int> f = *q.rbegin();
		q.erase(f);
		f.first.first--;
		if (f.first.first) {
			q.insert(f);
		}

		while (!q.empty()) {
			pair <pii, int> f = *q.rbegin();
			q.erase(f);

			if (f.second == cur) {
				pair <pii, int> nx = *q.rbegin();
				assert(!q.empty());
				q.erase(nx);
				q.insert(f);
				f = nx;
			}

			ans[pos[f.second].back()] = cur;
			pos[f.second].pop_back();
			cur = f.second;
			f.first.first--;

			if (f.first.first) {
				q.insert(f);
			}
		}

		assert(cur != pr);
		ans[pl] = cur;

		for (int p : poses) {
			ans[p] = cl;
		}

		print(n);
	}
}