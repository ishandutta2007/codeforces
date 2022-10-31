#include <bits/stdc++.h>
#define ld long double
#define ll long long
#define ull unsigned ll
#define pll pair<ll, ll>
#define itr(a) begin(a), end(a)
#define pb push_back
#define x first
#define y second
#define endl '\n'
#define FAST cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FILES(namein, nameout) freopen(namein, "r", stdin); freopen(nameout, "w", stdout);
#define M 1000000007
#define N 200000
#define INF 101111111111111
using namespace std;
int main(){
	FAST;
	ll q;
	cin >> q;
	while(q--){
		ll n, a, b, c, r = 0, p = 0, s = 0;
		cin >> n >> a >> b >> c;
		string ss;
		for(ll i =0;i<n;i++){
			char c;
			cin >> c;
			ss+=c;
			if(c == 'R') r++;
			else if(c == 'P') p++;
			else if(c == 'S') s++;
		}
		ll nr = min(r, b), fb = max<ll>(0, b-nr);
		ll np = min(p, c), fc = max<ll>(0, c-np);
		ll ns = min(s, a), fa = max<ll>(0, a-ns);
		ll can = nr+np+ns;
		if((n%2 == 0 && can >= n/2) || (n%2 == 1 && can > n/2)){
			cout << "YES" << endl;
			for(ll i =0;i<n;i++){
				bool us = false;
				if(ss[i] == 'R'){
					if((nr--) > 0) cout << 'P';
					else us = true;
				}else if(ss[i] == 'P'){
					if((np--) > 0) cout << 'S';
					else us = true;
				}else if(ss[i] == 'S'){
					if((ns--) > 0) cout << 'R';
					else us = true;
				}
				if(us){
					if((fa--) > 0) cout << 'R';
					else if((fb--) > 0) cout << 'P';
					else if((fc--) > 0) cout << 'S';
				}
			}
		}
		else cout << "NO";
		cout << endl;
	}
}