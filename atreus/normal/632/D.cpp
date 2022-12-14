#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;
const int maxn = 1e6 + 10;
const int mod = 1e9;

int a[maxn], cnt[maxn], sz[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		if (a[i] <= m)
			cnt[a[i]] ++;
	}
	int mxm = 0, Q = 1;
	for (int i = 1; i <= m; i++){
		for (int j = i; j <= m; j += i){
			sz[j] += cnt[i];
		}
		if (sz[i] > mxm){
			mxm = sz[i];
			Q = i;
		}
	}
	cout << Q << " " << mxm << endl;
	for (int i = 1; i <= n; i++){
		if (Q % a[i] == 0)
			cout << i << " ";
	}
	cout << endl;
}