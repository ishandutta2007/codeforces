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

	int n;
	scanf("%d\n", &n);
	string s;
	getline(cin, s);

	if(n % 3 == 1) {
		string t;
		if(s.length() >= 4) {
			t += s[s.length() - 4];
			t += s[s.length() - 3];
			t += s[s.length() - 2];
			t += s[s.length() - 1];
		}
		for(int i = 0; i < n - 4; i++) {
			if(i % 3 == 0 && i > 0) {
				printf("-");
			}
			printf("%c", s[i]);
		}
		if(s.length() > 4) printf("-");
		printf("%c%c-%c%c", t[0], t[1], t[2], t[3]);
	} else {
		for(int i = 0; i < n; i++) {
			if(i % 3 == 0 && i > 0) {
				printf("-");
			}
			printf("%c", s[i]);
		}
	}

	return(0);
}

// by Kim Andrey