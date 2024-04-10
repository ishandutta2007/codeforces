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
	int t;
	cin >> t;
	while(t--) {
		ll A, B, n;
		cin >> A >> B >> n;
		ll a[n], b[n];
		rep(i, n) cin >> a[i];
		rep(i, n) cin >> b[i];
		pair<ll,int>T[n];
		rep(i, n) {
			T[i]={((b[i]+A-1)/A)*a[i], i};
		}
		sort(T, T+n);
		rep(i, n) B-=T[i].st;
		bool ans=false;
		rep(i, n) {
			if(B+a[T[i].nd]>0) {
				ans=true;
				break;
			}
		}
		cout << (ans?"YES":"NO") << '\n';
	}
}