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
#define abs(a) ((a) < 0 ? -(a) : (a))
#define sqr(a) ((a) * (a))

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
	{
		srand(time(0));
		const string file = "";
		if(!file.empty()) {
			freopen((file + ".in").c_str(), "r", stdin);
			freopen((file + ".out").c_str(), "w", stdout);
		}
	}
	#endif

	vector<ll> vc;
	vc.pb(1);
	string s;
	getline(cin, s);
	reverse(s.begin(), s.end());
	s.pb('*');
	reverse(s.begin(), s.end());
	s.pb('*');
	s.pb('1');
	ll ans = 0;
	ll val = 0, stck = 1;
	for(int i = 0; i < (int)s.length(); i += 2) {
		if(s[i] == '*') {
			ll nval = 0, nstck = s[i + 1] - '0';
			for(int f = i + 2; f < (int)s.length(); f += 2) {
				if(s[f] == '*') {
					ll nnval = val, nnstck = stck * (nval + nstck);
					for(int g = f; g < (int)s.length(); g += 2) {
						if(s[g] == '*') {
							nnstck *= s[g + 1] - '0';
						} else {
							nnval += nnstck;
							nnstck = s[g + 1] - '0';
						}
					}
					nnval += nnstck;
					ans = max(ans, nnval);
					nstck *= s[f + 1] - '0';
				} else {
					nval += nstck;
					nstck = s[f + 1] - '0';
				}
			}
			nval += nstck;
			stck *= s[i + 1] - '0';
		} else {
			val += stck;
			stck = s[i + 1] - '0';
		}
	}
	val += stck;
	ans = max(ans, val);

	printf("%I64d", ans);

	return(0);
}

// by Kim Andrey