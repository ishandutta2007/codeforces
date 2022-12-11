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
const int maxn = 200100;

map<int, int> w, h;
int W, H;
int wr[maxn], hr[maxn];

void add(int *x, int sz, int pos, int val) {
	for (; pos <= sz; pos = (pos | (pos + 1)))
		x[pos] += val;
}

int get(int *x, int pos) {
	int res = 0;
	for (; pos >= 0; pos = (pos & (pos + 1)) - 1)
		res += x[pos];
	return res;
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

	int n;
	scanf("%d%d%d", &W, &H, &n);
	add(wr, W, 0, W);
	add(hr, H, 0, H);
	w[W] = 1;
	h[H] = 1;
	for(int i = 0; i < n; i++) {
		char c;
		int v;
		scanf("\n%c%d", &c, &v);
//		for(map<int, int>::iterator it = w.begin(); it != w.end(); it++) {
//			cout << (*it).fs << " ";
//		}cout << endl;
		if(c == 'H') {
			int l = 0, r = v;
			while(l + 1 < r) {
				int m = (l + r) / 2;
				if(get(hr, v) - get(hr, m - 1) > 0) {
					l = m;
				} else {
					r = m;
				}
			}
			int val = get(hr, l) - get(hr, l - 1);
			add(hr, H, l, v - l - val);
			add(hr, H, v, l + val - v);
			h[v - l]++;
			h[l + val - v]++;
			h[val]--;
			if(h[val] == 0) h.erase(val);
		} else {
			int l = 0, r = v;
			while(l + 1 < r) {
				int m = (l + r) / 2;
				if(get(wr, v) - get(wr, m - 1) > 0) {
					l = m;
				} else {
					r = m;
				}
			}
			int val = get(wr, l) - get(wr, l - 1);
			add(wr, W, l, v - l - val);
			add(wr, W, v, l + val - v);
			w[v - l]++;
			w[l + val - v]++;
			w[val]--;
			if(w[val] == 0) w.erase(val);
		}
		cout << 1ll * (*w.rbegin()).fs * (*h.rbegin()).fs << endl;
	}

	return(0);
}

// by Kim Andrey