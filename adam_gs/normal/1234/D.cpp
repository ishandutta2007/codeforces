#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
#define lg(a) (31-__builtin_clz(a))
const int LIM=1e5+7;
int tr[4*LIM], N=1;
void upd(int v, int x) {
	v+=N;
	tr[v]=x;
	v/=2;
	while(v) {
		tr[v]=tr[2*v]|tr[2*v+1];
		v/=2;
	}
}
int cnt(int l, int r) {
	l+=N; r+=N;
	int ans=tr[l]|tr[r];
	while(l/2!=r/2) {
		if(l%2==0) ans|=tr[l+1];
		if(r%2==1) ans|=tr[r-1];
		l/=2; r/=2;
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	string x;
	cin >> x;
	int n=x.size(), q;
	while(N<n) N*=2;
	rep(i, n) tr[N+i]=1<<(x[i]-'a');
	for(int i=N-1; i>=0; --i) tr[i]=tr[2*i]|tr[2*i+1];
	cin >> q;
	while(q--) {
		int x;
		cin >> x;
		if(x==1) {
			int a;
			char b;
			cin >> a >> b; --a;
			upd(a, 1<<(b-'a'));
		} else {
			int a, b;
			cin >> a >> b; --a; --b;
			cout << __builtin_popcount(cnt(a, b)) << '\n';
		}
	}
}