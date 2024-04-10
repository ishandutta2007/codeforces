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
const int inf = 1e9 + 7, maxn = 3e5 + 500;
ll mark[maxn], dp[maxn], par[maxn], n;
vector <pair <pair <int, int>, int> > v[maxn];
vector <int> ans;

int main(){ // 0 --> red , 1 --> blue
	ios_base::sync_with_stdio(false);
	int a, b;
	cin >> a >> b;
	if (b == 0)
		return cout << "No" << endl, 0;
	if (b == 1 and a > 0)
		return cout << "No" << endl, 0;
	int k = b - 1;
	if (a < k)
		return cout << "No" << endl, 0;
	a -= k;
	if (a % 2 == 0)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}