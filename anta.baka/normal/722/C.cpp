#include <bits/stdc++.h>
#define sz(a) (int)(a).size()
#define all(a) (a).begin(),(a).end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
// head

vector<int> pr, sz;
vector<ll> sum;
ll lar = 0;

int fin(int p) {
	if(pr[p] == p)
		return p;
	return pr[p] = fin(pr[p]);
}

void uni(int a, int b) {
	a = fin(a);
	b = fin(b);
	if(a != b) {
		if(sz[a] < sz[b])
			swap(a,b);
		pr[b] = a;
		sz[a] += sz[b];
		sum[a] += sum[b];
		lar = max(lar, sum[a]);
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < n; i++)
		cin >> b[i];
	pr.resize(n);
	sz.resize(n);
	sum.resize(n);
	vector<ll> ans(n);
	vector<bool> is(n, false);
	for(int i = n-1; i >= 0; i--) {
		ans[i] = lar;
		int f = b[i]-1;
		pr[f] = f;
		sz[f] = 1;
		sum[f] = a[f];
		is[f] = true;
		lar = max(lar, sum[f]);
		if(f > 0 && is[f-1])
			uni(f-1,f);
		if(f<n-1 && is[f+1])
			uni(f,f+1);
	}
	for(int i = 0; i < n; i++)
		cout << ans[i] << '\n';
}