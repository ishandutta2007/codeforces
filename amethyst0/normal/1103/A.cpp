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
char s[maxn];
bool yes[maxn];

int main() {
	scanf("%s", s);

	memset(yes, 0, sizeof yes);

	int n = strlen(s);

	for (int i = 0; i < n; i++) {
		if (s[i] == '0') {
			if (!yes[0]) {
				yes[0] = true;
				cout << 1 << ' ' << 1 << endl;
			}
			else {
				yes[0] = false;
				cout << 3 << ' ' << 1 << endl;
			}
		}
		else {
			if (!yes[1]) {
				yes[1] = true;
				cout << 4 << ' ' << 3 << endl;
			}
			else {
				yes[1] = false;
				cout << 4 << ' ' << 1 << endl;
			}
		}
	}

	//system("pause");
}