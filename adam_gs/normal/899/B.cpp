#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
int rok[]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
vector<int>T, V;
bool sprawdz(int x) {
	rep(i, V.size()) {
		if(i+x==T.size()) return false;
		if(V[i]!=T[x+i]) return false;
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	rep(i, 6) {
		rep(j, 12) T.pb(rok[j]);
	}
	T[37]=29;
	int n;
	cin >> n;
	while(n--) {
		int a;
		cin >> a;
		V.pb(a);
	}
	rep(i, T.size()) if(sprawdz(i)) {
		cout << "Yes\n";
		return 0;
	}
	cout << "No\n";
}