#include <iostream>
#include <deque>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <iomanip>
#include <queue>
#include <time.h>
#include <set>
#include <cstring>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <bitset>
#include <unordered_set>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define In insert
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7, maxn = 1e5 + 100;
ll dp[maxn], par[maxn], a[maxn];
multiset <int> s;

int main(){
	ll n, k, a, b;
	cin >> n >> k >> a >> b;
	ll cost = 0;
	while (n > 1){
		cost += (n % k) * a;
		n -= (n % k);
		ll p = n / k;
		if ((n - p) * a > b){
			n = p;
			cost += b;
		}
		else {
			cost += (n - 1) * a;
			n = 1;
		}
	}
	cout << cost << endl;
}