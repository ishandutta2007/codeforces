#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
#define lg(a) (31-__builtin_clz(a))
const int LIM=2e5+7;
ll tr[4*LIM], N=1;
void upd(int l, int r, ll x) {
	if(l>r) return;
	l+=N; r+=N;
	tr[l]+=x;
	if(l!=r) tr[r]+=x;
	while(l/2!=r/2) {
		if(l%2==0) tr[l+1]+=x;
		if(r%2==1) tr[r-1]+=x;
		l/=2; r/=2;
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m, lst;
	cin >> n >> m >> lst; --lst;
	while(N<n) N*=2;
	rep(i, m-1) {
		int a;
		cin >> a; --a;
		if(a==lst) continue;
		upd(0, min(a, lst)-1, abs(a-lst));
		upd(max(a, lst)+1, n-1, abs(a-lst));
		upd(min(a, lst)+1, max(a, lst)-1, abs(a-lst)-1);
		if(a<lst) {
			upd(a, a, lst);
			upd(lst, lst, a+1); 
		} else {
			upd(lst, lst, a);
			upd(a, a, lst+1);
		}
		lst=a;
	}
	for(int i=1; i<N; ++i) {
		tr[2*i]+=tr[i];
		tr[2*i+1]+=tr[i];
	}
	rep(i, n) cout << tr[N+i] << " ";
}