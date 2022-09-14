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
#include <string.h>
#include <assert.h>
#include <complex>
#include <random>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
mt19937 rr(random_device{}());

int main() {
	// freopen("input.txt", "r", stdin);
	
	int n;
	cin >> n;
	if (n <= 500) {
		cout << n + 2 << endl;
	} else  {
		cout << n - 2 << endl;
	}
	
		
	return 0;
}