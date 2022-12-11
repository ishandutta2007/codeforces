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

	int xp, yp, xv, yv;
	cin >> xp >> yp >> xv >> yv;

	while(1) {
		if(xp == 0 && yp == 0) {
			cout << "Polycarp";
			return(0);
		}
		if(xv == 0 && yv == 0) {
			cout << "Vasiliy";
			return(0);
		}
		if(xv - xp > yv - yp) {
			if(yp - 1 >= 0) {yp--;} else {xp--;}
		} else {
			if(xp - 1 >= 0) {xp--;} else {yp--;}
		}
		if(xv - 1 >= 0) xv--;
		if(yv - 1 >= 0) yv--;
		if(xv == xp && yv ==  yp) {
			cout << "Polycarp";
			return(0);
		}
	}

	return(0);
}

// by Kim Andrey