#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define lg(a) (31-__builtin_clz(a))
const int LIM=1e5+7, MOD=1e9+7;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
		int n, q, k;	
		cin >> n >> q >> k;
		ll T[n], pre[n];
		rep(i, n) cin >> T[i];
		ll na_ile[n];
		rep(i, n) {
			if(i==0) {
				if(n==1) {
					na_ile[0]=k-1;
				} else {
					na_ile[0]=T[1]-2;
				}
			} else if(i==n-1) {
				na_ile[i]=k-T[i-1]-1;
			} else {
				na_ile[i]=T[i+1]-T[i-1]-2;
			}
		}
		pre[0]=na_ile[0];
		rep(i, n-1) pre[i+1]=pre[i]+na_ile[i+1];
		rep(i, q) {
			int l, r;
			cin >> l >> r; --l; --r;
			if(l==r) {
				cout << k-1;
			} else if(r-l==1) {
				cout << k-T[r-1]-1+T[l+1]-2;
			} else {
				cout << k-T[r-1]-1+T[l+1]-2+pre[r-1]-pre[l];
			}
			cout << '\n';
		}
}