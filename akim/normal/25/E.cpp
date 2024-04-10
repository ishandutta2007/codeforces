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

int pf[3 * maxn];

void merge(string &ans, string &s1, string &s2) {
	string str = s2 + '#' + s1;
	int ls = str.length();
	pf[0] = 0;
	bool inside = 0;
	for(int i = 1; i < ls; i++) {
		int j = pf[i - 1];
		while(j > 0 && str[i] != str[j]) {j = pf[j - 1];}
		if(str[i] == str[j]) j++;
		pf[i] = j;
		if(pf[i] == (int)s2.length()) {
			inside = 1;
		}
	}
	if(inside) {
		ans = s1;
		return;
	}

	ans = s1 + s2.substr(pf[ls - 1], ls - pf[ls - 1]);
	return;
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

	string s[3];
	getline(cin, s[0]);
	getline(cin, s[1]);
	getline(cin, s[2]);

	int ans = mod;
	for(int i = 0; i < 3; i++) {
		for(int f = 0; f < 3; f++) {
			if(i == f) continue;
			string t;
			merge(t, s[i], s[f]);
			for(int g = 0; g < 3; g++) {
				if(i == g || f == g) continue;
				string r;
				merge(r, t, s[g]);
				if((int)r.length() < ans) {
					ans = r.length();
				}
			}
		}
	}

	printf("%d", ans);

	return(0);
}

// by Kim Andrey