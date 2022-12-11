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



int main() {

//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int t; scanf("%d", &t);
	for(; t > 0; t--) {
		ull l, r, x, z;
		cin >> l >> r; r++;
		x = 0, z = (1ll << 63ll);
		while(z > 0) {
			if((l & z) != (r & z)) {
				x <<= 1;
				z >>= 1;
				break;
			} else {
				x <<= 1;
				x |= ((l & z) ? 1 : 0);
			}
			z >>= 1;
		}
		while(z > 0) {
			x <<= 1;
			x |= 1;
			z >>= 1;
		}
		if(x == r) {r--;
			x = 0, z = (1ll << 63ll);
			while(z > 0) {
				if((l & z) != (r & z)) {
					x <<= 1;
					z >>= 1;
					break;
				} else {
					x <<= 1;
					x |= ((l & z) ? 1 : 0);
				}
				z >>= 1;
			}
			while(z > 0) {
				x <<= 1;
				x |= 1;
				z >>= 1;
			}
		}
		cout << x << "\n";
		//fflush(stdout);
	}


	return(0);
}

// by Kim Andrey