#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <cassert>
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
#define abs(a) ((a)<0?-(a):(a))
#define sqr(a) ((a)*(a))

const double eps = 1e-9;
const int mod = (int)1e+9 + 7;
const double pi = acos(-1.0);

vector<int> vc;
pair<pair<long long, long long>, int> x[100100], otv[100100];
bool pm[100100];
vector<int> rb[100100];
int pos = 0;

char down(char c) {
	if(c >= 'A' && c <= 'Z') {
		c -= 'A';
		c += 'a';
	}
	return(c);
}

int gethash(string &s) {
	int hash = 0, idx = 1;
	for(int i = 0; i < s.length(); i++, idx *= 147, idx %= mod + 2) {
		hash += down(s[i]) * idx;
		hash %= mod + 2;
	}
	return(hash);
}

int numr(string &s) {
	int k = 0;
	for(int i = 0; i < s.length(); i++) {
		if(s[i] == 'R' || s[i] == 'r') k++;
	}
	return(k);
}

map<int, int> idxhash;

void dfs(int u) {
	pm[u] = 1;
	otv[u] = x[pos];
	for(int i = 0; i < rb[u].size(); i++) {
		if(!pm[rb[u][i]]) {
			dfs(rb[u][i]);
		}
	}
}

int main() {

//	freopen("*.in","r",stdin);
//	freopen("*.out","w",stdout);

	int n, m;
	cin >> n;
	int q = 0;
	for(int i = 0; i < n; i++) {
		string s;
		cin >> s;
		int hash = gethash(s);
		if(!idxhash.count(hash)) {idxhash[hash] = q++; x[q - 1] = mp(mp(numr(s), s.length()), q - 1); vc.pb(q - 1);} else {vc.pb(idxhash[hash]);}
		//printf("%d ", hash);
	}

	cin >> m;
	for(int i = 0; i < m; i++) {
		string s, t;
		cin >> s >> t;
		int hs = gethash(s), ht = gethash(t);
		if(!idxhash.count(hs)) {idxhash[hs] = q++; x[q - 1] = mp(mp(numr(s), s.length()), q - 1);}
		if(!idxhash.count(ht)) {idxhash[ht] = q++; x[q - 1] = mp(mp(numr(t), t.length()), q - 1);}
		rb[idxhash[ht]].pb(idxhash[hs]);
	}

	sort(&x[0], &x[q]);
	for(int i = 0; i < q; i++) {
		if(!pm[x[i].sc]) {
			pos = i;
			dfs(x[i].sc);
		}
	}

	long long o1 = 0, o2 = 0;
	for(int i = 0; i < vc.size(); i++) {
		o1 += otv[vc[i]].fs.fs, o2 += otv[vc[i]].fs.sc;
		//printf("%I64d %I64d\n", otv[vc[i]].fs.fs, otv[vc[i]].fs.sc);
	}
	printf("%I64d %I64d", o1, o2);


	return(0);
}

// by Kim Andrey