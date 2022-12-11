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

deque<int> dq1, dq2;

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

	int n;
	scanf("%d", &n);
	{
		int m;
		scanf("%d", &m);
		for(int i = 0; i < m; i++) {
			int k;
			scanf("%d", &k);
			dq1.pb(k);
		}
	}
	{
		int m;
		scanf("%d", &m);
		for(int i = 0; i < m; i++) {
			int k;
			scanf("%d", &k);
			dq2.pb(k);
		}
	}

	for(int i = 0; i < 10000000; i++) {
		if(dq1.empty()) {printf("%d %d", i, 2); return(0);}
		if(dq2.empty()) {printf("%d %d", i, 1); return(0);}
		if(dq1.front() > dq2.front()) {
			dq1.pb(dq2.front());
			dq1.pb(dq1.front());
			dq1.pop_front();
			dq2.pop_front();
		} else {
			dq2.pb(dq1.front());
			dq2.pb(dq2.front());
			dq1.pop_front();
			dq2.pop_front();
		}
	}

	printf("-1");

	return(0);
}

// by Kim Andrey