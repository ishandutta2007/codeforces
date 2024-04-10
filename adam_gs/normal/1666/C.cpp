#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	pair<ll,ll>T[3];
	ll A[3], B[3];
	rep(i, 3) {
		cin >> A[i] >> B[i];
		T[i]={A[i], B[i]};
	}
	sort(A, A+3);
	sort(B, B+3);
	ll x=A[1], y=B[1];
	vector<pair<pair<ll,ll>,pair<ll,ll>>>V;
	rep(i, 3) {
		if(T[i].st!=x) V.pb({{min(T[i].st, x), T[i].nd}, {max(T[i].st, x), T[i].nd}});
		if(T[i].nd!=y) V.pb({{x, min(T[i].nd, y)}, {x, max(T[i].nd, y)}});
	}
	cout << V.size() << '\n';
	for(auto i : V) cout << i.st.st << " " << i.st.nd << " " << i.nd.st << " " << i.nd.nd << '\n';
}