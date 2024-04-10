/*AMETHYSTS*/
//#pragma comment(linker, "/STACK:1000000000")
#include <cstdio>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#include <fstream>
#include <deque>
#include <stack>
#include <climits>
#include <string>
#include <queue>
#include <memory.h>
#include <map>
#include <unordered_map>
 
#define ll long long
#define ld double
#define pii pair <int, int>
#define pll pair <ll, ll>
#define mp make_pair
 
using namespace std;

vector <ll> a;

void make(ll x) {
	for (ll i = 2; i * i <= x; i++) {
		while (x % i == 0) {
			a.push_back(i);
			x /= i;
		}
	}

	if (x != 1) {
		a.push_back(x);
	}
}

int main() {
	ll x;

	cin >> x;

	make(x);

	if (x == 1 || a.size() == 1) {
		cout << 1 << endl;
		cout << 0 << endl;
		return 0;
	}

	if ((int)a.size() == 2) {
		cout << 2 << endl;
	} else {
		cout << 1 << endl;

		cout << (a[0] * a[1]) << endl;
	}

	return 0;
}