#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define all(a) a.begin(), a.end()
const ll LIM=3e6+7;
ll ile[LIM], ans[LIM];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll n;
	cin >> n;
	rep(i, n) {
		int a;
		cin >> a;
		++ile[a];
	}
	for(ll i=1; i<LIM; ++i) {
		if(i*i<LIM) ans[i*i]+=ile[i]*(ile[i]-1);
		for(ll j=i+1; j*i<LIM; ++j) ans[i*j]+=ile[i]*ile[j]*2;
	}
	for(ll i=1; i<LIM; ++i) ans[i]+=ans[i-1];
	int m;
	cin >> m;
	while(m--) {
		int a;
		cin >> a;
		cout << n*(n-1)-ans[a-1] << '\n';
	}
}