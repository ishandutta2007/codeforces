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

int ms[maxn], mr[maxn], mt[maxn];

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

	string s, t, r;
	cin >> s;
	cin >> t;
	cin >> r;
	int ls = s.length(), lt = t.length(), lr = r.length();
	for(int i = 0; i < ls; i++) {
		ms[s[i] - 'a']++;
	}
	for(int i = 0; i < lt; i++) {
		mt[t[i] - 'a']++;
	}
	for(int i = 0; i < lr; i++) {
		mr[r[i] - 'a']++;
	}
	int ans = -1, ansa = 0, ansb = 0;
	for(int i = 0; ; i++) {
		int b = mod;
		bool ok = 1;
		for(int f = 0; f < 26; f++) {
			ms[f] -= mt[f] * i;
			if(ms[f] < 0) ok = 0;
			if(mr[f] > 0) b = min(b, ms[f] / mr[f]);
			ms[f] += mt[f] * i;
		}
		if(!ok) break;
		if(i + b > ans) {
			ans = i + b;
			ansa = i;
			ansb = b;
		}
	}
	int out = 0;
	for(int i = 0; i < ansa; i++) {
		printf("%s", t.c_str());
	}
	for(int i = 0; i < ansb; i++) {
		printf("%s", r.c_str());
	}
	for(int i = 0; i < 26; i++) {
		for(int f = 0; f < ms[i] - ansa * mt[i] - ansb * mr[i]; f++) {
			printf("%c", i + 'a');
		}
	}

	return(0);
}

// by Kim Andrey