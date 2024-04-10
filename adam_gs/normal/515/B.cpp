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
int T[LIM];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m;
	cin >> n >> m;
	int k=__gcd(n, m);
	rep(j, 2) {
		int x;
		cin >> x;
		rep(i, x) {
			int a;
			cin >> a;
			T[a%k]=1;
		}
	}
	bool ok=true;
	rep(i, k) if(!T[i]) ok=false;
	cout << (ok?"Yes":"No") << '\n';
}