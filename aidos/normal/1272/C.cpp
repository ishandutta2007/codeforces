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
 
const int inf = (1ll << 30) - 1;
const int maxn = (int) 2e5 + 10;
using namespace std;
int n, k;
string s;
set<char> S;
int a[maxn];
void solve(){    
	cin >> n >> k;
	cin >> s;
	S.clear();
	for(int i = 0; i < k; i++) {
		char x;
		cin >> x;
		S.insert(x);
	}
	a[n] = 1;
	for(int i = 0; i < n; i++) {
		if(S.count(s[i])) a[i] = 0;
		else a[i] = 1;
	}
	ll ans = 0;
	for(int i = 0; i < n; ) {
		ll j = i;
		while(a[i] == 0) i++;
		ans += (i-j) * (i-j+1)/2;
		i++;
	}
	cout << ans << "\n";
}
int main () {
	int t=1;
	//cin >> t;
	for(int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}