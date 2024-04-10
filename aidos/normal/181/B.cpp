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
int u[4020][4020];
pii a[maxn];
void solve(){
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i].f >> a[i].s;
		a[i].f += 1000;
		a[i].s += 1000;
		u[a[i].f][a[i].s] = 1;
	}
	int ans = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(j == i) continue;
			int dx = a[j].f - a[i].f;
			int dy = a[j].s - a[i].s;
			int x = a[j].f + dx;
			int y = a[j].s + dy;
			if(x < 0 || y < 0 || x >= 4020 || y >= 4020) continue;
			ans += u[x][y];
		}
	}
	ans /= 2;
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