// Dennis - Toney
#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ll Mod = 1000000007LL;
const int N = 1e6 + 10;
const ll Inf = 2242545357980376863LL;
const int Log = 61;

ll a[N], MX[N], MN[N], ans;
ll bt[N];
int cnt[Log];

void Solve(int l, int r){
	if(l + 1 == r) return ;

	int mid = (l + r) >> 1;
	Solve(l, mid); Solve(mid, r);
	// cerr << l << ' ' << r << '\n';
	int mn, mx, p;
	// [mx, mn] , [];
	mn = mid - 1, mx = mid - 1;
	p = mid;
	for(int i = mid - 1; i >= l; i--){
		if(a[i] <= a[mn]) mn = i;
		if(a[i] > a[mx]) mx = i;
		MX[i] = mx, MN[i] = mn;
		if(bt[mn] != bt[mx]) continue;
		while((p < r) && (a[mn] <= a[p]) && (a[p] < a[mx])) p ++;
		ans += p - mid;
	}
	// [] , [mn, mx];
	mn = mid, mx = mid;
	p = mid - 1;
	for(int i = mid; i < r; i++){
		if(a[i] < a[mn]) mn = i;
		if(a[i] >= a[mx]) mx = i;
		MX[i] = mx, MN[i] = mn;
		
		if(bt[mn] != bt[mx]) continue;
		while((p >= l) && (a[mn] < a[p]) && (a[p] <= a[mx])) p --;
		ans += (mid - 1) - p;
	}
	int pl, pr;
	// [mn], [mx]
	pl = mid, pr = mid;
	memset(cnt, 0, sizeof cnt);

	for(int i = mid - 1; i >= l; i--){
		mn = MN[i];
		mx = MX[i];
		while((pl < r) && (a[pl] < a[mx])) {
			if(pl < pr) cnt[ bt[MX[pl]] ] --;
			pl ++;
		}
		while((pr < r) && (a[pr] >= a[mn])){
			if(pl <= pr) cnt[ bt[MX[pr]] ] ++;
			pr ++;
		}
		if(pl < pr){
			ans += cnt[bt[mn]];
		}
	}
	// [mx], [mn]
	pl = mid, pr = mid;
	memset(cnt, 0, sizeof cnt);

	for(int i = mid - 1; i >= l; i--){
		mn = MN[i];
		mx = MX[i];
		while((pl < r) && (a[pl] >= a[mn])) {
			if(pl < pr) cnt[ bt[MN[pl]] ] --;
			pl ++;
		}
		while((pr < r) && (a[pr] < a[mx])){
			if(pl <= pr) cnt[ bt[MN[pr]] ] ++;
			pr ++;
		}
		if(pl < pr){
			ans += cnt[bt[mx]];
		}
	}
	return;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++){
		bt[i] = __builtin_popcountll(a[i]);
		// debug(bt[i]);
	}
	Solve(0, n);
	cout << ans + n << '\n';
	return 0;
}
/*
5
5 4 3 2 1

*/