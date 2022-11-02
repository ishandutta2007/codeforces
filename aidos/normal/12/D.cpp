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
const int maxn = (int) 1e5 + 10;
const int mod = (int) 1e9 + 7;
using namespace std;
int n;
pair<int, pii> e[500500];
int a[500500];
int k;
int t[500500];
int get(int x) {
	int i = k - x - 1;
	int res = 0;
	while(i >= 0) {
		res = max(res, t[i]);
		i = (i&(i+1)) - 1;
	}	
	return res;
}
void upd(int x,int y){
	int i = k - x;
	while(i<=k) {
		t[i] = max(t[i], y);
		i |= i+1;
	}
}
void solve(){
	scanf("%d", &n);
	for(int i = 0 ; i < n; i++) {
		scanf("%d", &e[i].f);
	}
	for(int i = 0; i < n; i++){
		scanf("%d", &e[i].s.f);
		a[i] = e[i].s.f;
	}
	
	for(int i = 0; i < n; i++){
		scanf("%d", &e[i].s.s);
	}
	sort(a, a + n);
	k = unique(a, a + n) - a;
	for(int i = 0; i < n; i++) e[i].s.f = lower_bound(a, a + k, e[i].s.f) - a;
	sort(e, e + n);
	int ans = 0;
	for(int i=n-1; i >= 0; ){
		int j = i;
		while(i >= 0 && e[i].f == e[j].f) {
			if(get(e[i].s.f) > e[i].s.s) ans++;
			i--;
		}
		while(j>i) {
			upd(e[j].s.f, e[j].s.s);
			j--;
		}
	}
	cout << ans << "\n";
}
int main () {
    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}