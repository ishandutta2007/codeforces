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
ll A[LIM], B[LIM], T[LIM];
void solve() {
	int n, m;
	cin >> n >> m;
	rep(i, n) cin >> T[i];
	rep(i, n-1) {
		A[i]=max(T[i]-T[i+1], 0ll);
		B[i]=max(T[i+1]-T[i], 0ll);
		if(i) {
			A[i]+=A[i-1];
			B[i]+=B[i-1];
		}
	}
	while(m--) {
		int a, b;
		cin >> a >> b;
		a-=2; b-=2;
		if(a<b) {
			cout << A[b]-(a>=0?A[a]:0) << '\n';
		} else {
			cout << B[a]-(b>=0?B[b]:0) << '\n';
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	//cin >> _;
	while(_--) solve();
}