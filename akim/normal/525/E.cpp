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
const int maxn = 30;

ll n, k, s, sz;
ll x[maxn];
ll fc[maxn] = {1};
map<ll, int> ma[maxn];
ll ans;

void rec(bool first, ll pos = 0, ll rez = 0, ll used = 0) {
	if(rez > s || used > k) return;
	if(pos == sz) {
		if(first) {
			ma[used][rez]++;
		} else {
			for(int i = 0; i <= k - used; i++) {
				if(ma[i].count(s - rez)) ans += ma[i][s - rez];
			}
		}
		return;
	}
	rec(first, pos + 1, rez, used);
	rec(first, pos + 1, rez + x[pos], used);
	if(x[pos] < 19) rec(first, pos + 1, rez + fc[x[pos]], used + 1);
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

	for(ll i = 1; i < 19; i++) fc[i] = fc[i - 1] * i;

	cin >> n >> k >> s;
	for(int i = 0; i < n; i++) {
		cin >> x[i];
	}
	sz = n / 2;
	rec(1);
	reverse(&x[0], &x[n]);
	sz = n - sz;
	rec(0);

	cout << ans;

	return(0);
}

// by Kim Andrey