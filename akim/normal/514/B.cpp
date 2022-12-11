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

set<pair<int, int> > st;

int gcd(int a, int b) {
	while(b) {
		a %= b;
		swap(a, b);
	}
	return(a);
}

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

	int n, x0, y0;
	scanf("%d%d%d", &n, &x0, &y0);
	for(; n > 0; n--) {
		int x, y;
		scanf("%d%d", &x, &y);
		x -= x0, y -= y0;
		int c = gcd(abs(x), abs(y));
		x /= c;
		y /= c;
		if(x < 0) {
			x = -x;
			y = -y;
		}
		if(x == 0 && y < 0) {
			x = -x;
			y = -y;
		}
		st.insert(mp(x, y));
	}

	cout << st.size();

	return(0);
}

// by Kim Andrey