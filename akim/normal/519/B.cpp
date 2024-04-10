#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <stdio.h>
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
int y[maxn];
int z[maxn];

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
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> x[i];
	}
	sort(&x[0], &x[n]);
	for(int i = 0; i < n - 1; i++) {
		cin >> z[i];
	}
	sort(&z[0], &z[n - 1]);
	bool ok = 0;
	for(int i = 0; i < n - 1; i++) {
		if(x[i] != z[i]) {
			if(!ok) {
				cout << x[i] << endl;
			}
			ok = 1;
			x[i] = x[i + 1];
		}
	}
	if(!ok) {
		cout << x[n - 1] << endl;
	}
	n--;
	for(int i = 0; i < n - 1; i++) {
		cin >> z[i];
	}
	sort(&z[0], &z[n - 1]);
	ok = 0;
	for(int i = 0; i < n - 1; i++) {
		if(x[i] != z[i]) {
			if(!ok) {
				cout << x[i] << endl;
			}
			ok = 1;
			x[i] = x[i + 1];
		}
	}
	if(!ok) {
		cout << x[n - 1] << endl;
	}

	return(0);
}

// by Kim Andrey