#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
#define lg(a) (31-__builtin_clz(a))
void solve() {
	int n;
	string a, b;
	cin >> n >> a >> b;
	int dasie[n];
	int zero=0, jeden=0;
	rep(i, n) {
		dasie[i]=0;
		if(a[i]=='0') ++zero; else ++jeden;
		if(jeden==zero) dasie[i]=1;
	}
	int p=0;
	for(int i=n-1; i>=0; --i) {
		if(((a[i]-'0')^p)!=b[i]-'0') {
			if(!dasie[i]) {
				cout << "NO\n";
				return;
			}
			p^=1;
		}
	}
	cout << "YES\n";
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
}