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
const double pi = acos(-1.0);

int x[5500][2];

int main() {

//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	int n, a, b, k; scanf("%d%d%d%d", &n, &a, &b, &k);a--;b--;
	x[a][0] = 1; x[a + 1][0] = -1;
	for(int i = 0; i < k; i++) {
		if(i & 1) {
			for(int f = 0; f < n; f++) {
				x[f][0] = 0;
			}
			int s = 0;
			for(int f = 0; f < n; f++) {
				s = (s + x[f][1]) % mod;
				if(f == b) continue;
				int ll = max(0, f - (abs(b - f) - 1)), rr = min(n - 1, f + (abs(b - f) - 1)) + 1;
				x[ll][0] = (x[ll][0] + s) % mod;
				x[f][0] = (x[f][0] - s) % mod;
				x[f + 1][0] = (x[f + 1][0] + s) % mod;
				x[rr][0] = (x[rr][0] - s) % mod;
			}
		} else {
			for(int f = 0; f < n; f++) {
				x[f][1] = 0;
			}
			int s = 0;
			for(int f = 0; f < n; f++) {
				s = (s + x[f][0]) % mod;
				if(f == b) continue;
				int ll = max(0, f - (abs(b - f) - 1)), rr = min(n - 1, f + (abs(b - f) - 1)) + 1;
				x[ll][1] = (x[ll][1] + s) % mod;
				x[f][1] = (x[f][1] - s) % mod;
				x[f + 1][1] = (x[f + 1][1] + s) % mod;
				x[rr][1] = (x[rr][1] - s) % mod;
			}
		}
	}
	int otv = 0;
	int s = 0;
	for(int f = 0; f < n; f++) {
		s = (s + x[f][k & 1]) % mod;
		otv = (otv + s) % mod;
	} if(otv < 0) {otv += mod;}
	cout << otv;

	return(0);
}

// by Kim Andrey