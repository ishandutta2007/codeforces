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

int x[100100];

int main() {

//	freopen("*.in","r",stdin);
//	freopen("*.out","w",stdout);
	
	int n, k, i; 
	scanf("%d%d", &n, &k);
	for(i = 1; i <= 2 * n; i++) {
     	x[i] = i;		
	}

	for(i = 1 ; i <= k; i++) {
		swap(x[i * 2], x[i * 2 - 1]);
	}

	for(i = 1; i <= 2 * n; i++) {
     	cout<<x[i]<<" ";
	}
	return(0);
}

// by Kim Andrey