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
#define ld long double

using namespace std;

const int maxn = (int)2e5 + 10;
int v[maxn];
char s[maxn];
int l[10], r[10];
int cl[maxn];

int main() {
	int t;

	cin >> t;

	while (t--) {
		int n;

		cin >> n;

		scanf("%s", s);

		for (int i = 0; i < 10; i++) {
			l[i] = n;
			r[i] = -1;
		}

		for (int i = 0; i < n; i++) {
			v[i] = s[i] - '0';
			l[v[i]] = min(l[v[i]], i);
			r[v[i]] = i;
		}

		for (int i = 8; i >= 0; i--) {
			l[i] = min(l[i], l[i + 1]);
		}

		for (int i = 1; i < 10; i++) {
			r[i] = max(r[i], r[i - 1]);
		}

		bool gd = false;

		for (int c = 0; c < 10; c++) {
			bool fl = true;
			int lst1 = -1;
			int lst2 = -1;

			for (int i = 0; i < n; i++) {
				if (v[i] < c) {
					cl[i] = 1;
					if (lst1 > v[i]) {
						fl = false;
						break;
					}

					lst1 = v[i];
				}
				else if (v[i] > c) {
					cl[i] = 2;
					if (lst2 > v[i]) {
						fl = false;
						break;
					}

					lst2 = v[i];
				}
				else {
					if (c == 0 || r[c - 1] < i) {
						cl[i] = 1;
					}
					else if (c == 9 || l[c + 1] > i) {
						cl[i] = 2;
					}
					else {
						fl = false;
						break;
					}
				}
			}

			if (fl) {
				gd = true;

				for (int i = 0; i < n; i++) {
					printf("%d", cl[i]);
				}

				printf("\n");
				break;
			}
		}

		if (!gd) {
			printf("-\n");
		}
	}
	
	//system("pause");
}