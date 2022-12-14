#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef complex<long double> point;

const int maxn = 2e5 + 10;
const int inf = 3e5;

ll t[maxn], x[maxn];
ll a[maxn], p[maxn];

string solve(int q, int n){
	t[q] = 0, x[q] = 0;
	q ++;
	for (int i = 0; i < q; i++)
		a[i] = t[i]/n, p[i] = i;
	sort(p, p + q, [n](int a, int b){
		return t[a] % n < t[b] % n;
	});
	ll lef = -1, rig = n;
	for (int ptr = 1; ptr < q; ptr++){
		int i = p[ptr-1], j = p[ptr];
		ll lo = x[i] - x[j], hi = t[j]%n - t[i]%n + x[i] - x[j];
		ll diff = a[i] - a[j];
		if (a[i] == a[j])
			continue;
		if (diff < 0){
			diff *= -1;
			swap(lo, hi);
			lo *= -1, hi *= -1;
		}
		lo = ceil(1. * lo / diff);
		hi = hi / diff;
		lef = max(lef, lo);
		rig = min(rig, hi);
	}
	int i = p[q-1];
	ll lo = x[i], hi = n - (t[i]%n) + x[i];
	lo = ceil(1.*lo/(t[i]/n+1)), hi /= (t[i]/n+1);
	lef = max(lef, lo);
	rig = min(rig, hi);
	if (lef > rig){
		cout << "NO\n";
		exit(0);
	}
	string ret;
	int now = 0;
	for (int i = 0; i < q; i++){
		ll sum = x[p[i]] - lef * (t[p[i]]/n);
		while ((int)ret.size() < t[p[i]]%n){
			if (now < sum)
				ret += 'R', now ++;
			else
				ret += 'L';
		}
	}
	while ((int)ret.size() < n){
		if (now < lef)
			ret += 'R', now ++;
		else
			ret += 'L';
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	int q, n;
	cin >> q >> n;
	vector<ll> X(q), Y(q);
	for (int i = 0; i < q; i++){
		cin >> t[i] >> X[i] >> Y[i];
		if ((t[i] & 1) != ((X[i]+Y[i]) & 1))
			return cout << "NO\n", 0;
	}	
	for (int i = 0; i < q; i++)
		x[i] = (X[i] + Y[i] + t[i]) / 2;
	string S, T;
	S = solve(q, n);
	for (int i = 0; i < q; i++)
		x[i] = (X[i] - Y[i] + t[i]) / 2;
	T = solve(q, n);
	for (int i = 0; i < n; i++){
		if (S[i] == 'R' and T[i] == 'R')
			cout << 'R';
		if (S[i] == 'R' and T[i] == 'L')
			cout << 'U';
		if (S[i] == 'L' and T[i] == 'L')
			cout << 'L';
		if (S[i] == 'L' and T[i] == 'R')
			cout << 'D';
	}
	cout << '\n';
}