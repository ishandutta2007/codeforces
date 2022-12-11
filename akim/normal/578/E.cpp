#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <ctime>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define pb push_back
#define ppb pop_back
#define mp make_pair
#define fs first
#define sc second
#define abs(a) ((a) < 0 ? -(a) : (a))
#define sqr(a) ((a) * (a))

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

const double eps = 1e-9;
const int mod = (int)1e+9 + 7;
const double pi = acos(-1.);
const int maxn = 100100;

set<int> l, r;
set<int>::iterator it;
vector<int> ans[2];
int n;
string s;
int go(bool f) {
	bool F = f;
	l.clear();
	r.clear();
	for(int i = 0; i < n; i++) {
		if(s[i] == 'L') {
			l.insert(i + 1);
		} else {
			r.insert(i + 1);
		}
	}
	int ret = 0;
	int pos = 0;
	for(int i = 0; ans[F].size() < n; i++) {
		if(f == 0) {
			it = l.lower_bound(pos);
			if(it != l.end()) {
				int nw = *it;
				l.erase(it);
				ans[F].pb(nw);
				pos = nw;
				f = !f;
			} else {
				pos = 0;
				ret++;
				if(l.empty() || r.empty()) {
				} else {
					int leftl = *l.begin(), leftr = *r.begin();
					if(leftl < leftr) {
					} else {
						r.insert(ans[F].back());
						ans[F].ppb();
						f = !f;
					}
				}
			}
		} else {
			it = r.lower_bound(pos);
			if(it != r.end()) {
				int nw = *it;
				r.erase(it);
				ans[F].pb(nw);
				pos = nw;
				f = !f;
			} else {
				pos = 0;
				ret++;
				if(l.empty() || r.empty()) {
				} else {
					int leftl = *l.begin(), leftr = *r.begin();
					if(leftl < leftr) {
						l.insert(ans[F].back());
						ans[F].ppb();
						f = !f;
					} else {
					}
				}
			}
		}
	}
	return(ret);
}

int main() {

	#ifdef SOL
	{
//		freopen("input.txt","r",stdin);
//		freopen("output.txt","w",stdout);
	}
	#else
	{
		srand(time(0));
		const string file = "";
		if(!file.empty()) {
			freopen((file + ".in").c_str(), "r", stdin);
			freopen((file + ".out").c_str(), "w", stdout);
		}
	}
	#endif

	getline(cin, s);
	n = s.length();
	int cntl = 0, cntr = 0;
	for(int i = 0; i < n; i++) {
		if(s[i] == 'L') {
			cntl++;
		} else {
			cntr++;
		}
	}
	int aans = 0, pans;
	if(n & 1) {
		aans = go(cntl < cntr);
		pans = (cntl < cntr);
	} else {
		int a0 = go(0), a1 = go(1);
		if(a0 < a1) {
			pans = 0;
			aans = a0;
		} else {
			pans = 1;
			aans = a1;
		}
	}

	printf("%d\n", aans);
	for(int i = 0; i < n; i++) {
		printf("%d ", ans[pans][i]);
	}

	return(0);
}

// by Kim Andrey