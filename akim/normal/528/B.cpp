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
const int maxn = 200100;

pair<int, int> pa[maxn];
int ans[maxn], n, maxans = 0;

vector<pair<int, int> > vc;

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

	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d%d", &pa[i].fs, &pa[i].sc);
		vc.pb(mp(pa[i].fs - pa[i].sc, i));
		vc.pb(mp(pa[i].fs + pa[i].sc, -i));
	}
	sort(vc.begin(), vc.end());
	for(int i = 0; i < (int)vc.size(); i++) {
		if(vc[i].sc < 0) {
			maxans = max(maxans, ans[-vc[i].sc]);
		} else {
			ans[vc[i].sc] = maxans + 1;
		}
	}

	cout << maxans;

	return(0);
}

// by Kim Andrey