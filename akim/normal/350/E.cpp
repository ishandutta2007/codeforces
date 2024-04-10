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
const int maxn = 310;

bool pm[maxn];
set<pair<int, int> > st;

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

	int n, m, k;
	int a = 0, b = 0;
	cin >> n >> m >> k;
	for(int i = 0; i < k; i++) {
		int u;
		cin >> u;
		pm[u] = 1;
		if(a == 0) {
			a = u;
		} else {
			b = u;
		}

	}
//	for(int i = 1; i <= k; i++) {
//		pm[i] = 1;
//	}
//	a = 1, b = 299;
	int bad = 0;
	for(int i = 1; i <= n; i++) {
		if(!pm[i]) {
			bad = i;
			break;
		}
	}
	if(bad == 0 || (n * (n - 1) / 2 - (k - 1)) < m || m < 2) {
		cout << -1;
		return(0);
	}
	m--; m--;
	cout << bad << " " << b << endl;
	cout << bad << " " << a << endl;
	st.insert(mp(min(bad, b), max(bad, b)));
	st.insert(mp(min(bad, a), max(bad, a)));
	for(int i = 1; i <= n; i++) {
		if(i != a && i != b && i != bad) {
			cout << a << " " << i << endl;
			st.insert(mp(min(a, i), max(a, i)));
			m--;
		}
	}
	if(m == 0) return(0);
	for(int i = 1; i <= n; i++) {
		for(int f = i + 1; f <= n; f++) {
			if((i == a && f == b) || (i == b && f == a)) continue;
			if((i == b && pm[f]) || (f == b && pm[i])) continue;
			if(st.count(mp(i, f))) continue;
			cout << i << " " << f << endl;
			if(--m == 0) return(0);
		}
	}

	return(0);
}

// by Kim Andrey