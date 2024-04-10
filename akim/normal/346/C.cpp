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

int x[maxn];
int z[10 * maxn];
int a, b;

void fill(int u) {
	int lpos = (u - b % u) % u;
	for(; lpos <= a - b; lpos += u) {
		z[lpos] = max(z[lpos], lpos + u - 1);
	}
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

	int n;
	scanf("%d", &n);

	for(int i = 0; i < n; i++) {
		scanf("%d", &x[i]);
	}

	scanf("%d%d", &a, &b);

	sort(&x[0], &x[n]);

	n = unique(&x[0], &x[n]) - &x[0];

	for(int i = 0; i < 10 * maxn; i++) {
		z[i] = i + 1;
	}

	for(int i = 0; i < n; i++) {
		fill(x[i]);
	}

	for(int i = 1; i <= a - b; i++) {
		z[i] = max(z[i], z[i - 1]);
	}
	int cnt = 0;
	for(int i = 0; i < a - b;) {
		i = z[i];
		cnt++;
	}

	cout << cnt;

	return(0);
}

// by Kim Andrey