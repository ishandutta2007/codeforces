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
const int maxn = 10 * 100100;

int z[maxn];
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

	int n, k;
	scanf("%d%d\n", &n, &k);
	string s;
	getline(cin, s);
	for(int i = 1, l = 0, r = 0; i < n; i++) {
		if(i <= r) {
			z[i] = min(r - i + 1, z[i - l]);
		}
		while(i + z[i] < n && s[z[i]] == s[z[i] + i]) {
			z[i]++;
		}
		if(i + z[i] - 1 > r) {
			l = i, r = i + z[i] - 1;
		}
	}
	z[0] = n;

	for(int i = 1; i <= n; i++) {
		int f = 0, cnt = 0;
		while(f < n && cnt < k && z[f] >= i) {
			f += i;
			cnt++;
		}
		if(cnt != k) continue;
		vc.pb(mp(i * k - 1, 1));
		vc.pb(mp(min(min(i * k + z[i * k] - 1, i * k + i - 1), n - 1) + 1, -1));
	}

	sort(vc.begin(), vc.end());

	int bal = 0, f = 0;
	for(int i = 0; i < n; i++) {
		while(f < (int)vc.size() && vc[f].fs == i) {
			bal += vc[f++].sc;
		}
		if(bal <= 0) {printf("0");} else {printf("1");}
	}

	return(0);
}

// by Kim Andrey