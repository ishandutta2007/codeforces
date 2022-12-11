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
const int maxn = 10 * 100100;

vector<int> vc[maxn];

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
		int b;
		scanf("%d", &b);
		vc[b].pb(i);
	}
	int cnt = 0, l = 0, ln = 0;
	for(int i = 0; i < maxn; i++) {
		if(vc[i].size() > cnt) {
			cnt = vc[i].size();
			l = vc[i][0];
			ln = vc[i].back() - vc[i][0];
		} else
		if(vc[i].size() == cnt && (!vc[i].empty()) && ln > vc[i].back() - vc[i][0]) {
			l = vc[i][0];
			ln = vc[i].back() - vc[i][0];
		}
	}

	printf("%d %d", l + 1, l + 1 + ln);

	return(0);
}