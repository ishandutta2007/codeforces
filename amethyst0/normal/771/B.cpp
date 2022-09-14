/*AMETHYSTS*/
#pragma comment(linker, "/STACK:1000000000")
#include <cstdio>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#include <deque>
#include <stack>
#include <climits>
#include <string>
#include <queue>
#include <memory.h>
#include <map>
#include <unordered_map>

#define ll long long
#define ld double
#define pii pair <ll, ll>
#define mp make_pair

using namespace std;

const double PI = 3.14159265358979323846;
const int maxn = (int)101;
const ll mod = (ll)1e9 + 7;
const ll inf = (ll)1e9;
const double eps = 1e-9;

int n, m, k;
vector<string> v;
string s;
string ans[maxn];

int main() {

	scanf("%d %d", &n, &k);
	for (int i = 0; i < 26; i++) {
		string tmp = "A";
		tmp += ('a' + i);
		v.push_back(tmp);
	}
	for (int i = 0; i < 26; i++) {
		string tmp = "B";
		tmp += ('a' + i);
		v.push_back(tmp);
	}
	for (int i = 0; i < n; i++) {
		ans[i] = v[i];
	}
	for (int i = 0; i < n - k + 1; i++) {
		cin >> s;
		if (s == "YES") {
			continue;
		}
		ans[i + k - 1] = ans[i];
	}
	for (int i = 0; i < n; i++) {
		cout << ans[i] << ' ';
	}
    return 0;
}