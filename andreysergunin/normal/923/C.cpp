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

const int maxn = (int)3e5 + 10;

struct point {
	int ed[2];
	int cnt;

	point() {
		ed[0] = ed[1] = -1;
		cnt = 0;
	}
};

point mas[maxn * 20];
int posit = 0;

int my_new() {
	return posit++;
}

void add(int t, int x, int pos) {
	mas[t].cnt++;

	if (pos == -1) {
		return;
	}

	int b = (x >> pos) & 1;

	if (mas[t].ed[b] == -1) {
		mas[t].ed[b] = my_new();
	}

	add(mas[t].ed[b], x, pos - 1);
}

int a[maxn];

int go(int t, int x, int pos) {
	mas[t].cnt--;
	if (pos == -1) {
		return 0;
	}

	int b = (x >> pos) & 1;

	if (mas[t].ed[b] != -1 && mas[mas[t].ed[b]].cnt != 0) {
		int ans = go(mas[t].ed[b], x, pos - 1);

		if (b == 1) {
			ans += (1 << pos);
		}

		return ans;
	}

	b ^= 1;

	int ans = go(mas[t].ed[b], x, pos - 1);

	if (b == 1) {
		ans += (1 << pos);
	}

	return ans;
}

int main() {
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		//a[i] = 1;
	}

	int t = my_new();

	for (int i = 0; i < n; i++) {
		int x;

		scanf("%d", &x);
		//x = 1;

		add(t, x, 29);
	}

	for (int i = 0; i < n; i++) {
		int z = go(t, a[i], 29);

		printf("%d ", z ^ a[i]);
	}

	//system("pause");
}