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

	string s;
	getline(cin, s);
	int n, ls = s.length();
	cin >> n;
	for(int i = 0; i < n; i++) {
		int q;
		cin >> q;
		x[q - 1]++;
		x[ls - q + 1]++;
	}
	int sum = 0;
	for(int i = 0; i < ls; i++) {
		sum += x[i];
		if(sum & 1) {
			cout << s[ls - i - 1];
		} else {
			cout << s[i];
		}
	}

	return(0);
}

// by Kim Andrey