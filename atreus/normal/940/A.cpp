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
const int mod = 1e9 + 7, maxn = 500 + 100;
int a[maxn], lit[maxn], big[maxn];

int main(){
	int n, d;
	cin >> n >> d;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort (a + 1, a + n + 1);
	if (n == 1)
		return cout << 0 << endl, 0;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			if (a[i] < a[j])
				big[i] ++;
			if (a[i] > a[j])
				lit[i] ++;
		}
	}
	int ans = 1000000;
	for (int i = 1; i <= n; i++){
		for (int j = i; j <= n; j++){
			if (a[j] - a[i] <= d)
				ans = min (ans, lit[i] + big[j]);
		}
	}
	cout << ans << endl;
}