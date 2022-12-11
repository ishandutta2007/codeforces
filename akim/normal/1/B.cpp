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

	int t;
	scanf("%d\n", &t);
	for(; t > 0; t--) {
		string s;
		getline(cin, s);
		int sec = 0, mn = 1;
		while(s.back() >= '0' && s.back() <= '9') {
			sec = (s.back() - '0') * mn + sec;
			mn *= 10;
			s.ppb();
		}
		bool dig = 0;
		for(int i = 0; i < (int)s.size(); i++) {
			if(s[i] >= '0' && s[i] <= '9') {
				dig = 1;
			}
		}
		if(dig) {
			s.ppb();
			int fir = 0, mn = 1;
			while(s.back() >= '0' && s.back() <= '9') {
				fir = (s.back() - '0') * mn + fir;
				mn *= 10;
				s.ppb();
			}
			string seco;
			while(sec > 0) {
				sec--;
				seco = (char)((sec % 26) + 'A') + seco;
				sec /= 26;
			}
			cout << seco << fir << endl;
		} else {
			int fir = 0;
			for(int i = 0; i < (int)s.length(); i++) {
				fir = fir * 26 + (s[i] - 'A' + 1);
			}
			cout << 'R' << sec << 'C' << fir << endl;
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