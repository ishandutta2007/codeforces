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
int n;
int a[maxn];
int ans = 1<<30;
void rec(int l, int r, int m, int b) {
	if(b == -1) {
		ans = min(ans, m ^ a[l]);
		return;
	}
	int pos = l;
	while(pos <= r && ((a[pos]^a[l]) & (1<<b)) == 0) {
		pos++;
	}
	if(pos == r + 1) {
		rec(l, r, m^(a[l]&(1<<b)), b-1);
		return;
	}
	rec(l, pos-1, m^(1<<b),b-1);
	rec(pos, r, m, b-1);
}
void solve(){
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	rec(0, n-1, 0, 29);

	cout << ans << "\n";
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