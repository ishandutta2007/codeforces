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
ll T[LIM], n;
ll f(ll x) {
	ll ans=0;
	rep(i, n) ans+=min(T[i], x);
	return ans;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll k, sum=0;
	cin >> n >> k;
	rep(i, n) {
		cin >> T[i];
		sum+=T[i];
	}
	if(sum<k) {
		cout << -1 << '\n';
		return 0;
	}
	ll po=0, ko=1000000000;
	while(po<ko) {
		ll sr=(po+ko+1)/2;
		if(f(sr)>k) ko=sr-1; else po=sr;
	}
	k-=f(po);
	queue<ll>q;
	rep(i, n) if(T[i]>po) q.push(i);
	while(k--) {
		if(T[q.front()]>po+1) q.push(q.front()); 
		q.pop();
	}
	while(!q.empty()) {
		cout << q.front()+1 << " ";
		q.pop();
	}
	cout << '\n';
}