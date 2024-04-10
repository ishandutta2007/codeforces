#pragma GCC option("arch=native","tune=native","no-zero-upper") 
#pragma GCC target("avx2","popcnt","rdrnd","bmi2")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=107;
int T[107];
void solve() {
	int n;
	cin >> n;
	T[0]=2137;
	int akt=n;
	for(int i=n; i; --i) {
		if(T[i]) continue;
		vector<int>V;
		for(int j=1; j<n; ++j) {
			cout << "? ";
			for(int l=1; l<=n; ++l) {
				if(l!=i) cout << 1 << " ";
				else cout << j+1 << " ";
			}
			cout << endl;
			int x;
			cin >> x;
			if(T[x] || x==i) break;
			V.pb(x);
		}
		for(int j=V.size()-1; j>=0; --j) {
			T[V[j]]=akt;
			--akt;
		}
		T[i]=akt; --akt;
	}
	cout << "! ";
	rep(i, n) cout << T[i+1] << " ";
	cout << endl;
}
int main() {
	int _=1;
	//cin >> _;
	while(_--) solve();
}