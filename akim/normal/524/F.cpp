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
const int maxn = 20 * 100100;
const int prmod = (int)1e+9 + 9;
const ll st = 31;

string s;
vector<int> vc;
int pr[maxn * 2];
ll hash[maxn * 2];
int anspos = 0, ansbal = 0;

int binpow(ll b) {
	ll a = st, ans = 1;
	while(b) {
		if(b & 1) {
			ans = ans * a % prmod;
		}
		b >>= 1;
		a = a * a % prmod;
	}
	return(ans);
}

bool cmp(int u, int v) {
	int rz = v - u;
	int m = s.length();
	if(((hash[u + m - 1] - (u - 1 >= 0 ? hash[u - 1] : 0) + prmod) % prmod * binpow(rz)) % prmod == (hash[v + m - 1] - (v - 1 >= 0 ? hash[v - 1] : 0) + prmod) % prmod) {
		return(0);
	}
	int l = 0, r = s.length() + 1;
	while(l + 1 < r) {
		int m = (l + r) / 2;
		if(((hash[u + m - 1] - (u - 1 >= 0 ? hash[u - 1] : 0) + prmod) % prmod * binpow(rz)) % prmod == (hash[v + m - 1] - (v - 1 >= 0 ? hash[v - 1] : 0) + prmod) % prmod) {
			l = m;
		} else {
			r = m;
		}
	}
	if(s[(u + l + s.length()) % s.length()] == '(') {
		return(0);
	} else {
		return(1);
	}
}

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
	int opened = 0;
	getline(cin, s);
	int ls = s.length();
	ll sst = 1;
	int cnt1 = 0, cnt2 = 0;
//
	for(int i = 0; i < ls * 2; i++) {
		hash[i] = hash[i - 1] + s[i % ls] * sst % prmod;
		sst = sst * st % prmod;
		pr[i] = -1;
		if(s[(i + s.length()) % ls] == '(') {
			cnt1++;
			vc.pb((i + s.length()) % ls);
		} else {
			cnt2++;
			if(!vc.empty()) {
				pr[(i + s.length()) % ls] = vc.back();
				pr[vc.back()] = (i + s.length()) % ls;
				vc.ppb();
				if(i < ls) {opened++;}
			}
		}
	}
//
	cnt1 >>= 1;
	cnt2 >>= 1;

	ansbal = opened;
	for(int i = 0; i < ls; i++) {
		if(opened == ansbal) {
			if(cmp(anspos, i)) {
				ansbal = opened;
				anspos = i;
			}
		} else if(opened > ansbal) {
			ansbal = opened;
			anspos = i;
		}
		if(s[i] == '(' && pr[i] != -1) {
			opened--;
		}
		if(s[i] == ')' && pr[i] != -1) {
			opened++;
		}
	}
	cnt1 -= ansbal;
	cnt2 -= ansbal;
	for(int i = 0; i < cnt2; i++) {
		cout << "(";
	}
	for(int i = 0; i < ls; i++) {
		cout << s[(anspos + i + s.length()) % ls];
	}
	for(int i = 0; i < cnt1; i++) {
		cout << ")";
	}




	return(0);
}

// by Kim Andrey