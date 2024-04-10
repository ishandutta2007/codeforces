#include <bits/stdc++.h>
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
#define REP(i,a,b) for(int i = (int)a; i < (int)b; ++i)
#define PER(i,a,b) for(int i = (int)b-1; i >= (int)a; --i)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
const ll MOD = 1e9+7;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n, q, in;
	bool ma = true;
	cin >> n >> q;
	vector<pair<int, int>> a(n);
	vi inp(n), c(n,0);
	FOR(i,n) { cin >> inp[i]; if (inp[i]==q) ma = false; }
	FOR(i,n) {
		if (inp[i]==0 && ma) { inp[i] = q; ma = false; }
		else if (inp[i]==0 && i>0) { inp[i] = inp[i-1]; }
	}
	FOR(i,n-1) if (inp[n-i-2]==0) inp[n-i-2]=inp[n-i-1];
	ma = false;
	FOR(i,n) if (inp[i]==q) ma = true;
	if (!ma) {cout << "NO"<<endl; return 0;}
	FOR(i,n) { a[i].first = inp[i]; a[i].second = i; }
	sort(all(a), greater<pair<int, int>>());
	FOR(i,n-1) {
		if(c[a[i].second]==0) c[a[i].second] = a[i].second+1;
		if (a[i].first == a[i+1].first) {
			in = a[i+1].second + 1;
			while (in < a[i].second) {
				if (c[in] == 0) {cout << "NO" << endl; return 0;}
				in = c[in];
			}
			c[a[i+1].second] = c[a[i].second];
		}
	}
	cout << "YES" << endl;
	FOR(i,n) cout << inp[i] << " ";
	cout << endl;
	return 0;
}