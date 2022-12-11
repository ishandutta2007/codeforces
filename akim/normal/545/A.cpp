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

int a[110][110];

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

	vector<int> vc;
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		bool good = 1;
		for(int f = 0; f < n; f++) {
			scanf("%d", &a[i][f]);
			if(i == f) continue;
			if(a[i][f] == 0 || 2 == a[i][f]) {

			} else {
				good = 0;
			}
		}
		if(good) {vc.pb(i + 1);}
	}

	printf("%d\n", (int)vc.size());
	for(int i = 0; i < (int)vc.size(); i++) {
		printf("%d ", vc[i]);
	}

	return(0);
}

// by Kim Andrey