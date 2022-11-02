#include <bits/stdc++.h>
using namespace std;


#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define pll pair < ll, ll >
#define all(s) s.begin(), s.end()
#define sz(s) (int) s.size()
#define vi vector < int >

const int inf = (int)1e9;
const int mod = (int) 1e9 + 7;

int n;
int t[200200];
int a[5];
int nxt[200200];
bool used[200200];
set < pii > S;
int ans= 0;
int main () {

    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> n;
    for(int i = 0; i < 3; i++)
    	cin >> a[i];
	for(int i = 0; i < n; i++){
		cin >> t[i];
		S.insert({t[i], i});
	}
	sort(a, a + 3);

	if((--S.end())->f > a[0] + a[1] + a[2]){
		cout << -1 << endl;
		return 0;
	}
	while(S.size()  > 0 && (--S.end())->f > a[2] + a[1]){
		S.erase(--S.end());
		ans++;
	}
	while(S.size() > 0 && (--S.end())->f > a[2] + a[0]){
		S.erase(--S.end());
		ans++;
		if(S.size() > 0 && S.begin()->f <= a[0]) {
			S.erase(S.begin());
		}
	}
	while(S.size() > 0 && (--S.end())->f > max(a[2], a[1]+ a[0])){
		S.erase(--S.end());
		ans++;
		set < pii > :: iterator it = S.upper_bound(mp(a[1], 300000));
		if(it != S.begin()) {
			it--;
			S.erase(it);
		}
	}
	if(a[1] + a[0] > a[2]){
		while(S.size() > 0 && (--S.end())->f > a[2]){
			S.erase(--S.end());
			ans++;
			set < pii > :: iterator it = S.upper_bound(mp(a[2], 300000));
			if(it != S.begin()) {
				it--;
				S.erase(it);
			}
		}
	}
	while(S.size() > 0){
		S.erase(--S.end());
		set < pii > :: iterator it = S.upper_bound(mp(a[1], 300000));
		ans++;
		if(it != S.begin()) {
			it--;
			S.erase(it);
			it = S.upper_bound(mp(a[0], 300000));
			if(it != S.begin()){
				it--;
				S.erase(it);
			}
		}else {
			it = S.upper_bound(mp(a[1] + a[0], 300000));
			if(it != S.begin()){
				it--;
				S.erase(it);
			}
		}
	}
	cout << ans << endl;
	
	
    


    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}