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
const int maxn = (int)1e5 + 10; //maximum + 10
const int mod = (int) 1e9 + 7;
using namespace std;

int n, k;
pii a[maxn];
int calc(int x) {
	int cnta = 0;
	int cntb = 0;
	for(int i = 0; i < n; i++) {
		if(a[i].f == x) cnta++;
		else if(a[i].s == x) cntb++;
	}
	if((cnta + cntb) * 2 < n) return inf;
	if(cnta * 2 >= n) return 0;
	return (n - cnta * 2 + 1)/2;
}
void solve(){
	cin >> n;
	map<int, int> m;
	for(int i = 0; i < n; i++) {
		cin >> a[i].f >> a[i].s;
		m[a[i].f]++;
		m[a[i].s]++;
	}
	int ans = inf;
	for(auto x: m) {
		if(x.s * 2 >= n) ans = min(ans, calc(x.f));
	}
	if(ans == inf) ans = -1;
	cout << ans << "\n";
}
int main () {

	int t = 1;
	//scanf("%d", &t);
	for(int i=1; i<=t; i++){
		//printf("Case #%d: ", i);
		solve();
	}
    return 0;
}