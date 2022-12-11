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

	char c[550][550] = {0};
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++) {
		scanf("\n");
		for(int f = 0; f < m; f++) {
			scanf("%c", &c[i][f]);
		}
	}
	int ans = 0;
	for(int i = 1; i < n; i++) {
		for(int f = 1; f < m; f++) {
			vector<char> vc;
			vc.pb(c[i][f]);
			vc.pb(c[i - 1][f]);
			vc.pb(c[i][f - 1]);
			vc.pb(c[i - 1][f - 1]);
			sort(vc.begin(), vc.end());
			if(vc[0] == 'a' && vc[1] == 'c' && vc[2] == 'e' && vc[3] == 'f') {
				ans++;
			}
		}
	}
	printf("%d", ans);

	return(0);
}

// by Kim Andrey