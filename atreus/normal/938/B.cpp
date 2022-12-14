#include <iostream>
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
const int inf = 1e9 + 7, maxn = 1e6;

int main(){ 
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int ans = 1;
	int mk = 5e5;
	for (int i = 0; i < n; i++){
		int k;
		cin >> k;
		ans = max(ans, min (k - 1, maxn - k));
	}
	cout << ans << endl;
}