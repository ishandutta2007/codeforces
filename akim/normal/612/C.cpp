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
const int maxn = 200100;

vector<int> vc;

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

	string s;
	getline(cin, s);
	int ans = 0;
	for(int i = 0; i < (int)s.length(); i++) {
		if(s[i] == '(') {
			vc.pb(1);
		} else
		if(s[i] == '[') {
			vc.pb(2);
		} else
		if(s[i] == '{') {
			vc.pb(3);
		} else
		if(s[i] == '<') {
			vc.pb(4);
		} else
		if(s[i] == ')') {
			if(vc.empty()) {
				cout << "Impossible";
				return(0);
			}
			if(vc.back() == 1) {
				vc.ppb();
			} else {
				ans++;
				vc.ppb();
			}
		} else
		if(s[i] == ']') {
			if(vc.empty()) {
				cout << "Impossible";
				return(0);
			}
			if(vc.back() == 2) {
				vc.ppb();
			} else {
				ans++;
				vc.ppb();
			}
		} else
		if(s[i] == '}') {
			if(vc.empty()) {
				cout << "Impossible";
				return(0);
			}
			if(vc.back() == 3) {
				vc.ppb();
			} else {
				ans++;
				vc.ppb();
			}
		} else
		if(s[i] == '>') {
			if(vc.empty()) {
				cout << "Impossible";
				return(0);
			}
			if(vc.back() == 4) {
				vc.ppb();
			} else {
				ans++;
				vc.ppb();
			}
		}
	}

	if(!vc.empty()) {
		cout << "Impossible";
		return(0);
	}

	cout << ans;

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