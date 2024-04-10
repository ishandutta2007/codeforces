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

	ll n, m; scanf("%I64d%I64d", &n, &m);
	ll o1 = (n - m + 1) * (n - m) / 2;
	ll c = n / m;
	ll ost = n % m;
	ll o2 = (c * (c - 1)) / 2 * (m - ost) + (c * (c + 1)) / 2 * ost;
	printf("%I64d %I64d", o2, o1);

	return(0);
}

// by Kim Andrey