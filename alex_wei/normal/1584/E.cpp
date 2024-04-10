#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair <ll, ll>

const int N = 3e5 + 5;
ll n, ans;
map <ll, int> s;
int main(){
	int T; cin >> T;
	while(T--) {
		cin >> n, ans = 0, s.clear();
		for(ll i = 1, a, ne = 1, del = 0; i <= n; i++) {
			cin >> a, ne ^= 1, del = -del + a;
			ne ? s[del - a]++ : s[a - del]++;
			while(s.size()) {
				if(ne) {
					pll it = *--s.end();
					if(it.first > del) s.erase(--s.end());
					else break;
				} else {
					pll it = *s.begin();
					if(it.first < -del) s.erase(s.begin());
					else break;
				}
			} ans += ne ? s[del] : s[-del]; 
		} cout << ans << endl;
	}
	return 0;
} //