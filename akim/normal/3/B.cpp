#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <cassert>
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

	vector<pair<int, int> > vc[2];
	vector<int> ans;

	int n, v, otv = 0;
	scanf("%d%d", &n, &v);
	for(int i = 0; i < n; i++) {
		int t, g;
		scanf("%d%d", &t, &g);
		t--;
		vc[t].pb(mp(g, i + 1));
	}
	sort(vc[0].begin(), vc[0].end());
	sort(vc[1].begin(), vc[1].end());
	int p0 = (int)vc[0].size() - 1, p1 = (int)vc[1].size() - 1;
	while((v > 0 && p0 >= 0) || (v > 1 && p1 >= 0)) {
		if(p0 >= 0) {
			if(p1 < 0 || v == 1 || (vc[0][p0].fs + (p0 - 1 >= 0 ? vc[0][p0 - 1].fs : 0) >= vc[1][p1].fs)) {
				v -= 1;
				otv += vc[0][p0].fs;
				ans.pb(vc[0][p0].sc);
				p0--;
			} else {
				v -= 2;
				otv += vc[1][p1].fs;
				ans.pb(vc[1][p1].sc);
				p1--;
			}
		} else {
			v -= 2;
			otv += vc[1][p1].fs;
			ans.pb(vc[1][p1].sc);
			p1--;
		}
	}

	cout << otv << endl;
	for(int i = 0; i < (int)ans.size(); i++) {
		cout << ans[i] << " ";
	}

	return(0);
}

// by Kim Andrey