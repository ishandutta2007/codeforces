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

map<char, int> rnm;
pair<int, int> ms[3];

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

	rnm['A'] = 0;
	rnm['B'] = 1;
	rnm['C'] = 2;
	ms[0].sc = 0;
	ms[1].sc = 1;
	ms[2].sc = 2;

	string s, t, r;
	getline(cin, s);
	getline(cin, t);
	getline(cin, r);

	if(s[1] == '>') {
		swap(s[0], s[2]);
	}
	ms[rnm[s[2]]].fs++;
	if(t[1] == '>') {
		swap(t[0], t[2]);
	}
	ms[rnm[t[2]]].fs++;
	if(r[1] == '>') {
		swap(r[0], r[2]);
	}
	ms[rnm[r[2]]].fs++;

	if(ms[0].fs == 1 && ms[1].fs == 1 && ms[2].fs == 1) {
		printf("Impossible\n");
		return(0);
	}

	sort(&ms[0], &ms[3]);
	for(int i = 0; i < 3; i++) {
		printf("%c", ('A' + ms[i].sc));
	}

	return(0);
}

// by Kim Andrey