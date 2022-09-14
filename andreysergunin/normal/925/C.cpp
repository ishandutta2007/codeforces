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
#define ld double

using namespace std;

const int maxn = (int)1e5 + 10;
ll v[maxn];
bool used[maxn];

int g[maxn];

int main() {
	int n;

	cin >> n;

	int pre = 0;

	for (int i = 0; i < n; i++) {
		g[i] = pre + rand() % 15;
		pre = g[i];
	}

	for (int i = 0; i < n; i++) {
		scanf("%lld", &v[i]);
		/*if (i == 0) {
			v[i] = g[i];
		}
		else {
			v[i] = g[i] ^ g[i - 1];
		}*/
	}

	//random_shuffle(v, v + n);

	vector <ll> f;

	for (int b = 59; b >= 0; b--) {
		vector <ll> cur;

		for (int i = 0; i < n; i++) {
			if (!used[i] && ((v[i] >> b) & 1)) {
				used[i] = true;
				cur.push_back(v[i]);
			}
		}

		vector <ll> now;

		int pos = 0;

		for (int i = 0; i < (int)cur.size(); i++) {
			while (pos != (int)f.size() && ((f[pos] >> b) & 1) == 0) {
				now.push_back(f[pos]);
				pos++;
			}

			if (pos == (int)f.size()) {
				if (i + 1 == (int)cur.size()) {
					now.push_back(cur[i]);
				}
				else {
					printf("No\n");
					//throw 1;
					return 0;
				}
			}
			else {
				now.push_back(cur[i]);
				now.push_back(f[pos++]);
			}
		}

		while (pos != (int)f.size()) {
			now.push_back(f[pos++]);
		}

		f = now;
	}

	printf("Yes\n");

	ll last = 0;

	for (int i = 0; i < (int)f.size(); i++) {
		if (last > (last ^ f[i])) {
			throw 1;
		}

		last ^= f[i];

		printf("%lld ", f[i]);
	}

	printf("\n");
	
	//system("pause");
	return 0;
}