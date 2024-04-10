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
#include <cstdio>
#include <cassert>
#include <cstring>
#include <unordered_set>

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
int n;

vector <int> ans;

void make(int pos) {
	assert(pos <= n - 3);
	int x = v[pos] ^ v[pos + 1] ^ v[pos + 2];
	v[pos] = v[pos + 1] = v[pos + 2] = x;
}

void solve(int l, int r) {
	if (r - l + 1 < 3) {
		assert(v[l] == 0 && v[r] == 0);
		return;
	}

	if (v[l] == 0) {
		if (v[l + 1] == 0) {

		}
		else if (v[l + 2] == 1) {
			ans.push_back(l);
			make(l);
		}
		else {
			ans.push_back(l + 1);
			make(l + 1);
			if (v[l + 1] == 1) {
				ans.push_back(l);
				make(l);
			}
		}
		solve(l + 1, r);
	}
	else {
		assert(v[r] == 0);
		if (v[r - 1] == 0) {

		}
		else if (v[r - 2] == 1) {
			ans.push_back(r - 2);
			make(r - 2);
		}
		else {
			ans.push_back(r - 3);
			make(r - 3);
			if (v[r - 1] == 1) {
				ans.push_back(r - 2);
				make(r - 2);
			}
		}
		solve(l, r - 1);
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		ans.clear();
		scanf("%d", &n);
		//n = rand() % 7 + 3;
		int s = 0;

		for (int i = 0; i < n; i++) {
			scanf("%d", &v[i]);
			//v[i] = rand() & 1;
			s ^= v[i];
		}

		if (s) {
			printf("NO\n");
			continue;
		}

		int num = 0;

		bool ok = false;

		for (int i = 0; i < n; i++) {
			if (v[i] == 1) {
				num ^= 1;
			}
			else {
				if (num == 0) {
					solve(0, i);
					solve(i, n - 1);
					ok = true;
					break;
				}
			}
		}

		if (!ok) {
			int last = 0;

			for (int i = 1; i < n; i++) {
				if (v[i] == 1) {
					if ((i - last) % 2 == 0) {
						for (int j = last; j + 2 < i - 1; j += 2) {
							ans.push_back(j);
							make(j);
						}

						for (int j = i; j - 2 >= last; j -= 2) {
							ans.push_back(j - 2);
							make(j - 2);
						}

						solve(0, last);
						solve(i, n - 1);
						ok = true;
						break;
					}

					last = i;
				}
			}
		}

		if (!ok) {
			printf("NO\n");
			continue;
		}

		printf("YES\n");

		printf("%d\n", (int)ans.size());
		assert((int)ans.size() <= n);

		for (int x : ans) {
			printf("%d ", x + 1);
		}
		for (int i = 0; i < n; i++) {
			assert(v[i] == 0);
		}
		printf("\n");
	}
}