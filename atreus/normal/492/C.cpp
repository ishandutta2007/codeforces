#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>

using namespace std;

#define MP make_pair
#define PB push_back
#define L first
#define R second

typedef pair<int, int> pie;
typedef long long ll;

const int maxn = 1e5 + 1000;
pair <ll, ll> p[maxn];

int main(){
	ll n, r, avg;
	cin >> n >> r >> avg;
	ll k = n * avg;
	for (int i = 0; i < n; i++){
		cin >> p[i].second >> p[i].first;
		k -= p[i].second;
	}
	if (k <= 0){
		cout << 0 << endl;
		return 0;
	}
	ll ans = 0;
	sort(p, p + n);
	for (int i = 0; i < n; i++){
		if (k >= r - p[i].second){
			k -= r - p[i].second;
			ans += (r - p[i].second) * p[i].first;
			if (k == 0)
				break;
			continue;
		}
		else {
			ans += k * p[i].first;
			k = 0;
			break;
		}
		if (k <= 0)
			break;
	}
	cout << ans << endl;
	return 0;
}