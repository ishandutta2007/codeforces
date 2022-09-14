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

const int maxn = (int)2e5 + 10;

int v[maxn];

int main() {
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}

	ll cur = 0;

	for (int i = 0; i < n; i++) {
		ll x = cur + v[i];

		printf("%lld ", x);
		cur = max(cur, x);
	}
}