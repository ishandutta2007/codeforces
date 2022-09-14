#pragma comment(linker, "/STACK:1000000000")
#pragma GCC optimize("Ofast,no-stack-protector")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <cassert>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <ctime>
#include <random>
#include <bitset>
#include <limits.h>
#include <fstream>

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define pll pair <ll, ll>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
#define uint unsigned int

const int maxn = (int)2e5 + 10;
char s[maxn];
int cnt[26];
int lnk[maxn];
int numb[26];

void write(int l, int r, int st) {
	if (l > r) {
		return;
	}

	int d = 0;
	int pos = l;

	while (lnk[pos] != -1) {
		d++;
		write(pos + 1, lnk[pos] - 1, st + d);
		pos = lnk[pos];
	}

	printf("%d %d\n", st, st + d);
	write(pos + 1, r, st);
}

int main() {
	int t;

	cin >> t;

	while (t--) {
		scanf("%s", s);
		int n = 0;

		while (s[n]) {
			lnk[n] = -1;
			n++;
		}
		
		vector <int> st;
		vector <pii> num;

		memset(cnt, 0, sizeof cnt);
		memset(numb, 0, sizeof numb);
		int sum = 0;

		for (int i = 0; i < n - 1; i++) {
			if (s[i] == s[i + 1]) {
				cnt[s[i] - 'a']++;
				sum++;
			}
		}

		int ans = (sum + 1) / 2;

		for (int i = 0; i < 26; i++) {
			ans = max(ans, cnt[i]);
		}

		int tot = 0;

		for (int i = 0; i < n; i++) {
			if (!st.empty()) {
				if (s[st.back()] != s[i]) {
					lnk[st.back()] = i;
					st.pop_back();
					if (num.back().second > 1) {
						numb[num.back().first]--;
					}

					num.back().second--;

					if (num.back().second == 0) {
						num.pop_back();
					}

					st.push_back(i);
					if (!num.empty() && num.back().first == s[i] - 'a') {
						num.back().second++;
						numb[s[i] - 'a']++;
					}
					else {
						num.push_back(mp(s[i] - 'a', 1));
					}
				}
				else if ((int)num.size() == 1) {
					num.back().second++;
					st.push_back(i);
					numb[s[i] - 'a']++;
				}
				else {
					numb[num.back().first] -= num.back().second - 1;
					for (int j = 0; j < 26; j++) {
						numb[j] += cnt[j];
					}

					int cur = 0;
					sum = 0;

					for (int j = 0; j < 26; j++) {
						sum += numb[j];
						cur = max(cur, numb[j]);
					}

					for (int j = 0; j < 26; j++) {
						numb[j] -= cnt[j];
					}

					cur = max(cur, (sum + 1) / 2);
					tot += num.back().second;

					if (tot + cur == ans) {
						while (num.back().second) {
							num.back().second--;
							st.pop_back();
						}

						num.pop_back();
						if (num.back().second > 1) {
							numb[num.back().first]--;
						}

						num.back().second--;
						lnk[st.back()] = i;
						st.pop_back();
						if (num.back().second == 0) {
							num.pop_back();
						}

						st.push_back(i);

						if (!num.empty() && num.back().first == s[i] - 'a') {
							num.back().second++;
							numb[s[i] - 'a']++;
						}
						else {
							num.push_back(mp(s[i] - 'a', 1));
						}
					}
					else {
						tot -= num.back().second;
						numb[num.back().first] += num.back().second - 1;
						numb[s[i] - 'a']++;
						num.back().second++;
						st.push_back(i);
					}
				}
			}
			else {
				st.push_back(i);
				num.push_back(mp(s[i] - 'a', 1));
			}

			if (i != n - 1 && s[i] == s[i + 1]) {
				cnt[s[i] - 'a']--;
			}
		}

		cout << ans + 1 << '\n';

		ans++;
		for (int i = 0; i < n; i++) {
			if (lnk[i] == -1) {
				ans--;
			}
		}

		assert(ans == 0);

		write(0, n - 1, 1);
	}
}