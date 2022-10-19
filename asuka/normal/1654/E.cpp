#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define ll long long
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
using namespace __gnu_pbds;
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")

const int N = 100015, B = 317;

int n, a[N];

gp_hash_table<ll, int> M;

int count(vector<ll>& vec) {
	sort(all(vec));
	int ans = 0;

	for (int l = 0, r; r = l, l < SZ(vec); l = r + 1) {
		while (r + 1 < SZ(vec) && vec[r + 1] == vec[l]) r++;

		ans = max(ans, r - l + 1);
	}

	return ans;
}

int main() {
#ifdef Asuka
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif

	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", &a[i]);

	int ans = 0;

	rep(k, -B, B) {
		M.clear();
		vector<ll> vec;
		rep(i, 1, n) {
			ll u = a[i] - (ll) k * i;
			vec.pb(u);
		}
		ans = max(ans, count(vec));
	}

	rep(i, 1, n) {
		M.clear();
		vector<ll> vec;
		rep(j, i + 1, min(i + B, n)) {
			if ((a[j] - a[i]) % (j - i) == 0) {
				vec.pb((a[j] - a[i]) / (j - i));
			}
		}
		ans = max(ans, count(vec) + 1);
	}

	printf("%d\n", n - ans);

	return 0;
}