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

vector<int> l[maxn];
int a[maxn];

multiset<int> st;

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
		int v;
		scanf("%d", &v);
		l[v].pb(i);
	}
	int sm = 0;
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		sm += a[i];
	}
	int sum = 0, ans = 200 * maxn;
	for(int i = 0; i < maxn; i++) {
		if(l[i].empty()) continue;

		for(int f = 0; f < (int)l[i].size(); f++) sm -= a[l[i][f]];

		multiset<int>::reverse_iterator it = st.rbegin();
		int gd = 0;
		for(int f = 0; f < (int)l[i].size() - 1 && it != st.rend(); f++, it++) {
			gd += *it;
		}

		ans = min(ans, sum + sm - gd);
		for(int f = 0; f < (int)l[i].size(); f++) sum += a[l[i][f]], st.insert(a[l[i][f]]);
	}
	printf("%d", ans);

	return(0);
}

// by Kim Andrey