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

char s[110][110];
bool pm[110][110];

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
		cin >> s[i];
	}

	int ans = 0;

	for(int f = 0; f < m; f++) {
		bool ok = 1;
		for(int i = 0; i < n - 1; i++) {
			if(!pm[i][f]) {
				if(s[i][f] > s[i + 1][f]) {
					ok = 0;
				}
			}
		}
		if(ok) {
			for(int i = 0; i < n - 1; i++) {
				if(!pm[i][f]) {
					if(s[i][f] < s[i + 1][f]) {
						pm[i][f + 1] = 1;
					}
				} else {
					pm[i][f + 1] = 1;
				}
			}
		} else {
			ans += 1;
			for(int i = 0; i < n - 1; i++) {
				if(pm[i][f]) {
					pm[i][f + 1] = 1;
				}
			}
		}
	}

	cout << ans;

	return(0);
}

// by Kim Andrey