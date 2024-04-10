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

	int n, k; scanf("%d%d", &n, &k);
	int l = 2, r = n;
	cout << 1 << " ";
	for(int i = 1; i < k; i++) {
		if(i & 1) {
			cout << r << " "; r--;
		} else {
			cout << l << " "; l++;
		}
	}
	if(k & 1) {
		for(; l <= r; l++) {
			cout << l << " ";
		}
	} else {
		for(; r >= l; r--) {
			cout << r << " ";
		}
	}


	return(0);
}

// by Kim Andrey