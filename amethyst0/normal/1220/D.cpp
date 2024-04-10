#pragma comment(linker, "/STACK:1000000000")
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <memory.h>
#include <cstring>
#include <queue>
#include <set>
#include <string>

using namespace std;

#define pii pair <int, int>
#define mp make_pair
#define ll long long

const int maxn = (int)2e5 + 10;
ll v[maxn];
ll buf[maxn];

ll ans;
vector <ll> res;

vector <ll> num;

void solve(int n, ll st = 1) {
	if (n == 0) {
		return;
	}

	int l = 0;
	int r = n - 1;

	for (int i = 0; i < n; i++) {
		if (v[i] % 2 == 0) {
			buf[l++] = v[i];
		}
		else {
			buf[r--] = v[i];
		}
	}

	vector <ll> cur;

	for (int i = 0; i < n; i++) {
		v[i] = buf[i];
	}

	for (int i = 0; i < n; i++) {
		if (v[i] % 2 == 1) {
			break;
		}

		cur.push_back(v[i] * st);
	}

	if ((int)cur.size() + (int)num.size() < ans) {
		ans = (int)cur.size() + (int)num.size();
		res = cur;
		for (int i = 0; i < (int)num.size(); i++) {
			res.push_back(num[i]);
		}
	}

	for (int i = (int)cur.size(); i < n; i++) {
		num.push_back(v[i] * st);
	}

	for (int i = 0; i < (int)cur.size(); i++) {
		v[i] /= 2;
	}
	
	solve((int)cur.size(), st * 2);
}

int main() {
	int n;

	cin >> n;

	int num = 0;

	for (int i = 0; i < n; i++) {
		scanf("%lld", &v[i]);
	}

	ans = n + 1;
	solve(n);

	cout << ans << endl;

	for (int i = 0; i < (int)res.size(); i++) {
		printf("%lld ", res[i]);
	}

	//system("pause");

	return 0;
}