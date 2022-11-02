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
int a[200100];
pii b[200200];
int ans[200200];
int k;
void solve(){
	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		b[i-1] = mp(a[i], i);	
	}
	sort(b, b + n);
	for(int i = 0, l = 0; i < n; i++){
		while(b[l].f < b[i].f) l++;
		ans[b[i].s] = l;
	}
	for(int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		if(a[x] == a[y]) continue;
		if(a[x] > a[y]) ans[x]--;
		else ans[y]--;
	}
	for(int i = 1; i <= n; i++) cout << ans[i] << " ";
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