#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
#define lg(a) (31-__builtin_clz(a))
const int LIM=2e5+7;
int T[LIM], dl[LIM];
int main() {
	int n, t, szuk, p=0;
	cin >> n >> t >> szuk;
	while(p<n) {
		cout << "? " << p+1 << " " << min(p+16, n) << endl;
		cin >> T[p/16];
		dl[p/16]=min(n-1, p+15)-p+1;
		p+=16;
	}
	rep(i, t) {
		int l=0;
		while(szuk>dl[l/16]-T[l/16]) {
			szuk-=dl[l/16]-T[l/16];
			l+=16;
		}
		int k=min(l+15, n-1);
		p=l;
		while(p<k) {
			int sr=(p+k)/2;
			cout << "? " << l+1 << " " << sr+1 << endl;
			int x;
			cin >> x;
			x=sr-l+1-x;
			if(x<szuk) p=sr+1; else k=sr;
		}
		cout << "! " << p+1 << endl;
		++T[p/16];
		if(i<t-1) cin >> szuk;
	}
}