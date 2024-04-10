#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int t;
	cin >> t;
	while(t--) {
		int n, mn=1e9;
		cin >> n;
		vi a(n);
		for(int i=0; i<n; i++) {
			cin >> a[i];
			mn=min(mn, a[i]);
		}
		vi b=a;
		sort(all(b));
		bool sorted=true;
		for(int i=0; i<n; i++) {
			sorted = sorted && (a[i] % mn>0 ? a[i]==b[i] : true);
		}
		if(sorted) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}

	return 0;
}