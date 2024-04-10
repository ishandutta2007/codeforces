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
#include <memory.h>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <memory.h>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long 
#define pii pair <int, int>
#define pll pair <ll, ll>
#define ld double

using namespace std;

const int maxn = (int)1e5 + 10;
char s[maxn];
int cnt[26];
int buf[26];

int main() {
	int t;
	cin >> t;
	while (t--) {
		scanf("%s", s);
		int n = strlen(s);

		int tot = 0;

		for (int i = 0; i < 26; i++) {
			cnt[i] = 0;
		}

		for (int i = 0; i < n; i++) {
			int c = s[i] - 'a';
			if (!cnt[c]) {
				tot++;
			}
			cnt[c]++;
		}

		if (tot == 1) {
			printf("%s\n", s);
			continue;
		}

		int a = 0;
		while (!cnt[a]) {
			a++;
		}

		int b = a + 1;
		string res = "";

		for (int i = 0; i < 26; i++) {
			if (cnt[i] == 1) {
				cnt[i]--;
				res.push_back('a' + i);
				break;
			}
		}

		if (!res.empty()) {
			for (int i = 0; i < 26; i++) {
				while (cnt[i]) {
					res.push_back('a' + i);
					cnt[i]--;
				}
			}

			printf("%s\n", res.c_str());
			continue;
		}

		if (cnt[a] - 2 <= n - cnt[a]) {
			// 1
			res.push_back('a' + a);
			res.push_back('a' + a);
			cnt[a] -= 2;

			while (cnt[a]) {
				while (!cnt[b]) {
					b++;
				}

				res.push_back('a' + b);
				cnt[b]--;
				res.push_back('a' + a);
				cnt[a]--;
			}

			for (int i = b; i < 26; i++) {
				while (cnt[i]) {
					res.push_back('a' + i);
					cnt[i]--;
				}
			}

			printf("%s\n", res.c_str());
		}
		else if (tot >= 3) {
			// 1
			res.push_back('a' + a);
			cnt[a]--;
			while (!cnt[b]) {
				b++;
			}

			cnt[b]--;
			res.push_back('a' + b);
			while (cnt[a]) {
				res.push_back('a' + a);
				cnt[a]--;
			}

			int c = b + 1;
			while (!cnt[c]) {
				c++;
			}

			res.push_back('a' + c);
			cnt[c]--;

			for (int i = b; i < 26; i++) {
				while (cnt[i]) {
					res.push_back('a' + i);
					cnt[i]--;
				}
			}

			printf("%s\n", res.c_str());
		}
		else {
			res.push_back('a' + a);
			cnt[a]--;

			while (!cnt[b]) {
				b++;
			}

			while (cnt[b]) {
				res.push_back('a' + b);
				cnt[b]--;
			}

			while (cnt[a]) {
				res.push_back('a' + a);
				cnt[a]--;
			}

			printf("%s\n", res.c_str());
		}
	}
}