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

	int n, A = 0, C = 0, G = 0, T = 0;
	string s;
	cin >> n;
	cin >> s;
	for(int i = 0; i < n; i++) {
		if(s[i] == 'A') A++;
		if(s[i] == 'C') C++;
		if(s[i] == 'G') G++;
		if(s[i] == 'T') T++;
	}
	int mx = max(max(A, C), max(G, T));
	ll cnt = 0;
	if(mx == A) cnt++;
	if(mx == C) cnt++;
	if(mx == G) cnt++;
	if(mx == T) cnt++;

	ll ans = 1;
	for(int i = 0; i < n; i++) {
		ans *= cnt;
		ans %= mod;
	}
	cout << ans;

	return(0);
}

// by Kim Andrey