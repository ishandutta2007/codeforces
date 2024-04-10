#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=2e5+7;
ll T[LIM];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	ll ans=0, ile=0;
	rep(i, n) {
		cin >> T[i];
		ile+=1-T[i];
	}
	rep(i, n) {
		if(T[i]) ans+=ile;
		else --ile;
	}
	cout << ans << '\n';
}