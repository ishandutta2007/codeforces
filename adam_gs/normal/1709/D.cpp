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
int tr[4*LIM], N=1;
int cnt(int l, int r) {
	l+=N; r+=N;
	int ans=max(tr[l], tr[r]);
	while(l/2!=r/2) {
		if(l%2==0) ans=max(ans, tr[l+1]);
		if(r%2==1) ans=max(ans, tr[r-1]);
		l/=2; r/=2;
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m;
	cin >> n >> m;
	while(N<m) N*=2;
	rep(i, m) cin >> tr[N+i];
	for(int i=N-1; i; --i) tr[i]=max(tr[2*i], tr[2*i+1]);
	int q;
	cin >> q;
	while(q--) {
		int x1, y1, x2, y2, k;
		cin >> x1 >> y1 >> x2 >> y2 >> k;
		--y1; --y2;
		if(abs(x1-x2)%k!=0 || abs(y1-y2)%k!=0) {
			cout << "NO\n";
			continue;
		}
		if(y1>y2) swap(y1, y2);
		int z=n-x1;
		z/=k;
		int p=x1+z*k;
		cout << (cnt(y1, y2)>=p?"NO":"YES") << '\n';
	}
}