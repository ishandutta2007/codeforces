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
	int n, m;
	cin >> n >> m;
	if(m%n) {
		cout << -1 << '\n';
		return 0;
	}
	m/=n;
	ll ans=0;
	while(m%2==0) {
		m/=2;
		++ans;
	}
	while(m%3==0) {
		m/=3;
		++ans;
	}
	cout << (m>1?-1:ans) << '\n';
}