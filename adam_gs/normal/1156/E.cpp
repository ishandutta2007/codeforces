#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
#define int long long
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=2e5+7;
int T[LIM], wlewym[LIM], wprawym[LIM], akt, ans;
void dc(int l, int r) {
	if(l==r) return;
	++akt;
	int mid=(l+r)/2;
	vector<int>lewo, prawo;
	lewo.pb(T[mid]);
	prawo.pb(T[mid+1]);
	for(int i=mid-1; i>=l; --i) if(T[i]>lewo.back()) {
		lewo.pb(T[i]);
	}
	for(int i=mid+2; i<=r; ++i) if(T[i]>prawo.back()) {
		prawo.pb(T[i]);
	}
	int l1=0, l2=0, ll=mid, lr=mid+1;
	while(l1<lewo.size() || l2<prawo.size()) {
		if(l1<lewo.size() && (l2==prawo.size() || lewo[l1]<prawo[l2])) {
			while(ll>=l && T[ll]<=lewo[l1]) {
				wlewym[T[ll]]=akt;
				if(wprawym[lewo[l1]-T[ll]]==akt) ++ans;
				--ll;
			}
			++l1;
		} else {
			while(lr<=r && T[lr]<=prawo[l2]) {
				wprawym[T[lr]]=akt;
				if(wlewym[prawo[l2]-T[lr]]==akt) ++ans;
				++lr;
			}
			++l2;
		}
	}
	dc(l, mid);
	dc(mid+1, r);
}
int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	rep(i, n) cin >> T[i];
	dc(0, n-1);
	cout << ans << '\n';
}