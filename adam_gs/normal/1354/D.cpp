#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=1<<20;
int tr[2*LIM], N=1;
void upd(int v, int x) {
	v+=N;
	while(v) {
		tr[v]+=x;
		v/=2;
	}
}
int cnt(int v, int k) {
	if(v>=N) return v-N;
	if(tr[2*v]>=k) return cnt(2*v, k);
	return cnt(2*v+1, k-tr[2*v]);
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, q;
	cin >> n >> q;
	while(N<n) N*=2;
	rep(i, n) {
		int a;
		cin >> a; --a;
		upd(a, 1);
	}
	while(q--) {
		int a;
		cin >> a;
		if(a>0) upd(a-1, 1);
		else upd(cnt(1, -a), -1);
	}
	if(tr[1]==0) cout << 0 << '\n';
	else cout << cnt(1, 1)+1 << '\n';
}