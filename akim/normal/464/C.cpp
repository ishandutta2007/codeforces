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

long long z[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
long long y[10] = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10};

vector<pair<char , string> > vc;

int main() {

//	freopen("*.in","r",stdin);
//	freopen("*.out","w",stdout);
	
	string s; getline(cin, s);
	int n; scanf("%d\n", &n);
	for(int i = 0; i < n; i++) {
		vc.pb(mp(' ', ""));
		scanf("%c->", &vc.back().fs);
		getline(cin, vc.back().sc);
	}

	for(int i = n - 1; i >= 0; i--) {
		int sz = vc[i].sc.size();
		long long g = 1;
		long long otv = 0;
		for(int f = 0; f < sz; f++) {
			otv = (otv + (z[vc[i].sc[sz - f - 1] - '0'] * g) % mod) % mod;
			g = (g * y[vc[i].sc[sz - f - 1] - '0']) % mod;
		}
		z[vc[i].fs - '0'] = otv;
		y[vc[i].fs - '0'] = g;
	}
	
	int sz = s.size();
	long long g = 1;
	long long otv = 0;
	for(int f = 0; f < sz; f++) {
		otv = (otv + (z[s[sz - f - 1] - '0'] * g) % mod) % mod;
		g = (g * y[s[sz - f - 1] - '0']) % mod;
//		cerr<<otv<<" "<<g<<"\n";
	}

	printf("%I64d", otv);

	return(0);
}

// by Kim Andrey