#include <functional>
#include <algorithm>
#include <assert.h>
#include <iostream>
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

#define all(a)		(a).begin(), (a).end()

typedef long long ll;

string c4(string s, int a, int b, int c, int d) {
	swap(s[a], s[b]);
	swap(s[b], s[c]);
	swap(s[c], s[d]);
	return s;
}

int main(){
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	string s;
	cin >> s;
	sort(all(s));
	set<string> U;
	do {
		set<string> B;
		queue<string> Q;
		Q.push(s);
		B.insert(s);
		for (; Q.size(); ) {
			string t = Q.front(), w;
			Q.pop();
			w = c4(t, 0, 2, 4, 5);
			if (B.count(w) == 0) {
				B.insert(w);
				Q.push(w);
			}
			w = c4(t, 0, 1, 4, 3);
			if (B.count(w) == 0) {
				B.insert(w);
				Q.push(w);
			}
			w = c4(t, 1, 2, 3, 5);
			if (B.count(w) == 0) {
				B.insert(w);
				Q.push(w);
			}
		}
		U.insert(*B.begin());
	} while (next_permutation(all(s)));
	cout << U.size() << endl;
	return 0;
}