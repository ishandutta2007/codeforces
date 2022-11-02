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
int a[maxn];
void solve(){
	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	ll c = 0;
	int x = a[0], t = 1;
	int l = 0;
	for(int i = 1; i < n; i++) {
		c += (i-l) * 1ll * (a[i] - a[i-1]);
		while(c > k) {
			c -= a[i] - a[l];
			l++;
		}
		if(i - l + 1 > t) {
			t = i - l + 1;
			x = a[i];
		}
	}
	cout << t << " " << x << "\n";
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