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
const int maxn = 330;

char c[maxn][maxn];

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
	for(int i = 0; i < m; i++) {
		for(int f = 0; f < n; f++) {
			cin >> c[f * 2][i * 2];
			c[f * 2 + 1][i * 2] = c[f * 2][i * 2];
			c[f * 2][i * 2 + 1] = c[f * 2][i * 2];
			c[f * 2 + 1][i * 2 + 1] = c[f * 2][i * 2];
		}
	}
	for(int i = 0; i < n * 2; i++) {
		for(int f = 0; f < m * 2; f++) {
			cout << c[i][f];
		}cout << endl;
	}

	return(0);
}

// by Kim Andrey