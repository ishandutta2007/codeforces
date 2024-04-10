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
char s[maxn];
int a[maxn], b[maxn];

int main() {
	int n;

	cin >> n;

	cin >> s;

	for (int i = 0; i < n; i++) {
		v[i] = s[i] - '0';
	}

	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
	}

	int ans = 0;

	for (int i = 0; i < n; i++) {
		ans += v[i];
	}

	for (int tm = 1; tm < 100000; tm++) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (tm >= b[i] && (tm - b[i]) % a[i] == 0) {
				v[i] ^= 1;
			}

			if (v[i] == 1) {
				cnt++;
			}
		}

		ans = max(ans, cnt);
	}

	cout << ans << endl;

	//system("pause");
}