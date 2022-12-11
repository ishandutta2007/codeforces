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
#if __cplusplus > 199711L
#include <unordered_set>
#include <unordered_map>
#include <tuple>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
/*tree<key, mapped = null_type, cmp = less<key>, rb_tree_tag, tree_order_statistics_node_update> name;*/
#endif

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
const int maxn = 5 * 100100;

bool del[maxn];
string s, t;
int n, zap;
int pa[maxn];
int st[maxn], sz;

bool goR(int p) {
	p++;
	if(p == n) return(0);
	while(del[p]) {
		p = pa[p];
		p++;
		if(p == n) return(0);
		if(del[p]) {
			int q = p;
			p--;
			p = pa[p];
			q = pa[q];
			pa[p] = q;
			pa[q] = p;
		}
	}
	zap = p;
	return(1);
}
bool goL(int p) {
	p = pa[p];
	p--;
	if(p == -1) return(0);
	while(del[p]) {
		p = pa[p];
		p--;
		if(p == -1) return(0);
		if(del[p]) {
			int q = p;
			p++;
			p = pa[p];
			q = pa[q];
			pa[p] = q;
			pa[q] = p;
		}
	}
	zap = p;
	return(1);
}

int main() {

	#ifdef SOL
	{
//		freopen("input.txt", "r", stdin);
//		freopen("output.txt", "w", stdout);
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

	int m, p;
	scanf("%d%d%d\n", &n, &m, &p); p--;
	getline(cin, s);
	getline(cin, t);
	for(int i = 0; i < n; i++) {
		if(s[i] == '(') {
			st[sz++] = i;
		} else {
			sz--;
			pa[st[sz]] = i;
			pa[i] = st[sz];
		}
	}
	for(int i = 0; i < m; i++) {
		if(t[i] == 'L') {
			p--;
			while(del[p]) {
				p = pa[p];
				p--;
				if(del[p]) {
					int q = p;
					p++;
					p = pa[p];
					q = pa[q];
					pa[p] = q;
					pa[q] = p;
				}
			}
		} else
		if(t[i] == 'R') {
			p++;
			while(del[p]) {
				p = pa[p];
				p++;
				if(del[p]) {
					int q = p;
					p--;
					p = pa[p];
					q = pa[q];
					pa[p] = q;
					pa[q] = p;
				}
			}
		} else
		if(t[i] == 'D') {
			del[p] = 1;
			del[pa[p]] = 1;
			if(s[p] == '(') {
				p = pa[p];
			}
			if(goR(p)) {
				p = zap;
			} else
			if(goL(p)) {
				p = zap;
			} else {
				assert(0);
			}
		}
	}

	for(int i = 0; i < n; i++) {
		if(!del[i]) {
			printf("%c", s[i]);
		} else {
			i = pa[i];
		}
	}

	#ifdef SOL
	{
		fflush(stdout);
		fprintf(stderr, "%.3lf ms\n", 1000. * clock() / CLOCKS_PER_SEC);
		fflush(stderr);
	}
	#endif
	return(0);
}

// by Andrey Kim