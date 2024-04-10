/*AMETHYSTS*/
#pragma comment(linker, "/STACK:1000000000")
#include <cstdio>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#include <deque>
#include <stack>
#include <climits>
#include <string>
#include <numeric>
#define mp make_pair
#define pii pair <int, int>
#define ll long long
#define ui unsigned int
#define ld double
#define pll pair <ll, ll> 

using namespace std;

char s[110][110];
int p[110];

bool gl(char c) {
	return c == 'a' || c == 'e' || c == 'y' || c == 'u' || c == 'i' || c == 'o';
}

int main() {
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		scanf("%d", &p[i]);
	}

	scanf(" ");

	for (int i = 0; i < n; i++) {
		gets(s[i]);

		int sum = 0;

		int len = strlen(s[i]);

		for (int j = 0; j < len; j++) {
			if (gl(s[i][j])) {
				sum++;
			}
		}

		if (sum != p[i]) {
			printf("NO\n");
			return 0;
		}
	}

	printf("YES\n");

	return 0;
}