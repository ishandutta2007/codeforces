#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
void solve() {
	int n;
	cin >> n;
	int T[n+1];
	rep(i, n) T[i+1]=1;
	for(int i=1; i<=n; ++i) {
		int a;
		cin >> a;
		if(a==0) T[i]=0;
		else if(a+i-T[i]*(i-1)<=n) T[a+i-T[i]*(i-1)]=0;
		cout << T[i] << " ";
	}
	cout << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	cin >> _;
	while(_--) solve();
}