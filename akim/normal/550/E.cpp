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

int a[maxn];

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
		scanf("%d", &a[i]);
	}
	if(a[n - 1] != 0) {
		printf("NO");
		return(0);
	}
	if(n == 1) {
		printf("YES\n0");
		return(0);
	}

	string ans = "0";
	bool skobki = 1;
	int st = n - 2;
	if(a[n - 2] == 1) {
		skobki = 0;
	} else {
		st = n - 3;
		ans += ">-))0";
	}
	for(int i = st; i >= 0; i--) {
		if(skobki) {
			if(a[i] == 1) {
				ans += ">-";
				ans += (a[i] == 0 ? "0" : "1");
			} else {
				ans += "(>-";
				ans += (a[i] == 0 ? "0" : "1");
				ans += "(";
				skobki = 0;
			}
		} else {
			ans += ">-";
			ans += (a[i] == 0 ? "0" : "1");
		}
	}

	reverse(ans.begin(), ans.end());
	if(!skobki) {
		printf("YES\n%s", ans.c_str());
	} else {
		printf("NO\n");
	}

	return(0);
}

// by Kim Andrey