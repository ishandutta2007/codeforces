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



int main() {

//	freopen("*.in","r",stdin);
//	freopen("*.out","w",stdout);
	int m;
	scanf("%d", &m);
	for(int i = 0; i < 4; i++) {
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		if(m - a >= d || m - a >= c) {cout << i + 1 << " " << a << " " << m - a; return 0;}
		if(m - b >= c || m - b >= d) {cout << i + 1 << " " << b << " " << m - b; return 0;}
		if(m - c >= b || m - c >= a) {cout << i + 1 << " " << c << " " << m - c; return 0;}
		if(m - d >= a || m - d >= b) {cout << i + 1 << " " << d << " " << m - d; return 0;}
	}
	cout<<-1;
	return 0;
}

// by Kim Andrey