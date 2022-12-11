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

struct node {
	int len, link, pos;
	map<char, int> nxt;
};

node saf[2 * maxn], sab[2 * maxn];
int szf, lstf, szb, lstb;

vector<pair<int, int> > vc;

void addf(char c, int pos) {
	int cur = szf++;
	saf[cur].len = saf[lstf].len + 1;
	saf[cur].pos = pos;
	int p;
	for(p = lstf; p != -1 && !saf[p].nxt.count(c); p = saf[p].link) {
		saf[p].nxt[c] = cur;
	}
	if(p == -1) {
		saf[cur].link = 0;
	} else {
		int q = saf[p].nxt[c];
		if(saf[p].len + 1 == saf[q].len) {
			saf[cur].link = q;
		} else {
			int clone = szf++;
			saf[clone].len = saf[p].len + 1;
			saf[clone].nxt = saf[q].nxt;
			saf[clone].link = saf[q].link;
			saf[clone].pos = saf[q].pos;
			for(; p != -1 && saf[p].nxt[c] == q; p = saf[p].link) {
				saf[p].nxt[c] = clone;
			}
			saf[q].link = saf[cur].link = clone;
		}
	}
	lstf = cur;
}

void addb(char c, int pos) {
	int cur = szb++;
	sab[cur].len = sab[lstb].len + 1;
	sab[cur].pos = pos;
	int p;
	for(p = lstb; p != -1 && !sab[p].nxt.count(c); p = sab[p].link) {
		sab[p].nxt[c] = cur;
	}
	if(p == -1) {
		sab[cur].link = 0;
	} else {
		int q = sab[p].nxt[c];
		if(sab[p].len + 1 == sab[q].len) {
			sab[cur].link = q;
		} else {
			int clone = szb++;
			sab[clone].len = sab[p].len + 1;
			sab[clone].nxt = sab[q].nxt;
			sab[clone].link = sab[q].link;
			sab[clone].pos = sab[q].pos;
			for(; p != -1 && sab[p].nxt[c] == q; p = sab[p].link) {
				sab[p].nxt[c] = clone;
			}
			sab[q].link = sab[cur].link = clone;
		}
	}
	lstb = cur;
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

	{
		szf = lstf = 0;
		saf[0].len = 0;
		saf[0].link = -1;
		szf++;
	}
	{
		szb = lstb = 0;
		sab[0].len = 0;
		sab[0].link = -1;
		szb++;
	}

	string s;
	getline(cin, s);
	int n = s.length();
	for(int i = 0; i < n; i++) {
		addf(s[i], i + 1);
	}
	for(int i = n - 1; i >= 0; i--) {
		addb(s[i], i + 1);
	}

	getline(cin, s);
	n = s.length();
	int pos = 0;
	while(pos < n) {
		int jf = 0, lenf = 0;
		while(pos + lenf < n && saf[jf].nxt.count(s[pos + lenf])) {
			jf = saf[jf].nxt[s[pos + lenf]];
			lenf++;
		}
		int jb = 0, lenb = 0;
		while(pos + lenb < n && sab[jb].nxt.count(s[pos + lenb])) {
			jb = sab[jb].nxt[s[pos + lenb]];
			lenb++;
		}
		if(lenf == 0 && lenb == 0) {
			printf("-1");
			return(0);
		}
		if(lenf > lenb) {
			vc.pb(mp(saf[jf].pos - lenf + 1, saf[jf].pos));
			pos = pos + lenf;
		} else {
			vc.pb(mp(sab[jb].pos + lenb - 1, sab[jb].pos));
			pos = pos + lenb;
		}
	}

	printf("%d\n", (int)vc.size());
	for(int i = 0; i < (int)vc.size(); i++) {
		printf("%d %d\n", vc[i].fs, vc[i].sc);
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