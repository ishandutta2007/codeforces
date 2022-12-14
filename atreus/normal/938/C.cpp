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
const int inf = 1e9 + 7, maxn = 2e5 + 500;
set <pair <ll, int> > s;
vector <pair <int, ll> > v[maxn];
ll n, a[maxn], dp[maxn];

int main(){ 
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--){
		ll x;
		cin >> x;
		bool ans = 0;
		for (int i = 1; i <= 1e5; i++){
			if (i * i < x)
				continue;
			int l = 1, r = i + 1;
			ll q = (1ll * i * i) - x;
			while (r - l > 1){
				int mid = (r + l) / 2;
				ll k = (i / mid) * (i / mid);
				if (k < q)
					r = mid;
				else
					l = mid;
			}
			ll k = (i / l) * (i / l);
			if (k == q){
				cout << i << " " << l << endl;
				ans = 1;
				break;
			}
		}
		if (!ans)
			cout << -1 << endl;
	}
}