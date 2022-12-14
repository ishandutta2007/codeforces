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
const int maxn = 10000 + 100;
const int  mod = 1e9 + 7;
const ll inf = (1ll << 62);
int a[maxn];

int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n / 2; i++)
		cin >> a[i];
	sort (a + 1, a + (n / 2) + 1);
	int ans1 = 0, ans2 = 0, tmp = 1;
	for (int i = 1; i <= n / 2; i++){
		ans1 += abs (tmp - a[i]);
		tmp += 2;
	}
	tmp = 2;
	for (int i = 1; i <= n / 2; i++){
		ans2 += abs (tmp - a[i]);
		tmp += 2;
	}
	cout << min (ans1, ans2) << endl;
}