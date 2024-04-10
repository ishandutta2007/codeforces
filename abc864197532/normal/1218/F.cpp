#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);++i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 

int main () {
	lli n,k,a;
	cin >> n >> k;
	lli x[n],v[n];
	fop (i,0,n) cin >> x[i];
	cin >> a;
	fop (i,0,n) cin >> v[i];
	lli now=0;
	lli ans=0;
	priority_queue <lli, vector<lli>, greater<lli> > nums;
	fop (i,0,n) {
		nums.push(v[i]);
		lli aa=(max(0ll,x[i]-k)+a-1)/a;
		if (aa>i+1) {
			cout << -1 << endl;
			return 0;
		}
		if (aa>now) {
			fop (j,0,aa-now) {
				ans+=nums.top();
				nums.pop();
			}
			now=aa;
		}
	}
	cout << ans << endl;
}