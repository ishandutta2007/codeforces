//#pragma comment(linker, "/STACK:1000000000")
#pragma GCC optimize("Ofast,no-stack-protector")
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
#include <cstdio>
#include <cassert>
#include <cstring>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long 
#define pii pair <int, int>
#define pll pair <ll, ll>
#define ld double

using namespace std;

const int maxn = 45;
char s[maxn];
char t[maxn];

int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		scanf("%d %s", &n, s);
		for (int i = 0; i < n; i++) {
			t[i] = s[i];
		}

		sort(t, t + n);
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] != t[i]) {
				cnt++;
			}
		}

		printf("%d\n", cnt);
	}
}