#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <ctime>

#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define ull unsigned long long
#define pll pair < ll, ll >
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()
#define sz(a) (int)a.size()
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <ctime>

#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define ull unsigned long long
#define pll pair < ll, ll >
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()
#define sz(a) (int)a.size()

const int inf = (1 << 29) - 1;
const int maxn = (int)1e6 + 10; //maximum + 10
const int mod = (int) 1e9 + 7;
using namespace std;
int n, m;
ll a[2020];
ll b[2020];
ll sa[2020];
ll sb[2020];

void solve(){
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		sa[i] = sa[i-1] + a[i];
	}
	cin >> m;
	for(int i = 1; i <= m; i++) {
		cin >> b[i];
		sb[i] = sb[i-1] + b[i];
	}
	ll ans = abs(sa[n] - sb[m]);
	int ok = 0;
	vector<int> z;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			ll cur = (sa[n] - a[i] + b[j]) - (sb[m] - b[j] + a[i]);
			if(abs(cur) < ans) {
				ans = abs(cur);
				z = {i, j};
			}			
		}
	}
	set< pair<ll, ll> > S;
	for(int i1=1; i1 <= n; i1++){
		for(int i2 = i1+1; i2 <= n; i2++){
			ll cur = sa[n] - sb[m]- 2*(a[i1] + a[i2]);
			S.insert(mp(cur, i1 * (n+1ll) + i2));
		}
	} 
	for(int j1 = 1; j1 <= m; j1++){
		for(int j2 = j1 + 1; j2 <= m; j2++){
			ll d = 2*(b[j1] + b[j2]);
			set< pair<ll, ll> > :: iterator it = S.lower_bound(mp(-d, -1));
			if(it != S.end()) {
				ll cur = it->f + d;
				if(abs(cur) < ans) {
					ans = abs(cur);
					int i1 = it->s/(n+1);
					int i2 = it->s % (n+1);
					z = {i1, j1, i2, j2};
				}
			}
			if(it != S.begin()) {
				it--;
				ll cur = it->f + d;
				if(abs(cur) < ans) {
					ans = abs(cur);
					int i1 = it->s/(n+1);
					int i2 = it->s % (n+1);
					z = {i1, j1, i2, j2};
				}
			}
		}
	}
	cout << ans << "\n";
	cout << z.size()/2 << "\n";
	for(int i = 0; i < z.size(); i += 2) {
		cout << z[i] << " "<< z[i + 1] << "\n";
	}


}
int main () {

    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d: ", i);
      solve();
    }
    
    return 0;
}