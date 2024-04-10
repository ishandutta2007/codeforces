#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define all(a) a.begin(), a.end()
const int LIM=3e5+7, INF=1e9+7;
ll ma[4*LIM][2], mi[4*LIM][2], T[LIM], N;
void upd(int v) {
	v+=N;
	ma[v][1]=T[v-N];
	mi[v][1]=-T[v-N];
	v/=2;
	while(v) {
		ma[v][0]=max(ma[2*v][1]+mi[2*v+1][1], ma[2*v][0]+ma[2*v+1][0]);
		ma[v][0]=max(ma[v][0], max(ma[2*v][0], ma[2*v+1][0]));
		ma[v][1]=max(ma[2*v][1]+mi[2*v+1][0], ma[2*v][0]+ma[2*v+1][1]);
		ma[v][1]=max(ma[v][1], max(ma[2*v][1], ma[2*v+1][1]));
		mi[v][0]=max(mi[2*v][0]+mi[2*v+1][0], mi[2*v][1]+ma[2*v+1][1]);
		mi[v][0]=max(mi[v][0], max(mi[2*v][0], mi[2*v+1][0]));
		mi[v][1]=max(mi[2*v][0]+mi[2*v+1][1], mi[2*v][1]+ma[2*v+1][0]);
		mi[v][1]=max(mi[v][1], max(mi[2*v][1], mi[2*v+1][1]));
		v/=2;
	}
}
void solve() {
	int n, q;
	cin >> n >> q;
	N=1;
	while(N<n) N*=2;
	rep(i, n) cin >> T[i];
	rep(i, 2*N) ma[i][0]=ma[i][1]=mi[i][0]=mi[i][1]=0;
	rep(i, n) {
		ma[N+i][1]=T[i];
		mi[N+i][1]=-T[i];
	}
	for(int i=N-1; i; --i) {
		ma[i][0]=max(ma[2*i][1]+mi[2*i+1][1], ma[2*i][0]+ma[2*i+1][0]);
		ma[i][0]=max(ma[i][0], max(ma[2*i][0], ma[2*i+1][0]));
		ma[i][1]=max(ma[2*i][1]+mi[2*i+1][0], ma[2*i][0]+ma[2*i+1][1]);
		ma[i][1]=max(ma[i][1], max(ma[2*i][1], ma[2*i+1][1]));
		mi[i][0]=max(mi[2*i][0]+mi[2*i+1][0], mi[2*i][1]+ma[2*i+1][1]);
		mi[i][0]=max(mi[i][0], max(mi[2*i][0], mi[2*i+1][0]));
		mi[i][1]=max(mi[2*i][0]+mi[2*i+1][1], mi[2*i][1]+ma[2*i+1][0]);
		mi[i][1]=max(mi[i][1], max(mi[2*i][1], mi[2*i+1][1]));
	}
	cout << max(ma[1][0], ma[1][1]) << '\n';
	while(q--) {
		int a, b;
		cin >> a >> b; --a; --b;
		swap(T[a], T[b]);
		upd(a);
		upd(b);
		cout << max(ma[1][0], ma[1][1]) << '\n';
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	cin >> _;
	while(_--) solve();
}