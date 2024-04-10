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
		int x1, y1, z1, x2, y2, z2;
		cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
		int c=min(z1, y2), ans=c;
		z1-=ans;
		y2-=ans;
		c=min(y1, x2);
		y1-=c;
		x2-=c;
		c=min(y1, y2);
		y1-=c;
		y2-=c;
		c=min(z2, x1);
		z2-=c;
		x1-=c;
		c=min(z2, z1);
		z2-=c;
		z1-=c;
		c=min(y1, z2);
		ans-=c;
		cout << 2*ans << "\n";
	}

	return 0;
}