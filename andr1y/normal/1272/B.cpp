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
		string s;
		cin >> s;
		ll lc = 0, rc = 0, uc = 0, dc = 0;
		for(ll i = 0;i<s.length();i++){
			if(s[i] == 'L') lc++;
			if(s[i] == 'R') rc++;
			if(s[i] == 'U') uc++;
			if(s[i] == 'D') dc++;
		}
		ll hc = min(lc, rc), vc = min(uc, dc);
		if(vc == 0){
			if(hc >= 1) cout << "2\nRL\n";
			else cout << "0\n";
		}else{
			if(hc == 0) cout << "2\nUD\n";
			else{
				cout << hc*2+vc*2 << endl;
				for(ll i = 0;i<hc;i++) cout << 'R';
				for(ll i = 0;i<vc;i++) cout << 'U';
				for(ll i = 0;i<hc;i++) cout << 'L';
				for(ll i = 0;i<vc;i++) cout << 'D';
				cout << endl;
			}
		}
	}
}