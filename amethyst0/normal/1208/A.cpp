#pragma comment(linker, "/STACK:1000000000")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <ctime>
#include <random>
#include <bitset>
#include <cstring>
#include <memory.h>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;

int main() {
	int t;

	cin >> t;

	while (t--) {
		int a, b, n;

		cin >> a >> b >> n;

		n %= 3;

		if (n == 0) {
			cout << a << endl;
		}
		else if (n == 1) {
			cout << b << endl;
		}
		else {
			cout << (a ^ b) << endl;
		}
	}

	//system("pause");
	return 0;
}