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
#include <memory.h>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;

const int maxn = 1010;
int v[maxn][maxn];

int main() {
	int n;

	cin >> n;

	int x = 0;

	for (int i = 0; i < n; i += 2) {
		for (int j = 0; j < n; j += 2) {
			v[i][j] = x;
			v[i + 1][j] = x + 1;
			v[i][j + 1] = x + 3;
			v[i + 1][j + 1] = x + 2;
			x += 4;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", v[i][j]);
		}

		printf("\n");
	}

	//system("pause");
	return 0;
}