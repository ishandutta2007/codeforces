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

const int maxn = 110;
int v[maxn];
bool used[maxn];

int main() {
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int ans = 0;

	while (true) {
		int ps = -1;

		for (int i = 0; i < n; i++) {
			if (used[i]) {
				continue;
			}

			if (ps == -1 || v[ps] > v[i]) {
				ps = i;
			}
		}

		if (ps == -1) {
			break;
		}

		ans++;

		for (int i = 0; i < n; i++) {
			if (v[i] % v[ps] == 0) {
				used[i] = true;
			}
		}
	}

	cout << ans << endl;

	//system("pause");
}