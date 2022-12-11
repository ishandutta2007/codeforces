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
#define abs(a) ((a) < 0 ? -(a) : (a))
#define sqr(a) ((a) * (a))

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

const double eps = 1e-9;
const int mod = (int)1e+9 + 7;
const double pi = acos(-1.);
const int maxn = 100100;

vector<pair<int, int> > vc1, vc2;

int main() {

	#ifdef SOL
	{
//		freopen("input.txt","r",stdin);
//		freopen("output.txt","w",stdout);
	}
	#else
	{
		srand(time(0));
		const string file = "";
		if(!file.empty()) {
			freopen((file + ".in").c_str(), "r", stdin);
			freopen((file + ".out").c_str(), "w", stdout);
		}
	}
	#endif

	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		if(a > 0) {
			vc1.pb(mp(a, b));
		} else {
			vc2.pb(mp(-a, b));
		}
	}

	sort(vc1.begin(), vc1.end());
	sort(vc2.begin(), vc2.end());

	if(vc1.size() > vc2.size()) {
		int ans = 0;
		for(int i = 0; i < vc2.size(); i++) {
			ans += vc2[i].sc;
		}
		for(int i = 0; i <= vc2.size(); i++) {
			ans += vc1[i].sc;
		}
		printf("%d\n", ans);
	} else
	if(vc1.size() < vc2.size()) {
		int ans = 0;
		for(int i = 0; i < vc1.size(); i++) {
			ans += vc1[i].sc;
		}
		for(int i = 0; i <= vc1.size(); i++) {
			ans += vc2[i].sc;
		}
		printf("%d\n", ans);
	} else {
		int ans = 0;
		for(int i = 0; i < vc1.size(); i++) {
			ans += vc1[i].sc;
		}
		for(int i = 0; i < vc2.size(); i++) {
			ans += vc2[i].sc;
		}
		printf("%d\n", ans);
	}

	return(0);
}