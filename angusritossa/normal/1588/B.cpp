#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
typedef long long ll;
#define int long long
ll i, j, k, overall, N;
ll query(int l, int r) {
	printf("? %lld %lld\n", l, r);
	fflush(stdout);
	ll ans;
	scanf("%lld", &ans);
	return ans;
}
ll SQRT(ll x) {
	return sqrt(x)+0.5;
}
ll getN(ll x) {
	return (1+SQRT(1+8*x))/2;
}
void bsearch2(ll l, ll r, ll otherr, ll am) {
	D("2 %lld %lld %lld %lld\n", l, r, otherr, am);
	// find j
	if (l == r) {
		j = l+1;
		i = j - getN(query(1, j-1));
		return;
	}
	int mid = (l+r)/2;
	ll q2 = query(mid+1, otherr);
	ll m = otherr-mid;
	if (q2 == m*(m-1)/2) {
		bsearch2(l, mid, otherr, am);
	} else {
		bsearch2(mid+1, r, otherr, am);
	}
}
void bsearch3(ll l, ll r, ll otherl, ll am) {
	D("3 %lld %lld %lld %lld\n", l, r, otherl, am);

	if (l == r) {
		j = l+1;
		k = j + getN(query(j+1, N));
		return;
	}

	int mid = (l+r+1)/2;
	ll q2 = query(otherl, mid);
	ll m = mid-otherl+1;
	if (q2 == m*(m-1)/2) {
		bsearch3(mid, r, otherl, am);
	} else {
		bsearch3(l, mid-1, otherl, am);
	}
}
void bsearch1(ll l, ll r, ll mid = -1) {
	D("1 %lld %lld %lld\n", l, r, mid);
	if (mid == -1) mid = (l+r)/2;
	ll q = query(1, mid);
	if (q == 0) {
		bsearch1(mid+1, r);
	} else if (q == overall) {
		bsearch1(l, mid);
	} else {
		ll q2 = overall-q;
		if (q && q2) {
			q2 = query(mid+1, N);
		}
		ll n = getN(q);
		ll m = getN(q2);
		D("(%lld %lld) (%lld %lld)\n", n, q, m, q2);
		bool leftGood = (n*(n-1))/2 == q;
		bool rightGood = (m*(m-1))/2 == q2;
		if (leftGood && rightGood) {
			if (query(mid+1, mid+m) != q2) {
				D("here1\n");
				rightGood = false;
			}
			if (query(mid-n+1, mid) != q) {
				D("here2\n");
				leftGood = false;
			}
			if (leftGood && rightGood) {
				i = mid-n+1;
				j = mid+1;
				k = mid+m;
				D("here\n");
				return;
			}
		}
		assert(leftGood || rightGood);
		if (leftGood) {
			i = mid-n+1;
			bsearch3(mid+1, r, mid+1, q2);
		} else {
			k = mid+m;
			bsearch2(l, mid, mid, q);
		}
	}
}
#undef int
int main() {
	#define int long long
	int t;
	scanf("%lld", &t);
	for (int _ = 0; _ < t; _++) {
		scanf("%lld", &N);
		overall = query(1, N);
		bsearch1(1, N);
		printf("! %lld %lld %lld\n", i, j, k);
		fflush(stdout);
	}
}