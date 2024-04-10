#include <bits/stdc++.h>
#define all(a) (a).begin(),(a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
// head

string W[6] = {"S", "M", "L", "XL", "XXL", "XXXL"};

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	vector<int> c(6);
	for(int i = 0; i < 6; i++)
		cin >> c[i];
	int n; cin >> n;
	vector<pii> a(n,pii(-1,-1));
	for(int i = 0; i < n; i++) {
		string s; cin >> s;
		int m = sz(s), zap = -1;
		for(int j = 0; j < m; j++)
			if(s[j] == ',')
				zap = j;
		if(zap == -1) {
			for(int j = 0; j < 6; j++)
				if(s == W[j])
					a[i].ff = j;
		} else {
			for(int j = 0; j < 6; j++)
				if(s.substr(0,zap) == W[j])
					a[i] = pii(j,j+1);
		}
	}
	for(int i = 0; i < 6; i++) {
		for(int j = 0; j < n; j++)
			if(a[j].ff==-1&&a[j].ss==i || a[j].ff==i&&a[j].ss==-1)
				c[i]--;
		for(int j = 0; j < n; j++)
			if(a[j].ff==i&&a[j].ss!=-1) {
				if(c[i]>0)
					--c[i];
				else
					a[j].ff = -1;
			}
	}
	bool can = true;
	for(int i = 0; i < 6; i++)
		can &= (c[i] >= 0);
	if(!can)
		return cout<<"NO",0;
	cout<<"YES\n";
	for(int i = 0; i < n; i++) {
		int k = a[i].ff;
		if(k == -1)
			k = a[i].ss;
		cout << W[k] << "\n";
	}
}