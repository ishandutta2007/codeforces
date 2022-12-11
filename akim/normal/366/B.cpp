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

const double eps = 1e-9;
const int mod = (int)1e+9 + 7;
const double pi = acos(-1.0);

int ms[100100];

int main() {

//	freopen("*.in","r",stdin);
//	freopen("*.out","w",stdout);
	
	int n, c, k;

	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i++) {
		scanf("%d", &c);
		ms[i] = c;
	}
	int num = 0, rzm = mod;
	for(int i = 0; i < k; i++) {
		int nnum = i, nrzm = 0;
		for(int f = i; f < n; f+=k) {
			nrzm += ms[f];
		}
		if(nrzm < rzm) {rzm = nrzm; num = nnum;}
	}
	cout << num + 1;
	return(0);
}

// by Kim Andrey