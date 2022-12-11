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
const int maxn = 20;

int len;

set<pair<int, int> > was;
vector<int> vc[maxn];

bool rec(char *s, int pos, int ost = 0) {
	if(pos == len && ost == 0) {
		return(1);
	}
	if(ost > 9 || ost < 0 || was.count(mp(pos, ost))) {
		return(0);
	}
	was.insert(mp(pos, ost));
	int val = ost * 10 + (s[pos] - '0');
	for(int i = 0; i <= 6; i++) {
		for(int f = 0; i + f <= 6; f++) {
			if(rec(s, pos + 1, val - i * 4 - f * 7)) {
				for(int g = 0; g < 6; g++) {
					if(g < i) vc[g].pb(4); else
					if(g < i + f) vc[g].pb(7); else
					vc[g].pb(0);
				}
				return(1);
			}
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

	int t;
	cin >> t;
	for(; t > 0; t--) {
		for(int i = 0; i < 6; i++) {
			vc[i].clear();
		}
		was.clear();
		char c[maxn];
		cin >> c;
		len = strlen(c);
		if(!rec(c, 0)) {
			cout << -1;
		} else {
			for(int i = 0; i < 6; i++) {
				while(vc[i].size() > 0 && vc[i].back() == 0) {vc[i].ppb();}
				if(vc[i].size() == 0) vc[i].pb(0);
				for(int f = (int)vc[i].size() - 1; f >= 0; f--) {
					cout << vc[i][f];
				}cout << " ";
			}
		}
		cout << endl;
	}

	return(0);
}

// by Kim Andrey