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

vector<int> vc, ch;

int main() {

	#ifdef SOL
	{
//		freopen("input.txt", "r", stdin);
//		freopen("output.txt", "w", stdout);
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

	string s, z, pr = "+";
	while(pr != "=") {
	cin >> s;
	cin >> z;
	vc.pb(pr == "+" ? 1 : 0);
	ch.pb(0);
	pr = z;
	}
	int n = vc.size(), m;
	cin >> m;
	ch[0] = m;
	for(int k = 0; k < n; k++) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if(i == j) continue;
				if(ch[j] == 0) {
					if(vc[j] == vc[i]) {
						if(ch[i] > 1) {
							ch[i]--;
							ch[j]++;
						}
					} else {
						if(ch[i] < m) {
							ch[i]++;
							ch[j]++;
						}
					}
				}
			}
		}
	}

	bool ok = 1;
	for(int i = 0; i < n; i++) {
		if(!(ch[i] > 0 && ch[i] <= m)) {
			ok = 0;
		}
	}

	if(ok) {
		printf("Possible\n");
		for(int i = 0; i < n; i++) {
			if(i) {
				printf("%c ", vc[i] == 1 ? '+' : '-');
			}
			printf("%d ", ch[i]);
		}
		printf("= %d", m);
	} else {
		printf("Impossible\n");
	}

	#ifdef SOL
	{
		fflush(stdout);
		fprintf(stderr, "%.3lf ms\n", 1000. * clock() / CLOCKS_PER_SEC);
		fflush(stderr);
	}
	#endif
	return(0);
}

// by Andrey Kim