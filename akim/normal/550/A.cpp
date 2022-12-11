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

	string s;
	vector<int> vc1, vc2;
	getline(cin, s);
	for(int i = 0; i < (int)s.length() - 1; i++) {
		if(s[i] == 'A' && s[i + 1] == 'B') {
			vc1.pb(i);
		}
		if(s[i] == 'B' && s[i + 1] == 'A') {
			vc2.pb(i);
		}
	}
	if(vc1.empty() || vc2.empty()) {
		printf("NO");
		return(0);
	}

	if((vc1[0] < vc2.back() && vc1[0] + 1 != vc2.back()) || (vc2[0] < vc1.back() && vc2[0] + 1 != vc1.back())) {
		printf("YES");
	} else {
		printf("NO");
	}

	return(0);
}

// by Kim Andrey