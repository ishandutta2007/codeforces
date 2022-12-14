#include <bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
const ll maxn = 3e5 + 10;
int a[maxn], cnt[maxn];
pii b[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		cnt[a[i]] ++;
		if (cnt[a[i]] == 1)
			k --;
	}
	for (int i = 1; i <= n; i++){
		cin >> b[i].F;
		b[i].S = i;
	}
	sort (b + 1, b + n + 1);
	ll sum = 0;
	for (int i = 1; k > 0; i++){
		int idx = b[i].S;
		if (cnt[a[idx]] > 1) {
			k --;
			sum += b[i].F;
			cnt[a[idx]] --;
		}
	}
	cout << sum << endl;
}