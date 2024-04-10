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

string st[] = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};

int main() {

//	freopen("*.in","r",stdin);
//	freopen("*.out","w",stdout);
	
	scanf("%*d\n");
	string s;getline(cin, s);
	for(int i = 0; i < 8; i++) {
		if(st[i].length() == s.length()) {
			bool ok = 1;
			for(int f = 0; f < s.length(); f++) {
				if(!(s[f] == '.' || s[f] == st[i][f])) {ok = 0;}
			}
			if(ok) {
				printf("%s", st[i].c_str());
				return(0);
			}
		}
	}
	
	
	return(0);
}

// by Kim Andrey