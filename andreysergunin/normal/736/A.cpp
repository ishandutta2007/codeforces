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

int main()
{

	// ifstream cin("joke.in");
	// ofstream cout("joke.out");

	long long n;
	cin >> n;
	vector<long long> f(MAXN);
	f[0] = 1;
	f[1] = 2;
	int i = 1;
	for (; f[i] <= n; ++i) {
		f[i + 1] = f[i] + f[i - 1];
	}

	cout << i - 1 << endl;

}