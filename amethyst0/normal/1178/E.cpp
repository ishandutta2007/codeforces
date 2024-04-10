#pragma comment(linker, "/STACK:1000000000")
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

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

string s;
string ans;

void go(int l, int r) {
	if (l > r) {
		cout << ans;
		reverse(ans.begin(), ans.end());
		cout << ans << endl;
		return;
	}

	if (r - l + 1 <= 3) {
		cout << ans;
		cout << s[l];
		reverse(ans.begin(), ans.end());
		cout << ans << endl;
		return;
	}

	for (int i = l; i < l + 2; i++) {
		for (int j = r - 1; j < r + 1; j++) {
			if (s[i] == s[j]) {
				ans.push_back(s[i]);
				go(l + 2, r - 2);
				return;
			}
		}
	}
}

int main() {
	cin >> s;

	go(0, (int)s.size() - 1);

	//system("pause");
}