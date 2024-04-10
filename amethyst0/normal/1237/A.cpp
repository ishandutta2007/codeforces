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
#define ld double

using namespace std;

const int maxn = (int)1e5 + 10;

int v[maxn];

int main() {
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int cnt = 0;

	for (int i = 0; i < n; i++) {
		if (v[i] % 2 == 0) {
			cout << v[i] / 2 << '\n';
		}
		else if (cnt == 0) {
			cout << (v[i] + 1) / 2 << '\n';
			cnt ^= 1;
		}
		else {
			cnt ^= 1;
			cout << (v[i] - 1) / 2 << '\n';
		}
	}

	//system("pause");
	return 0;
}