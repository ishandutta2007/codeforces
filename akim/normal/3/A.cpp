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

	vector<string> vc;
	char a1, b1;
	int a, b, c, d;
	cin >> a1 >> c >> b1 >> d;

	a = a1 - 'a', b = b1 - 'a';
	while(a < b && c < d) {
		vc.pb("RU");
		a++, c++;
	}
	while(a < b && c > d) {
		vc.pb("RD");
		a++, c--;
	}
	while(a > b && c < d) {
		vc.pb("LU");
		a--, c++;
	}
	while(a > b && c > d) {
		vc.pb("LD");
		a--, c--;
	}
	while(a < b) {
		vc.pb("R");
		a++;
	}
	while(a > b) {
		vc.pb("L");
		a--;
	}
	while(c < d) {
		vc.pb("U");
		c++;
	}
	while(c > d) {
		vc.pb("D");
		c--;
	}

	cout << vc.size() << endl;
	for(int i = 0; i < (int)vc.size(); i++) {
		cout << vc[i] << endl;
	}

	return(0);
}

// by Kim Andrey