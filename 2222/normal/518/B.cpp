#include <algorithm>
#include <iostream>
#include <assert.h>
#include <sstream>
#include <complex>
#include <numeric>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

#define all(a)			(a).begin(), (a).end()
#define sz(a)			int((a).size())
#define FOR(i, a, b)	for (int i(a); i < b; ++i)
#define REP(i, n)		FOR(i, 0, n)
#define UN(v)			sort(all(v)), (v).erase(unique((v).begin(), (v).end()), (v).end())
#define CL(a, b)		memset(a, b, sizeof a)
#define pb				push_back
#define X				first
#define Y				second

typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;

int main() {
	for (string s, t; getline(cin, s) && getline(cin, t); ) {
		vector<int> cnt(128);
		for (char c : t)
			cnt[c]++;
		int x = 0, y = 0;
		for (char &c : s) {
			if (cnt[c] > 0) {
				++x;
				--cnt[c];
				c = ' ';
			}
		}
		for (char c : s) {
			if ('a' <= c && c <= 'z')
				c += 'A' - 'a';
			else
				c += 'a' - 'A';
			if (cnt[c] > 0) {
				++y;
				--cnt[c];
			}
		}
		cout << x << ' ' << y << endl;
	}
    return 0;
}