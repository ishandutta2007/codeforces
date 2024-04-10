//#pragma comment(linker, "/STACK:1000000000")
//#pragma GCC optimize("Ofast,no-stack-protector")
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
#define pll pair <ll, ll>
#define ld double

using namespace std;

const int maxn = (int)2010;
char s[maxn];

vector <pii> ans;

void rev(int l, int r) {
	ans.push_back(mp(l + 1, r + 1));
	reverse(s + l, s + r + 1);
}

int main() {
	int t;

	cin >> t;

	while (t--) {
		ans.clear();
		int n, k;
		scanf("%d %d", &n, &k);

		scanf("%s", s);
		int cnt = n / 2 - k + 1;

		for (int i = 0; i < n; i++) {
			if (i < cnt || (i >= 2 * cnt && (i - 2 * cnt) % 2 == 0)) {
				int pos = -1;

				for (int j = i; j < n; j++) {
					if (s[j] == '(') {
						pos = j;
						break;
					}
				}

				rev(i, pos);
			}
			else {
				int pos = -1;

				for (int j = i; j < n; j++) {
					if (s[j] == ')') {
						pos = j;
						break;
					}
				}

				rev(i, pos);
			}
		}

		printf("%d\n", ans.size());

		//cout << "!" << s << endl;

		for (int i = 0; i < (int)ans.size(); i++) {
			printf("%d %d\n", ans[i].first, ans[i].second);
		}
	}

	//system("pause");
}