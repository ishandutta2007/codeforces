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

using namespace std;

#define pii pair <int, int>
#define mp make_pair
#define ll long long

const int maxn = (int)1e5 + 10;
char s[maxn];

int main() {
	int n;
	cin >> n;
	scanf("%s", s);

	int z = 0, o = 0;

	for (int i = 0; i < n; i++) {
		if (s[i] == 'z') {
			z++;
		}

		if (s[i] == 'n') {
			o++;
		}
	}

	while (o--) {
		printf("1 ");
	}

	while (z--) {
		printf("0 ");
	}

	//system("pause");

	return 0;
}