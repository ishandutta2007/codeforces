/*AMETHYSTS*/
#pragma comment(linker, "/STACK:1000000000")
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
#define ld double
#define mp make_pair
#define ll long long
#define pii pair <int, int>

using namespace std;

int main() {
	int n;

	cin >> n;

	if (n == 1) {
		cout << 0 << endl;
	} else if (n % 2 == 0) {
		cout << (n - 2) / 2 << endl;
	} else {
		cout << n / 2 << endl;
	}

	return 0;
}