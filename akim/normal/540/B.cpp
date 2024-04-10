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

	int n, k, p, x, y;
	scanf("%d%d%d%d%d", &n, &k, &p, &x, &y);
	int m = (n + 1) / 2 - 1;
	int s = 0;
	for(int i = 0; i < k; i++) {
		int u;
		scanf("%d", &u);
		s += u;
		if(u < y) {
			m--;
		}
	}
	n -= k;
	if(m < 0) {
		cout << -1;
		return(0);
	}
	int cnt1 = 0, cnt2 = 0;;
	while(m && n) {
		s += 1;
		cnt1++;
		n--;
		m--;
	}
	while(n) {
		s += y;
		cnt2++;
		n--;
	}

	if(s > x) {
		cout << "-1";
		return(0);
	}

	for(int i = 0; i < cnt1; i++) {
		cout << 1 << " ";
	}
	for(int i = 0; i < cnt2; i++) {
		cout << y << " ";
	}


	return(0);
}

// by Kim Andrey