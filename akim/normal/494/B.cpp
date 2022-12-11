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

ll a[100100], q1[100100], q2[100100], pf[100100];

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

	string s, t;
	getline(cin, s);
	getline(cin, t);
	s = t + '#' + s;
	int ls = s.length(), lt = t.length();
	for(int i = 1; i < ls; i++) {
		int f = pf[i - 1];
		while(f > 0 && s[i] != s[f]) {
			f = pf[f - 1];
		}
		if(s[i] == s[f]) f++;
		pf[i] = f;
		if(i > lt) {
			if(pf[i] == lt) {
				i -= lt + 1;
				a[i] = ((i - lt >= 0 ? q2[i - lt] : 0) + i - lt + 2) % mod;
			} else {
				i -= lt + 1;
				a[i] = (i - 1 >= 0 ? a[i - 1] : 0);
			}
			q1[i] = ((i - 1 >= 0 ? q1[i - 1] : 0) + a[i]) % mod;
			q2[i] = ((i - 1 >= 0 ? q2[i - 1] : 0) + q1[i]) % mod;
//			cout << a[i] << " " << q1[i] << " " << q2[i] << "\n";
			i += lt + 1;
		}
	}

	cout << q1[ls - lt - 2];

	return(0);
}

// by Kim Andrey