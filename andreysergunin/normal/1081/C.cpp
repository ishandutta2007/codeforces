#include <iostream>
#include <stdio.h>
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
#include <cstring>
#include <bitset>
#include <functional>
#include <tuple>
#include <complex>
#include <chrono>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef unsigned int uint;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int P = 998244353;

void add(int &a, int b) {
	a += b;
	if (a >= P) {
		a -= P;
	}
}

void mul(int &a, int b) {
	ll c = (ll)a * b;
	c %= P;
	a = c;
}

const int MAXN = 2222;

int dp[MAXN][MAXN];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // ifstream cin("input.txt");


   	int n, m, k;
   	cin >> n >> m >> k;

   	dp[1][0] = m;
   	for (int i = 1; i < n; ++i) {
   		for (int j = 0; j <= i; ++j) {
   			int cur = dp[i][j];
   			add(dp[i + 1][j + 1], dp[i][j]);
   			mul(cur, m - 1);
   			add(dp[i + 1][j], cur);
   		}
   	}	

   	cout << dp[n][n - 1 - k] << endl;


}