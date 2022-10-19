#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") 
#pragma GCC option("arch=native","tune=native","no-zero-upper") 
#pragma GCC target("avx2","popcnt","rdrnd","bmi2")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=1e5+7;
int F1[LIM], F2[LIM];
int fnd1(int x) {
	if(F1[x]==x) return x;
	return F1[x]=fnd1(F1[x]);
}
int fnd2(int x) {
	if(F2[x]==x) return x;
	return F2[x]=fnd2(F2[x]);
}
void uni1(int a, int b) {
	if(fnd1(a)==fnd1(b)) return;
	F1[fnd1(b)]=fnd1(a);
}
void uni2(int a, int b) {
	if(fnd2(a)==fnd2(b)) return;
	F2[fnd2(b)]=fnd2(a);
}
void solve() {
	int n, m1, m2;
	cin >> n >> m1 >> m2;
	rep(i, n) F1[i]=F2[i]=i;
	rep(i, m1) {
		int a, b;
		cin >> a >> b; --a; --b;
		uni1(a, b);
	}
	rep(i, m2) {
		int a, b;
		cin >> a >> b; --a; --b;
		uni2(a, b);
	}
	vector<pair<int,int>>ans;
	rep(i, n) rep(j, n) {
		if(fnd1(i)!=fnd1(j) && fnd2(i)!=fnd2(j)) {
			uni1(i, j);
			uni2(i, j);
			ans.pb({i, j});
		}
	}
	cout << ans.size() << '\n';
	for(auto i : ans) cout << i.st+1 << " " << i.nd+1 << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	//cin >> _;
	while(_--) solve();
}