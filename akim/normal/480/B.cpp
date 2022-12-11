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

ll d[100100];

int main() {

//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	long long l, x, y, n;
	scanf("%I64d%I64d%I64d%I64d", &n, &l, &x, &y);
	for(int i = 0; i < n; i++) {scanf("%I64d", &d[i]);}
	bool bv2 = 0, bv3 = 0, f1 = 0, f2 = 0;
	vector<int> v2, v3;
	ll rxy = abs(x - y), sxy = x + y;
	{
		int fx = 0, fy = 0, frxy = 0, fsxy = 0;
		for(int i = 0; i < n; i++) {

			while(fx < n && d[fx] - d[i] < x) {
				fx++;
			}
			if(fx < n && d[fx] - d[i] == x) {f1 = 1;}

			while(fy < n && d[fy] - d[i] < y) {
				fy++;
			}
			if(fy < n && d[fy] - d[i] == y) {f2 = 1;}

			if(x != y) {
				while(frxy < n && d[frxy] - d[i] < rxy) {
					frxy++;
				}
				if(!bv2 && frxy < n && d[frxy] - d[i] == rxy) {
					if(d[i] - min(x, y) >= 0) {
						bv2 = 1;
						v2.pb(d[i] - min(x, y));
					} else
					if(d[frxy] + min(x, y) <= l) {
						bv2 = 1;
						v2.pb(d[frxy] + min(x, y));
					}
				}

				while(fsxy < n && d[fsxy] - d[i] < sxy) {
					fsxy++;
				}
				if(!bv3 && fsxy < n && d[fsxy] - d[i] == sxy) {
					bv3 = 1;
					v3.pb(d[i] + x);
				}
			}
		}
	}

	if(x == y) {
		if(f1) {printf("0\n");} else
		{printf("1\n%I64d", x);}
		return(0);
	}
	if(f1 && f2) {
		printf("0\n");
	} else
	if(f1) {
		printf("1\n%I64d", y);
	} else
	if(f2) {
		printf("1\n%I64d", x);
	} else
	if(bv2) {
		printf("1\n%d", v2[0]);
	} else
	if(bv3) {
		printf("1\n%d", v3[0]);
	} else {
		printf("2\n%I64d %I64d", min(x, y), max(x, y));
	}

	return(0);
}

// by Kim Andrey