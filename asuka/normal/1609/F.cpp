#include<bits/stdc++.h>
#define ll long long
#define N 1000015
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
#define VI vector<int>
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
int n, c[N], res;
ll a[N];
vector<int> Max, Min;
vector<array<int, 3>> pMax[60], pMin[60]; // {l, r, val}
int calc(const vector<array<int, 3>> &v, int x) {
	auto it = upper_bound(all(v), (array<int, 3>) {x, inf, inf});
	if(it == v.begin()) return 0;
	it = prev(it);
	return (min((*it)[1], x) - (*it)[0] + 1) + (it == v.begin() ? 0 : (*prev(it))[2]);
}
int Calc(const vector<array<int, 3>> &v, int l, int r) {
	return calc(v, r) - calc(v, l - 1);
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &n);
	rep(i, 1, n) scanf("%lld", &a[i]), c[i] = __builtin_popcountll(a[i]);
	ll ans = 0;
	rep(i, 1, n) {
		while(SZ(Max) > 0 && a[Max.back()] < a[i]) {
			res -= Calc(pMin[c[Max.back()]], SZ(Max) == 1 ? 1 : (Max[SZ(Max) - 2] + 1), Max.back());
			pMax[c[Max.back()]].pop_back();
			Max.pop_back();
		}
		int l = SZ(Max) == 0 ? 1 : (Max.back() + 1);
		res += Calc(pMin[c[i]], l, i);
		pMax[c[i]].pb({l, i, (i - l + 1) + (SZ(pMax[c[i]]) == 0 ? 0 : pMax[c[i]].back()[2])});
		Max.pb(i);
		while(SZ(Min) > 0 && a[Min.back()] > a[i]) {
			res -= Calc(pMax[c[Min.back()]], SZ(Min) == 1 ? 1 : (Min[SZ(Min) - 2] + 1), Min.back());
			pMin[c[Min.back()]].pop_back();
			Min.pop_back();
		}
		l = SZ(Min) == 0 ? 1 : (Min.back() + 1);
		res += Calc(pMax[c[i]], l, i);
		pMin[c[i]].pb({l, i, (i - l + 1) + (SZ(pMin[c[i]]) == 0 ? 0 : pMin[c[i]].back()[2])});
		Min.pb(i);
		ans += res;
	}
	printf("%lld\n", ans);
	return 0;
}
/*
6
1 1 4 5 1 4
*/