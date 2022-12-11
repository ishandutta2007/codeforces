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

long long x[2][2], otv[2];

int main() {

//	freopen("*.in","r",stdin);
//	freopen("*.out","w",stdout);
	
	string s; getline(cin, s); int ls = s.length();
	for(long long i = 0; i < ls; i++) {
		x[s[i] - 'a'][i & 1]++;
		otv[0] += x[s[i] - 'a'][(i + 1) & 1];
		otv[1] += x[s[i] - 'a'][i & 1];
	}
	
	printf("%I64d %I64d", otv[0], otv[1]);
	
	return(0);
}

// by Kim Andrey