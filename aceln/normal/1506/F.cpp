#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
const int maxn=1e6+7;
const int inf=2e9;
const ll inff=1e18;
const ll mod=1e9+7;
#define pii pair<int,int>
#define mkp make_pair
#define F first
#define S second
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
//#define int ll

int a[maxn],b[maxn];

int32_t main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int _; cin>>_;
	while (_--) {
		int n; cin>>n;
		for (int i=1;i<=n;i++) cin>>a[i];
		for (int i=1;i<=n;i++) cin>>b[i];
		vector<pii> v;
		v.pb({1,1});
		for (int i=1;i<=n;i++) v.pb({a[i],b[i]});
		sort(all(v));

		ll ans=0;
		for (int i=1;i<=n;i++) {
			if ((v[i-1].F+v[i-1].S)&1) {
				ans+=(v[i].F-v[i-1].F-(v[i].S-v[i-1].S)+1)/2; 
			}
			else {
				if (v[i].F-v[i-1].F == v[i].S-v[i-1].S) ans+=(v[i].F-v[i-1].F);
				else ans+=(v[i].F-v[i-1].F-(v[i].S-v[i-1].S))/2;
			}
		}
		cout<<ans<<'\n';
	}
}