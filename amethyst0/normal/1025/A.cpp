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
#include <ctime>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned int ui;
//typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
#define mp make_pair

const int maxn = (int)1e5 + 10;
char s[maxn];
int cnt[26];

int main() {
	int n;
	cin >> n;
	scanf("%s", s);

	int diff = 0;

	for (int i = 0; i < n; i++) {
		cnt[s[i] - 'a'] += 1;
	}

	for (int i = 0; i < 26; i++) {
		if (cnt[i] != 0) {
			diff += 1;
		}

		if (cnt[i] > 1) {
			printf("Yes");
			return 0;
		}
	}

	if (diff == 1) {
		printf("Yes");
	}
	else {
		printf("No");
	}
	//system("pause");
}