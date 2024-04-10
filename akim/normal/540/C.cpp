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

int xs, ys, xf, yf;
char c[550][550];
bool pm[550][550];
priority_queue<pair<int, pair<int, int> > > q;

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

	scanf("%d%d", &xs, &ys); xs--, ys--;
	scanf("%d%d", &xf, &yf); xf--, yf--;

	q.push(mp(0, mp(xs, ys)));
	while(!q.empty()) {
		int xn = q.top().sc.fs, yn = q.top().sc.sc, t = q.top().fs;
		q.pop();
		if(xn < 0 || xn >= n || yn < 0 || yn >= m || pm[xn][yn]) {
			continue;
		}
		pm[xn][yn] = 1;
		if(xn == xf && yn == yf) {
			int cnt = 0;
			if(yn + 1 < m && c[xn][yn + 1] == '.') {cnt++;};
			if(yn - 1 >= 0 && c[xn][yn - 1] == '.') {cnt++;};
			if(xn + 1 < n && c[xn + 1][yn] == '.') {cnt++;};
			if(xn - 1 >= 0 && c[xn - 1][yn] == '.') {cnt++;};
			if(c[xs][ys] == 'X' && abs(xf - xs) + abs(yf - ys) == 1 && cnt >= 1) {
				cout << "YES";
			} else
			if(cnt > 1 || (t < 0 && c[xn][yn] == 'X') || (t == 0 && cnt >= 1)) {
				cout << "YES";
			} else {
				cout << "NO";
			}
			return(0);
		}
		if(c[xn][yn] != 'X' || t == 0) {
			q.push(mp(t - 1, mp(xn, yn + 1)));
			q.push(mp(t - 1, mp(xn, yn - 1)));
			q.push(mp(t - 1, mp(xn + 1, yn)));
			q.push(mp(t - 1, mp(xn - 1, yn)));
		}
	}

	cout << "NO";

	return(0);
}

// by Kim Andrey