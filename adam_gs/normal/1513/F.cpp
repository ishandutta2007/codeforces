#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") 
#pragma GCC option("arch=native","tune=native","no-zero-upper") 
#pragma GCC target("avx2","popcnt","rdrnd","bmi2")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=2e5+7;
ll a[LIM], b[LIM], odw[LIM];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	vector<pair<ll,ll>>p1, p2;
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> b[i];
	ll ans=0;
	rep(i, n) {
		ans+=abs(a[i]-b[i]);
		if(a[i]<=b[i]) {
			p1.pb({a[i], i});
			p1.pb({b[i], i});
		} else {
			p2.pb({b[i], i});
			p2.pb({a[i], i});
		}
	}
	sort(all(p1));
	sort(all(p2));
	int l1=0, l2=0;
	priority_queue<pair<ll,ll>>q1, q2;
	ll przeciecie=0;
	while(l1<p1.size() || l2<p2.size()) {
		ll akt=0;
		if(l1==p1.size()) {
			akt=p2[l2].st;
			if(!odw[p2[l2].nd]) {
				q2.push({-p2[l2].st, p2[l2].nd});
			}
			odw[p2[l2].nd]^=1;
			++l2;
		} else if(l2==p2.size()) {
			akt=p1[l1].st;
			if(!odw[p1[l1].nd]) {
				q1.push({-p1[l1].st, p1[l1].nd});
			}
			odw[p1[l1].nd]^=1;
			++l1;
		} else {
			if(p1[l1].st<=p2[l2].st) {
				akt=p1[l1].st;
				if(!odw[p1[l1].nd]) {
					q1.push({-p1[l1].st, p1[l1].nd});
				}
				odw[p1[l1].nd]^=1;
				++l1;
			} else {
				akt=p2[l2].st;
				if(!odw[p2[l2].nd]) {
					q2.push({-p2[l2].st, p2[l2].nd});
				}
				odw[p2[l2].nd]^=1;
				++l2;
			}
		}
		if(!q1.empty() && !q2.empty()) {
			przeciecie=max(przeciecie, akt-max(-q1.top().st, -q2.top().st));
		}
		while(!q1.empty() && odw[q1.top().nd]==0) q1.pop();
		while(!q2.empty() && odw[q2.top().nd]==0) q2.pop();
	}
	ans-=2*przeciecie;
	cout << ans << '\n';
}