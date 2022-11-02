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

using namespace std;

int n, k1, k2, k;
int a[10111];
int b[11111];
void solve(){
	cin >>n >> k1 >> k2;
	k = k1 + k2;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) cin >> b[i];
	for(int i = 0; i < n; i++) a[i] -= b[i];
	for(int i = 0; i < k; i++){
		int t= -1;
		for(int j = 0; j < n; j++){
			if(t == -1 || abs(a[j]) > abs(a[t])) t = j;
		}
		if(a[t] < 0) a[t]++;
		else a[t]--;
	}
	ll ans = 0;
	for(int i = 0; i < n; i++) ans += a[i] * 1ll * a[i];
	cout << ans << endl;
	
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