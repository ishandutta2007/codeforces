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
const int maxn = 2 * 100100;

set<pair<int, int> > x[3];
vector<int> ans;

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
		int u;
		scanf("%d", &u);
		x[u % 3].insert(mp(-u, i + 1));
	}
	int now = 0;
	while(1) {
		set<pair<int, int> >::iterator it = x[now % 3].lower_bound(mp(-now, 0));
		if(it != x[now % 3].end()) {
			int q = it -> fs;
			ans.pb((*it).sc);
			x[now % 3].erase(it);
			now = -q + 1;
		} else {
			break;
		}
	}
	if((int)ans.size() != n) {
		printf("Impossible\n");
	} else {
		printf("Possible\n");
		for(int i = 0; i < n; i++) {
			printf("%d ", ans[i]);
		}
	}

	return(0);
}

// by Kim Andrey