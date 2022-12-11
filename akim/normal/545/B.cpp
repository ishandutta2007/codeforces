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

	string s, t;
	getline(cin, s);
	getline(cin, t);
	int cnt = 0, n = s.length();
	for(int i = 0; i < n; i++) {
		if(s[i] != t[i]) {
			cnt++;
		}
	}

	if(cnt & 1) {
		printf("impossible\n");
		return(0);
	}

	cnt >>= 1;

	for(int i = 0; i < n; i++) {
		if(s[i] != t[i]) {
			if(cnt > 0) {
				printf("%c", s[i]);
			} else {
				printf("%c", t[i]);
			}
			cnt--;
		} else {
			printf("0");
		}
	}

	return(0);
}

// by Kim Andrey