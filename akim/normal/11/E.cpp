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

string s, t;

//double check(string s) {
//    s = s + s;
//    int n = s.length();
//    int cnt = 0;
//    for(int i = 0; i < n; i++) {
//        if(i & 1) {
//            cnt += s[i] == 'R';
//        } else {
//            cnt += s[i] == 'L';
//        }
//    }
//    cout << cnt << " " << n << endl;
//    return((1. * cnt) / (1. * n));
//}

long double check(string s) {
    int g=0,t=0,f=0,c=0;
	for (unsigned int i=0;i<s.length();i++)
	{
		if (s[i]=='X')
			t++;
		else if (s[i]==(t&1?'R':'L'))
			g++,t++,f=0;
		else
			g++,t+=2,c+=f,f=!f;
	}
	if (t & 1)
		t++,c+=f;
	if (g*2>t)
		g-=c,t-=c*2;
	return double(g)/t;
}

int main() {

	#ifdef SOL
	{
//		freopen("input.txt", "r", stdin);
//		freopen("output.txt", "w", stdout);
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

    getline(cin, s);
    int n = s.length();
    for(int i = 0; i < n; i++) {
        if(i && s[i] == s[i - 1] && s[i] != 'X') t += 'X';
        t += s[i];
    }
    long double ans;
    if(s[0] == s[n - 1] && s[0] != 'X') {
        ans = max(check('X' + t), check(t + 'X'));
    } else {
        ans = check(t);
    }
    printf("%.6lf\n", double(floor(ans * 1e8) / 1e6));

	#ifdef SOL
	{
		fflush(stdout);
		fprintf(stderr, "%.3lf ms\n", 1000. * clock() / CLOCKS_PER_SEC);
		fflush(stderr);
	}
	#endif
	return(0);
}

// by Andrey Kim