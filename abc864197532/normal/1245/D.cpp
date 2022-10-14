#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m)-((m)>(n));i!=(n)-((m)>(n));i+=2*((m)<(n))-1)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int>
 
int dij[2001];
 
int find (int a) {
    if (a == dij[a]) return a;
    dij[a] = find(dij[a]);
    return dij[a];
}
 
 
 
int main () {
	int n;
	cin >> n;
	vector <pii> nums;
	fop (i,0,n) {
		int a,b;
		cin >> a >> b;
		nums.eb(a,b);
	}
	int v[n], x[n];
	vector <tuple<lli, int, int> > N;
	fop (i,0,n) {
		int a;
		cin >> a;
		N.eb(1ll * a, -1, i);
	}
	fop (i,0,n) cin >> x[i];
	fop (i,0,n) {
		fop (j,0,n) {
			if (i == j) continue;
			lli a = abs(nums[i].first - nums[j].first) + abs(nums[i].second - nums[j].second);
			a *= (x[i] + x[j]);
			N.eb(a, i, j);
		}
	}
	sort(N.begin(), N.end());
	fop (i,0,n+1) dij[i] = i;
	lli ans = 0;
	vector <int> power;
	vector <pii> road;
	fop (i,0,N.size()) {
		lli a;
		int b,c;
		tie(a,b,c) = N[i];
		int aa = find(b + 1), bb = find(c + 1);
		if (aa == bb) continue;
		dij[aa] = bb;
		ans += a;
		if (b == -1 or c == -1) power.pb(b + c + 1);
		else road.eb(b, c);
	}
	cout << ans << endl;
	cout << power.size() << endl;
	fop (i,0,power.size()) cout << power[i] + 1 << " \n" [i == power.size() - 1];
	cout << road.size() << endl; 
	fop (i,0,road.size()) cout << road[i].first + 1 << ' ' << road[i].second + 1 << endl;
}