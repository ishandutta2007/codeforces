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

int head;
int p[maxn], pm[maxn], ks, rz[maxn];
vector<int> beg;

void dfs(int u) {
	if(!pm[u]) {
		pm[u] = ks;
		rz[head]++;
		dfs(p[u]);
		return;
	}
}

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
	for(int i = 1; i <= n; i++) {
		scanf("%d", &p[i]);
	}
	bool ok1 = 0, ok2 = 0;
	int p1, p2;
	for(int i = 1; i <= n; i++) {
		if(!pm[i]) {
			beg.pb(i);
			head = i;
			ks++;
			rz[i] = 0;
			dfs(i);
			if(rz[i] == 1) {
				ok1 = 1;
				p1 = i;
			}
			if(rz[i] == 2) {
				ok2 = 1;
				p2 = i;
			}
		}
	}
	if(ok1) {
		printf("YES\n");
		for(int i = 0; i < (int)beg.size(); i++) {
			if(p1 != beg[i]) {
				for(int f = p[beg[i]]; f != beg[i]; f = p[f]) {
					printf("%d %d\n", p1, f);
				}
				printf("%d %d\n", p1, beg[i]);
			}
		}
	} else
	if(ok2) {
		for(int i = 0; i < (int)beg.size(); i++) {
			if(rz[beg[i]] & 1) {
				printf("NO\n");
				return(0);
			}
		}

		p1 = p2;

		printf("YES\n");
		for(int i = 0; i < (int)beg.size(); i++) {
			if(p1 != beg[i]) {
				for(int f = p[beg[i]], g = p[p1]; f != beg[i]; f = p[f], g = p[g]) {
					printf("%d %d\n", g, f);
				}
				printf("%d %d\n", p1, beg[i]);
			}
		}
		printf("%d %d\n", p1, p[p1]);

	} else {
		printf("NO\n");
		return(0);
	}

	return(0);
}

// by Kim Andrey