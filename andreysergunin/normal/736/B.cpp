#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#include <cassert>
#include <unordered_map>
#include <fstream>
#include <random>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;

const int MAXN = 1e5;

bool isPrime(int n) {
	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0)
			return false;
	}
	return true;
}

int main()
{

	// ifstream cin("joke.in");
	// ofstream cout("joke.out");

	int n;
	cin >> n;
	if (isPrime(n)) {
		cout << 1 << endl;
		return 0;
	}

	if (n % 2 == 0) {
		cout << 2 << endl;
		return 0;
	}

	if (isPrime(n - 2)) {
		cout << 2 << endl;
		return 0;
	}

	cout << 3 << endl;


}