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
#define abs(a) ((a)<0?-(a):(a))
#define sqr(a) ((a)*(a))

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;


const double eps = 1e-9;
const int mod = (int)1e+9 + 7;
const double pi = acos(-1.);
const int maxn = 600100;

vector<int> bor[maxn][3];
int sz[maxn];
int ls;

bool rec(string &s, bool odin = 1, int posb = 0, int poss = 0) {
	if(poss == ls) {
		return(!odin);
	}
	if(odin) {
		if(		(bor[ls][0][posb] != 0 && rec(s, (s[poss] == 'a'), bor[ls][0][posb], poss + 1)) ||
				(bor[ls][1][posb] != 0 && rec(s, (s[poss] == 'b'), bor[ls][1][posb], poss + 1)) ||
				(bor[ls][2][posb] != 0 && rec(s, (s[poss] == 'c'), bor[ls][2][posb], poss + 1))) {
			return(1);
		} else {
			return(0);
		}
	} else {
		if(bor[ls][s[poss] - 'a'][posb] != 0) {
			return(rec(s, 0, bor[ls][s[poss] - 'a'][posb], poss + 1));
		}
	}
	return(0);
}

int main() {

	#ifdef SOL
	{
//		freopen("input.txt","r",stdin);
//		freopen("output.txt","w",stdout);
	}
	#else
	srand(time(0));
	const string file = "";
	if(!file.empty()) {
		freopen((file + ".in").c_str(),"r",stdin);
		freopen((file + ".out").c_str(),"w",stdout);
	}
	#endif

	for(int i = 0; i < maxn; i++) {
		sz[i] = 1;
		bor[i][0].pb(0);
		bor[i][1].pb(0);
		bor[i][2].pb(0);
	}

	int n, m;
	scanf("%d%d\n", &n, &m);
	for(int i = 0; i < n; i++) {
		string s; getline(cin, s);
		int pos = 0;
		int ls = s.length();
		for(int f = 0; f < ls; f++) {
			if(bor[ls][s[f] - 'a'][pos] == 0) {
				bor[ls][0].pb(0);
				bor[ls][1].pb(0);
				bor[ls][2].pb(0);
				bor[ls][s[f] - 'a'][pos] = sz[ls]++;
			}
			pos = bor[ls][s[f] - 'a'][pos];
		}
	}

	for(int i = 0; i < m; i++) {
		string s; getline(cin, s);
		ls = s.length();
		cout << ((rec(s) == 1) ? ("YES\n") : ("NO\n"));
	}

	return(0);
}

// by Kim Andrey