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
const int maxn = 100100;

char c[200][200];
int bal[200][200];


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

	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++) {
		scanf("\n");
		for(int f = 0; f < m; f++) {
			c[i][f] = getchar();
		}
	}
	int ans = 0;
	for(int i = n - 1; i >= 0; i--) {
		for(int f = m - 1; f >= 0; f--) {
			if(c[i][f] == 'W') {
				if(bal[i][f] != 1) {
					for(int g = 0; g <= i; g++) {
						for(int h = 0; h <= f; h++) {
							bal[g][h] += (1 - bal[i][f]);
						}
					}
					ans++;
				}
			} else {
				if(bal[i][f] != -1) {
					for(int g = 0; g <= i; g++) {
						for(int h = 0; h <= f; h++) {
							bal[g][h] += (-1 - bal[i][f]);
						}
					}
					ans++;
				}
			}
		}
	}
	printf("%d", ans);

	return(0);
}

// by Kim Andrey