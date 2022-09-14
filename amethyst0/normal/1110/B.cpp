#pragma comment(linker, "/STACK:1000000000")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>
#include <assert.h>
#include <vector>
#include <cstring>
#include <bitset>
#include <ctime>

using namespace std;

typedef long long ll;
typedef unsigned int ui;
//typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
#define mp make_pair

const int maxn = (int)1e5 + 10;
int b[maxn];

int n, m, k;

int main() {
	cin >> n >> m >> k;

	int total = 0;

	for (int i = 0; i < n; i++) {
		scanf("%d", &b[i]);
	}

	total = b[n - 1] - b[0] + 1;

	int cnt = k - 1;

	vector <int> x;

	for (int i = 1; i < n; i++) {
		x.push_back(b[i] - b[i - 1] - 1);
	}

	sort(x.begin(), x.end());

	while (cnt) {
		total -= x.back();
		x.pop_back();
		cnt--;
	}

	cout << total << endl;

	//system("pause");

	return 0;
}