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
const int LIM=2e5+7;
int F[LIM];
vector<int>kolumny[LIM];
int fnd(int x) {
	if(F[x]==x) return x;
	return F[x]=fnd(F[x]);
}
bool uni(int a, int b) {
	if(fnd(a)==fnd(b)) return false;
	F[fnd(b)]=fnd(a);
	return true;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m, q;
	cin >> n >> m >> q;
	rep(i, n) F[i]=i;
	rep(i, q) {
		int a, b;
		cin >> a >> b; --a; --b;
		kolumny[b].pb(a);
	}
	int ans=n-1;
	rep(i, m) {
		if(kolumny[i].size()==0) {
			++ans;
			continue;
		}
		rep(j, kolumny[i].size()-1) {
			if(uni(kolumny[i][j], kolumny[i][j+1])) --ans;
		}
	}
	cout << ans << '\n';
}