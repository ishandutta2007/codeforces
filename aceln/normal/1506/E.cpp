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

int a[maxn];

int32_t main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while (t--) {
		int n; cin>>n;
		set<int> s;
		for (int i=1;i<=n;i++) cin>>a[i];

		for (int i=1;i<=n;i++) s.insert(i);
		for (int i=1;i<=n;i++) {
			if (a[i]!=a[i-1]) {
				cout<<a[i]<<' ';
				s.erase(a[i]);
			}
			else {
				int tmp=(*s.begin());
				cout<<tmp<<' ';
				s.erase(tmp);
			}
		}
		cout<<'\n';

		for (int i=1;i<=n;i++) s.insert(i);
		for (int i=1;i<=n;i++) {
			if (a[i]!=a[i-1]) {
				cout<<a[i]<<' ';
				s.erase(a[i]);
			}
			else {
				int tmp=(*prev(s.lower_bound(a[i])));
				cout<<tmp<<' ';
				s.erase(tmp);
			}
		}
		cout<<'\n';

	}
}