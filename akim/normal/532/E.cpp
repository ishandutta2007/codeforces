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

	cin >> n;
	string s, t;
	cin >> s >> t;
	int lf = 0, rg = n - 1;
	while(s[lf] == t[lf]) lf++;
	while(s[rg] == t[rg]) rg--;

	bool ok1 = 1, ok2 = 1;
	for(int i = lf; i < rg; i++) {
		if(s[i] != t[i + 1]) ok1 = 0;
	}
	for(int i = lf; i < rg; i++) {
		if(s[i + 1] != t[i]) ok2 = 0;
	}

	cout << ok1 + ok2;

	return(0);
}

// by Kim Andrey