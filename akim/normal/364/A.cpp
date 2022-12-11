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

string s;
long long x[40000];

int main() {

//	freopen("*.in","r",stdin);
//	freopen("*.out","w",stdout);
	long long sum, i, f, g, h;
	scanf("%I64d\n", &sum);
	getline(cin, s);
	long long ls = s.length();
	for(i = 0; i < s.length(); i++) {
		long long sm = 0;
		for(f = i; f < s.length(); f++) {
			sm += s[f] - '0';
			x[sm]++;
		}
	}

	long long ln = 40000, otv = 0;
	if(sum == 0) {
		cout<<2 * (x[0] * ((ls*(ls + 1))/2)) - sqr(x[0]);
		return(0);
	}
	for(i = 1; i < ln; i++) {
		if(!(sum % i) && sum / i < 40000) {
			otv += x[i] * x[sum / i];
		}
	}
	cout<<otv;

	return(0);
}

// by Kim Andrey