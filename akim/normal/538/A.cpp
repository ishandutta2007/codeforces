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
const int maxn = 100100;



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

	string s = "CODEFORCES";
	string t;
	getline(cin, t);
	int ps = 0, c1 = 0, c2 = 0;
	for(int i = 0; i < (int)t.length(); i++) {
		if(ps < (int)s.length() && s[ps] == t[i]) {
			ps++; c1++;
		} else {
			break;
		}
	}
	ps = s.length();
	for(int i = t.length(); i >= 0; i--) {
		if(ps >= 0 && s[ps - 1] == t[i - 1]) {
			ps--; c2++;
		} else {
			break;
		}
	}
	if(c1 + c2 >= (int)s.length()) {
		cout << "YES";
	} else {
		cout << "NO";
	}

	return(0);
}

// by Kim Andrey