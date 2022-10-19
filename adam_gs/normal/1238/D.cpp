#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define all(a) a.begin(), a.end()
const int LIM=3e5+7;
ll kiedy[2];
void solve() {
	ll n;
	string x;
	cin >> n >> x;
	ll ans=n*(n-1)/2;
	kiedy[0]=kiedy[1]=n;
	for(int i=n-1; i>=0; --i) {
		ans-=kiedy[x[i]-'A']-i-1;
		kiedy[x[i]-'A']=i;
	}
	kiedy[0]=kiedy[1]=-1;
	rep(i, n) {
		ans-=i-kiedy[x[i]-'A']-1;
		kiedy[x[i]-'A']=i;
	}
	rep(i, n-1) if(x[i]!=x[i+1]) ++ans;
	cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	//cin >> _;
	while(_--) solve();
}