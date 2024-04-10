#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define lg(a) (31-__builtin_clz(a))
#define all(a) a.begin(), a.end()
ll pow(ll a,ll b,ll c){ll w=1;while(b){if(b&1)w=(w*a)%c;b/=2;a=(a*a)%c;}return w;}
void solve() {
	int n, t;
	cin >> n >> t >> t;
	int p=0, k=n-1;
	while(p<k) {
		int sr=(p+k)/2;
		cout << "? 1 " << sr+1 << endl;
		int x;
		cin >> x;
		x=sr+1-x;
		if(x<t) p=sr+1; else k=sr;
	}
	cout << "! " << p+1 << endl;
}
int main() {
	int t=1;
	while(t--) solve();
}