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

int x[20];
int now[20], ansd[20];
int n, a, b, ans = mod;

void dfs(int u, int n, int cnt = 0) {
	if(ans < cnt) {
		return;
	}
	if(u == n - 1) {
		if(x[n - 1] <= 0 && x[n - 2] <= 0 && ans > cnt) {
			ans = cnt;
			for(int i = 0; i < n; i++) {
				ansd[i] = now[i];
			}
		}
		return;
	}

	int mind = max((x[u - 1] + b - 1) / b, 0), maxd = max(max((x[u] + a - 1) / a, (x[u + 1] + b - 1) / b), mind);

	for(int i = mind; i <= maxd; i++) {
		x[u - 1] -= i * b;
		x[u] -= i * a;
		x[u + 1] -= i * b;

		now[u] = i;
		dfs(u + 1, n, cnt + i);

		x[u - 1] += i * b;
		x[u] += i * a;
		x[u + 1] += i * b;
	}
}

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

	scanf("%d%d%d", &n, &a, &b);
	for(int i = 0; i < n; i++) {
		scanf("%d", &x[i]);
		x[i]++;
	}
	dfs(1, n);

	cout << ans << "\n";
	for(int i = 0; i < n; i++) {
		while(ansd[i] > 0) {
			ansd[i]--;
			cout << i + 1 << " ";
		}
	}

	return(0);
}

// by Kim Andrey