#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;

int n;
int a[200200];
int l[200200], secl[200200];
ll suml[200200], sumsecl[200200];

int main(){
	ios::sync_with_stdio(false);
	
	cin >> n;
	rep(i, n)
		cin >> a[i];
	
	ll ans = 0;
	for(int i = 0, nl = 0, nsecl = 0; i < n; ++i){
		if(i-a[i]+1 > nl)
			nsecl = nl, nl = i-a[i]+1;
		else if(i-a[i]+1 > nsecl)
			nsecl = i-a[i]+1;
		l[i] = nl, secl[i] = nsecl, ans += (i-nl+1);
		suml[i+1] = suml[i] + nl, sumsecl[i+1] = sumsecl[i] + nsecl;
	}
	
//	cout << ans << endl;
	int q;
	cin >> q;
	while(q--){
		int p, x;
		cin >> p >> x;
		--p;
		if(x <= a[p]){
			int nl = p-x+1;
			if(nl > l[p]){
				int t = lower_bound(l, l+n, nl) - l;
				t = max(t, p);
//				cout << t << " " << p << endl;
				cout << ans - (1ll * (t-p) * nl - (suml[t]-suml[p])) << '\n';
			} else 
				cout << ans << endl;
		} else {
			if(l[p] != p-a[p]+1){
				cout << ans << endl;
				continue;
			}
			int t = upper_bound(l, l+n, l[p]) - l;
			int lmt = max(secl[p], p-x+1);
			int tt = lower_bound(secl, secl+n, lmt) - secl;
			if(tt < p) tt = p;
			if(tt > t) tt = t;
//			cout << p << " " << tt << " " << t << endl;
			cout << ans + (1ll * (tt-p) * (l[p]-lmt)) + (suml[t]-suml[tt]) - (sumsecl[t]-sumsecl[tt]) << '\n';
		}
	}
	
	return 0;
}