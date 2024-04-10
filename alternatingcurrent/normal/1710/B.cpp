#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
const ll Mod = 998244353;

int T;
ll n, m;
struct rain{
	ll x, p;
	int ind;
} a[200200];
ll f[200200];
ll lmtl[200200], lmtr[200200];
bool ans[200200];

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> n >> m;
		rep(i, n)
			cin >> a[i].x >> a[i].p, a[i].ind = i;
		sort(a, a + n, [&](rain u, rain v) -> bool{ return u.x < v.x; });
		ll sum = 0, d = 0;
		priority_queue<ll, vector<ll>, greater<ll> > pq1;
		rep(i, n){
			if(i){
				sum -= 1ll * d * (a[i].x - a[i - 1].x);
				while(!pq1.empty() && pq1.top() < a[i].x){
					sum += (a[i].x - pq1.top());
					d--;
//					cout << i << " pop " << pq1.top() << endl;
					pq1.pop();
				}
			}
			sum += a[i].p;
			d++;
//			cout << a[i].x + a[i].p << " to " << sum << endl;
			pq1.push(a[i].x + a[i].p);
			f[i] = sum;
		}
//		rep(i, n)
//			cout << f[i] << " ";
//		cout << endl;
//		cout << "-^^^^^^-" << endl;
		priority_queue<ll> pq2;
		sum = d = 0;
		for(int i = n - 1; i >= 0; i--){
			if(i < n - 1){
				sum -= 1ll * d * (a[i + 1].x - a[i].x);
				while(!pq2.empty() && pq2.top() > a[i].x){
					sum += (pq2.top() - a[i].x);
					d--;
					pq2.pop();
				}
			}
//			cout << a[i].x - a[i].p << " to " << sum << endl;
			f[i] += sum;
			sum += a[i].p;
			d++;
			pq2.push(a[i].x - a[i].p);
		}
//		rep(i, n)
//			cout << f[i] << " ";
//		cout << endl;
//		cout << "-^^^^^^-" << endl;
		rep(i, n)
			lmtl[i] = 0xc0c0c0c0c0c0c0c0ll, lmtr[i] = 0x3f3f3f3f3f3f3f3fll;
		rep(i, n){
			if(f[i] <= m)
				continue;
			lmtl[i] = a[i].x + (f[i] - m);
			lmtr[i] = a[i].x - (f[i] - m);
//			cout << i << ": " << lmtl[i] << " " << lmtr[i] << endl;
		}
		rep(i, n)
			lmtr[i + 1] = min(lmtr[i + 1], lmtr[i]);
		for(int i = n - 1; i > 0; i--)
			lmtl[i - 1] = max(lmtl[i - 1], lmtl[i]);
		rep(i, n)
			ans[a[i].ind] = (bool)(a[i].x + a[i].p >= lmtl[i] && a[i].x - a[i].p <= lmtr[i]);
		rep(i, n)
			cout << ans[i];
		cout << endl;
	}
	return 0;
}