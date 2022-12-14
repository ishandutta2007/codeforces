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
const int INF = 1e9 + 7, maxn = 1e5 + 200;
vector <int> v[maxn];
int dp[maxn], hei[maxn];

void dfs (int u, int h){
	hei[u] = h;
	for (auto w : v[u])
		dfs (w, h + 1);
}

int main(){
    ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++){
		int p;
		cin >> p;
		v[p].PB(i);
	}
	dfs (1, 0);
	for (int i = 1; i <= n; i++)
		dp[hei[i]] ^= 1;
	int ans = 0;
	for (int i = 0; i <= n; i++)
		ans += dp[i];
	cout << ans << endl;
}