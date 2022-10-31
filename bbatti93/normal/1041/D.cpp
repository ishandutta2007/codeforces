#include <bits/stdc++.h>
#define FOR(i,n) for(ll i = 0; i < (ll)n; ++i)
template<class T> bool MX(T &l,const T &r){return l<r?l=r,1:0;}
using namespace std; typedef long long ll;

int main() { ios_base::sync_with_stdio(0);cin.tie(0);
	ll n, h, l, a, ei=0, ma=0, sp=0;
	cin >> n >> h;
	vector<ll> s(n),e(n),m(n);
	FOR(i,n) {
	    cin >> s[i] >> e[i];
	    if (i>0) m[i-1]=s[i]-e[i-1];
    }
	FOR(si,n) {
		if (si>0 && h>m[si-1]+sp) {
            a=m[si-1]+sp;
            l-=sp;
        } else {
            l=e[si];
            a=h;
            ei=si;
        }
		sp=0;
		while (a>0) {
			if (ei==n-1 || m[ei]>=a) {
                l+=a;
                sp=a;
                a=0;
			} else {
			    a-=m[ei];
			    ++ei;
			    l=e[ei];
            }
        }
		MX(ma,l-s[si]);
	}
	cout << ma << endl;
	return 0;
}