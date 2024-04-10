#pragma comment(linker, "/STACK:1000000000")
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <ctime>

#define mp make_pair
#define pii pair <int, int>
#define ll long long
#define pll pair <ll, ll>
#define ld long double

using namespace std;

const int maxn = (int)110;

int v[maxn];
bool used[maxn];
int n;

int go(int x) {
	int cnt = 0;
	int tm = 0;

	for (int i = 0; i < n; i++) {
		if (!used[i] && tm + v[i] <= x) {
			tm += v[i];
			cnt++;
		}
	}

	return cnt;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}

	sort(v, v + n);

	int cnt = 0;
	int tm = 0;

	for (int i = 0; i < n; i++) {
		if (tm + v[i] <= 710) {
			cnt++;
			tm += v[i];
		}
	}

	cout << cnt << ' ';

	int best = (int)1e9;

	for (int e = tm; e >= 0; e--) {
		memset(used, 0, sizeof used);
		int cur = 0;

		if (go(e) != cnt) {
			break;
		}

		int num = 0;

		int f = e;

		while (num != cnt) {
			for (int i = n - 1; i >= 0; i--) {
				if (!used[i]) {
					used[i] = true;
					if (go(e - v[i]) + num + 1 == cnt) {
						if (e >= 350) {
							cur += e - 350;
							e -= v[i];
							break;
						}
					}
					else {
						used[i] = false;
					}
				}
			}

			num++;
		}

		if (cur < best) {
			best = cur;
		}

		e = f;
	}

	cout << best << endl;

	//system("pause");
}