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
const int INF = 1e9 + 7, maxn = 1e5 + 50;

int main(){
	ios_base::sync_with_stdio(false);
	int n, ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i++){
		int k;
		cin >> k;
		ans += abs (k);
	}
	cout << ans << endl;
}