#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;

int T;
int n;
pair<int, int> a[200200], b[200200];
ll ans = 0;
map<int, int> cnt;

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> n;
		cnt.clear();
		rep(i, n){
			cin >> a[i].first >> a[i].second;
			cnt[a[i].second]++;
		}
		sort(a, a + n), sort(b, b + n);
		ans = 1LL * n * (n - 1) * (n - 2) / 6LL;
		int l = 0, r = 0;
//		while(l < n){
//			r = l;
//			while(r < n && a[r].first == a[l].first)
//				r++;
//			if(r >= l + 2)
//				ans = ans - 1LL * (r - l) * (r - l - 1) / 2ll * (n - 2);
//			l = r;
//		}
//		l = r = 0;
//		while(l < n){
//			r = l;
//			while(r < n && b[r].first == b[l].first)
//				r++;
//			if(r >= l + 2)
//				ans = ans - 1LL * (r - l) * (r - l - 1) / 2LL * (n - 2);
//			cnt[b[l].first] = r - l;
//			l = r;
//		}
//		l = r = 0;
		while(l < n){
			r = l;
			while(r < n && a[r].first == a[l].first){
				r++;
			}
			for(int k = l; k < r; k++){
				ans -= 1LL * (cnt[a[k].second] - 1) * (r - l - 1);
			}
			l = r;
		}
		cout << ans << endl;
	} 
	return 0;
}