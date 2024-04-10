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

const int maxn = (int)5e5 + 10;
char s[maxn];

int main() {
	scanf("%s", s);

	int mins = 26;

	int n = strlen(s);

	for (int i = 0; i < n; i++) {
		int x = s[i] - 'a';

		if (x > mins) {
			printf("Ann\n");
		}
		else {
			printf("Mike\n");
		}

		mins = min(mins, x);
	}

	//system("pause");

	return 0;
}