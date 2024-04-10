#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <cstring>
#include <map>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#define f first
#define s second
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define vi vector <int>
#define ld long double
#define pii pair<int, int>
using namespace std;    
const int N = int(3e5), mod = int(1e9)  + 7, inf = int(1e9);      



int s, d, n;
pair <int, int> a[N];
bool per(int la, int ra, int lb, int rb) {
 	if (la > rb || lb > ra) return 0;
 	return 1;
}
int main () {
	cin >> n;
	for (int i = 1; i <= n; i++) {
	 	cin >> s >> d;
	 	bool good = 1;
	 	for (int j = 1; j < i; j++)
	 		if (per(a[j].f, a[j].s, s, s + d - 1))
	 			good = 0;
	 	if (good) {
	 	 	a[i].f = s;
	 	 	a[i].s = s + d - 1;
	 		continue;
	 	}
	 	pair <int, int> res = mp(inf, inf);
	 	for (int j = 0; j < i; j++) {
	 	 	int l = a[j].s + 1, r = a[j].s + d;
	 	 	bool bad = 0;
	 	 	for (int k = 1; k < i; k++)
	 	 		if (per(a[k].f, a[k].s, l, r))
	 	 			bad = 1;	
	 		if (!bad) {
	 		 	res = min(res, mp(l, r));
	 		}
	 	}
	 	a[i] = res;

	}
	for (int i = 1; i <= n; i++) {
	 	cout << a[i].f << " " << a[i].s << endl;
	}
return 0;
}