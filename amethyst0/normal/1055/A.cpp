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
#include <random>
//#include <priority_queue>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define ld long double
#define pii pair <int, int>
#define ll long long
#define pll pair <ll, ll>

using namespace std;

const int maxn = 1010;
int a[maxn], b[maxn];

int main() {
	int n, s;

	cin >> n >> s;

	s--;

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	for (int i = 0; i < n; i++) {
		scanf("%d", &b[i]);
	}

	if (a[0] == 0) {
		cout << "NO" << endl;
	}
	else if (a[s] == 1) {
		cout << "YES" << endl;
	}
	else {
		bool fl = true;
		for (int i = s + 1; i < n; i++) {
			if (a[i] == 1 && b[s] == 1 && b[i] == 1) {
				cout << "YES" << endl;
				fl = false;
				break;
			}
		}

		if (fl) {
			cout << "NO" << endl;
		}
	}

	//system("pause");
}