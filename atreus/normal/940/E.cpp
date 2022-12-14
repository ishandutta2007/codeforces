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
	int n, c;
	cin >> n >> c;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		par[i] = par[i - 1] + a[i];
	
	for (int i = 1; i <= n; i++){
		dp[i] = dp[i - 1] + a[i];
		s.insert (a[i]);
		if (i < c){
			continue;
		}
		if (i == c){
			dp[i] -= *s.begin();
			continue;
		}
		s.erase(s.find(a[i - c]));
		dp[i] = min (dp[i], dp[i - c] + par[i] - par[i - c] - *s.begin());
	}
	cout << dp[n] << endl;
}