#pragma comment(linker, "/STACK:1000000000")
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <ctime>

#define mp make_pair
#define pii pair <int, int>
#define ll long long
#define pll pair <ll, ll>
#define ld double

using namespace std;

const int maxn = (int)2e3 + 10;
char s[maxn];
char t[maxn];
int cnt[26];

int n;

vector <int> ans;

void app(int x) {
	if (x == 0) {
		return;
	}
	reverse(s, s + n);
	reverse(s + x, s + n);
	ans.push_back(x);
}

int main() {
	cin >> n;
	scanf("%s", s);
	scanf("%s", t);

	for (int i = 0; i < n; i++) {
		cnt[s[i] - 'a']++;
		cnt[t[i] - 'a']--;
	}

	for (int i = 0; i < 26; i++) {
		if (cnt[i] != 0) {
			cout << -1 << endl;
			return 0;
		}
	}

	int l = n / 2;
	int r = n / 2;
	bool rev = false;

	for (int i = n - 1; i >= 0; i--) {
		if (s[i] == t[l]) {
			app(n - i);
			app(i);
			app(1);
			break;
		}
	}

	while (!(l == 0 && r == n - 1)) {
		if (!rev) {
			if (l == 0) {
				app(n - (r - l + 1));
				app(r - l + 1);
				rev = !rev;
				continue;
			}
			else {
				for (int i = n - 1; i >= 0; i--) {
					if (s[i] == t[l - 1]) {
						app(n - i);
						app(i - (r - l + 1));
						l--;
						app(r - l + 1);
						rev = !rev;
						break;
					}
				}
			}
		}
		else {
			if (r == n - 1) {
				app(n - (r - l + 1));
				app(r - l + 1);
				rev = !rev;
				continue;
			}
			else {
				for (int i = n - 1; i >= 0; i--) {
					if (s[i] == t[r + 1]) {
						app(n - i);
						app(i - (r - l + 1));
						r++;
						app(r - l + 1);
						rev = !rev;
						break;
					}
				}
			}
		}
	}

	if (rev) {
		app(n);
	}

	for (int i = 0; i < n; i++) {
		if (s[i] != t[i]) {
			throw 1;
		}
	}

	cout << (int)ans.size() << endl;

	for (int i = 0; i < (int)ans.size(); i++) {
		cout << ans[i] << ' ';
	}

	//system("pause");
}