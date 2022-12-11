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

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;


const double eps = 1e-9;
const int mod = (int)1e+9 + 7;
const double pi = acos(-1.);

int ball[100100], balr[100100], ans[100100];

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

	string s;
	getline(cin, s);

	for(int i = 0; i < (int)s.length(); i++) {
		if(s[i] == '(') {
			ball[i] = (i != 0 ? ball[i - 1] : 0) + 1;
		} else {
			ball[i] = (i != 0 ? ball[i - 1] : 0) - 1;
			if(s[i] == '#') {
				ans[i] = 1;
			}
		}
	}
	int bal = 0;
	for(int i = s.length() - 1; i >= 0; i--) {
		if(s[i] != '(') {
			bal += 1;
		} else {
			bal -= 1;
		}
		if(s[i] == '#') {
			ans[i] += max(ball[i] - bal + 1, 0);
			break;
		}
	}
	bal = 0;
	for(int i = 0; i < (int)s.length(); i++) {
		if(s[i] == '(') {
			bal += 1;
		}
		if(s[i] == ')') {
			bal -= 1;
		}
		if(s[i] == '#') {
			bal -= ans[i];
		}
		if(bal < 0) {
			cout << -1;
			return(0);
		}
//		cout << bal << " ";
	}
	if(bal != 0) {
		cout << -1;
		return(0);
	}
	for(int i = 0; i < (int)s.length(); i++) {
		if(ans[i] > 0) cout << ans[i] << endl;
	}

	return(0);
}

// by Kim Andrey