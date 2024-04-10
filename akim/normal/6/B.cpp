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

char c[110][110];

bool pm[26];

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

	int n, m, ans = 0;
	char color;
	cin >> n >> m >> color;
	for(int i = 0; i < n; i++) {
		for(int f = 0; f < m;  f++) {
			cin >> c[i][f];
		}
	}

	pm[color - 'A'] = 1;

	for(int i = 0; i < n; i++) {
		for(int f = 0; f < m; f++) {
			if(c[i][f] == color) {
				if(i - 1 >= 0 && c[i - 1][f] != '.' && !pm[c[i - 1][f] - 'A']) {
					ans++;
					pm[c[i - 1][f] - 'A'] = 1;
				}
				if(i + 1 < n && c[i + 1][f] != '.' && !pm[c[i + 1][f] - 'A']) {
					ans++;
					pm[c[i + 1][f] - 'A'] = 1;
				}
				if(f - 1 >= 0 && c[i][f - 1] != '.'&& !pm[c[i][f - 1] - 'A']) {
					ans++;
					pm[c[i][f - 1] - 'A'] = 1;
				}
				if(f + 1 < m && c[i][f + 1] != '.' && !pm[c[i][f + 1] - 'A']) {
					ans++;
					pm[c[i][f + 1] - 'A'] = 1;
				}
			}
		}
	}

	cout << ans;

	return(0);
}

// by Kim Andrey