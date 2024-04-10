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

int n, k;
char s[100500];

int main() {
	cin >> n >> k >> s;
	int i = 0;
	for (; k > 0; ) {
		if (s[i] == 0 || s[i + 1] == 0) break;
		if (s[i] == '4' && s[i + 1] == '7') {
			if (i % 2) {
				s[i] = '7';
				--k;
				if (i) {
					--i;
					if (s[i] == '4') {
						k %= 2;
					}
				}
			} else {
				s[i + 1] = '4';
				--k;
			}
		} else ++i;
	}
	puts(s);
	return 0;
}