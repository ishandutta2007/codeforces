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

int x[maxn];

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

	int n, k;
	cin >> n >> k;
	n += 2;
	x[0] = - 2 * mod;
	x[n - 1] = 2 * mod;
	for(int i = 1; i < n - 1; i++) {
		string s;
		cin >> s;
		if(s[0] == '?') {
			x[i] = mod;
		} else {
			for(int f = 0; f < (int)s.length(); f++) {
				if(s[f] == '-') continue;
				x[i] *= 10;
				x[i] += s[f] - '0';
			}
			if(s[0] == '-') {
				x[i] = -x[i];
			}
		}
	}
	for(int i = 0; i < k; i++) {
		for(int f = i; f < n; f += k) {
			if(x[f] != mod) continue;
			int l = f;
			while(f < n && x[f] == mod) {
				f += k;
			}
			int r = f;
			if(x[max(l - k, 0)] < 0 && x[min(n - 1, r)] < 0) {
				r -= k;
				while(r >= l) {
					x[r] = x[r + k] - 1;
					r -= k;
				}
				continue;
			}
			if(x[max(l - k, 0)] > 0 && x[min(n - 1, r)] > 0) {
				while(l < r) {
					x[l] = x[l - k] + 1;
					l += k;
				}
				continue;
			}

			int ans = (r - l) / k;
			int minl = (ans - 1) / 2, maxl = (ans - 1) - (ans - 1) / 2;
			bool badl = 0, badr = 0;
			if(x[max(l - k, 0)] >= -maxl) {
				badl = 1;
			}
			if(x[min(r, n - 1)] <= maxl) {
				badr = 1;
			}
			if(badl) {
				minl = max(x[max(l - k, 0)] + 1, -maxl);
				while(l < r) {
					x[l] = minl++;
					l += k;
				}
			} else
			if(badr) {
				minl = min(x[min(r, n - 1)] - 1, maxl);
				r -= k;
				while(l <= r) {
					x[r] = minl--;
					r -= k;
				}
			} else {
				maxl = - maxl;
				while(l < r) {
					x[l] = maxl++;
					l += k;
				}
			}
		}
		for(int f = i; f < n; f += k) {
			if(f == 0) continue;
			if(x[max(f - k, 0)] >= x[f]) {
				cout << "Incorrect sequence";
				return(0);
			}
		}
	}

	for(int i = 1; i < n - 1; i++) {
		cout << x[i] << " ";
	}

	return(0);
}

// by Kim Andrey