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

pair<int, int> m[maxn];
int ans[maxn];

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
	scanf("%d" ,&n);
	for(int i = 0; i < n; i++) {
		int c;
		scanf("%d", &c);
		m[i] = mp(c, i);
	}
	sort(&m[0], &m[n]);
	reverse(&m[0], &m[n]);

	for(int i = 0; i < n; i++) {
		ans[m[i].sc] = (i >= 0 ? (m[i - 1].fs == m[i].fs ? ans[m[i - 1].sc] : i + 1) : 0);
	}

	for(int i = 0; i < n; i++) {
		printf("%d ", ans[i]);
	}

	return(0);
}

// by Kim Andrey