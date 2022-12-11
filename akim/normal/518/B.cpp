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

int up[maxn];
int down[maxn];

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

	string s, t;
	getline(cin, s), getline(cin, t);
	int yra = 0, opa = 0;
	for(int i = 0; i < (int)s.length(); i++) {
		if(s[i] >= 'a' && s[i] <= 'z') {
			down[s[i] - 'a']++;
		}
		if(s[i] >= 'A' && s[i] <= 'Z') {
			up[s[i] - 'A']++;
		}
	}
	for(int i = 0; i < (int)t.length(); i++) {
		if(t[i] >= 'a' && t[i] <= 'z') {
			if(down[t[i] - 'a']-- > 0) {
				yra++;
			}
		}
		if(t[i] >= 'A' && t[i] <= 'Z') {
			if(up[t[i] - 'A']-- > 0) {
				yra++;
			}
		}
	}

	for(int i = 0; i < 26; i++) {
		if(up[i] < 0 && down[i] > 0) {
			opa += min(abs(up[i]), down[i]);
		}
		if(up[i] > 0 && down[i] < 0) {
			opa += min(up[i], abs(down[i]));
		}
	}

	cout << yra << " " << opa;

	return(0);
}

// by Kim Andrey