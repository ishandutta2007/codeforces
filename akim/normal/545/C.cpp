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

vector<pair<int, int> > vc;
int dp[maxn], H[maxn];

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
		int x, h;
		scanf("%d%d", &x, &h);
		vc.pb(mp(x - h, -(i + 1)));
		vc.pb(mp(x, -(n + i + 1)));
		vc.pb(mp(x, 0));
		vc.pb(mp(x, (i + 1)));
		vc.pb(mp(x + h, (n + i + 1)));
		H[i + 1] = h;
		H[n + i + 1] = h;
	}

	sort(vc.begin(), vc.end());
	int tek = 0, lst = -mod, llst = -mod;
	for(int i = 0; i < (int)vc.size(); i++) {
		if(vc[i].sc < 0) {
			dp[-vc[i].sc] = tek + 1;
		} else
		if(vc[i].sc > 0){
			if(vc[i].sc <= n) {
				if(llst < vc[i].fs - H[vc[i].sc]) {
					tek = max(dp[vc[i].sc], tek);
				}
			} else {
				if(lst <= vc[i].fs - H[vc[i].sc]) {
					tek = max(dp[vc[i].sc], tek);
				}
			}
		} else {
			llst = lst;
			lst = vc[i].fs;
		}
	}

	printf("%d", tek);

	return(0);
}

// by Kim Andrey