#pragma comment(linker, "/STACK:1000000000")
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
#include <limits.h>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

const int maxn = (int)1e5 + 10;

int v[2 * maxn];

int main() {
	int n;

	cin >> n;

	if (n % 2 == 0) {
		cout << "NO" << endl;
		return 0;
	}

	int pos = n;

	for (int i = 0; i < n; i++) {
		v[2 * i] = 2 * i + 1;
		v[pos] = 2 * i + 2;
		pos += 2;
		pos %= 2 * n;
	}

	cout << "YES" << endl;

	for (int i = 0; i < 2 * n; i++) {
		printf("%d ", v[i]);
	}

	//system("pause");
}