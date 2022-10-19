#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
const int LIM=1e5+7;
pair<ll,ll>T[LIM];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll n, d;
	cin >> n >> d;
	rep(i, n) cin >> T[i].st >> T[i].nd;
	sort(T, T+n);
	int p=0;
	ll sum=0, ans=0;
	rep(i, n) {
		sum+=T[i].nd;
		while(T[i].st-T[p].st>=d) {
			sum-=T[p].nd;
			++p;
		}
		ans=max(ans, sum);
	}
	cout << ans << '\n';
}