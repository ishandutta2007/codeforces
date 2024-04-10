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
	int T[n];
	rep(i, n) T[i]=-1;
	int akt=0;
	rep(i, n) if(T[i]==-1) {
		int p=akt-1;
		vector<int>V;
		++akt;
		cout << "? " << i+1 << endl;
		int x;
		cin >> x; --x;
		V.pb(x);
		while(true) {
			++akt;
			cout << "? " << i+1 << endl;
			int x;
			cin >> x; --x;
			if(x==V[0]) break;
			V.pb(x);
		}
		p=(p+V.size())%V.size();
		x=i;
		rep(j, V.size()) {
			T[x]=V[(j-p+V.size())%V.size()];
			x=V[(j-p+V.size())%V.size()];
		}
	}
	cout << "! ";
	rep(i, n) cout << T[i]+1 << " ";
	cout << endl;
}
int main() {
	int _;
	cin >> _;
	while(_--) solve();
}