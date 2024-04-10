#include <cstring>
#include <algorithm>
#include <map>
#include <stack>
#include <cassert>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <queue>
#include <vector>
#include <iostream>
#include <set>
#define MP make_pair
#define F first
#define PB push_back
#define S second
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 100;
const int  mod = 1e9 + 7;
const ll inf = (1ll << 62);
int a[maxn];

int main(){
	ios::sync_with_stdio(false);
	int n, k, l, cnt = 0;
	cin >> n >> k >> l;
	int m = n * k;
	for (int i = 1; i <= m; i++)
		cin >> a[i];
	sort (a + 1, a + m + 1);
	for (int i = 1; i <= m; i++){
		if (a[i] - a[1] <= l)
			cnt ++;
		else
			break;
	}
	if (cnt < n)
		return cout << 0 << endl, 0;
	ll sum = 0, last = 1 - k, cur = n;
	for (int i = 1; i <= cnt; i++){
		if (i - last == k){
			last = i;
			sum += a[i];
			cur --;
		}
		else if (cnt - i + 1 == cur){
			cur --;
			last = i;
			sum += a[i];
		}
	}
	cout << sum << endl;
}