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

int x[maxn];

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

	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &x[i]);
	}

	sort(&x[0], &x[n]);
	reverse(&x[0], &x[n]);
	vector<int> ans;
	for(int i = 0; i < n - 1;) {
		if(x[i] == x[i + 1]) {
			ans.pb(x[i]);
			i += 2;
		} else
		if(x[i] - 1 == x[i + 1]) {
			ans.pb(x[i + 1]);
			i += 2;
		} else {
			i++;
		}
	}
	ll otv = 0;
	for(int i = 0; i + 1 < (int)ans.size(); i += 2) {
		otv += 1ll * ans[i] * ans[i + 1];
	}

	cout << otv;

	return(0);
}

// by Kim Andrey