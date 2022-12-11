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

priority_queue<int> q;
map<int, int> ma;
int x[330], z[330];
vector<pair<int, int> > vc;
vector<int> ch;

int gcd(int a, int b) {
	while(b) {
		a %= b;
		swap(a, b);
	}
	return(a);
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
	int gcdall;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		cin >> x[i];
		ch.pb(x[i]);
		ma[x[i]] = mod;
		if(i == 0) {
			gcdall = x[i];
		} else {
			gcdall = gcd(gcdall, x[i]);
		}
	}

	if(gcdall != 1) {
		cout << -1;
		return(0);
	}

	for(int i = 0; i < n; i++) {
		cin >> z[i];
ma[x[i]] = min(ma[x[i]], z[i]);
		q.push(x[i]);
	}

	while(!q.empty()) {
		int p = q.top(); q.pop();
		for(int i = 0; i < n; i++) {
//			if(p > x[i]) {
				int c = gcd(x[i], p);
				if(ma.count(c) == 0) {
					ma[c] = ma[p] + z[i];
					q.push(c);
				} else {
					ma[c] = min(ma[p] + z[i], ma[c]);
				}
//			}
		}
	}
	cout << ma[1];


	return(0);
}

// by Kim Andrey