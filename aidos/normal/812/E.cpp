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
int n;
int a[100100];
int p[100100];
int lev[100100];
int b[10];
map<int, int> m[10];
int c[11];
int cnt[11];
void solve(){
	scanf("%d", &n);
	for(int i = 1; i <= n;i++){
		scanf("%d", &a[i]);
	}
	for(int i = 2; i <= n; i++){
		scanf("%d", &p[i]);
		lev[i] = lev[p[i]]^1;
	}
	for(int i = 1; i <= n; i++){
		b[lev[i]] ^= a[i];
		m[lev[i]][a[i]]++;
		cnt[lev[i]]++;
	}
	//cout << b[0] << " " << b[1] << endl;
	int w = lev[n];
	ll ans = 0;
	for(int i = 1; i <= n; i++){
		if(lev[i] == w){
			if(b[w] == 0){
				ans += cnt[w] - 1;
			}
			int x = b[w] ^ a[i];
			ans += m[w^1][x];
		}
		else {
			if(b[w] == 0){
				ans += cnt[w^1] - 1;
			}
			int x = b[w] ^ a[i];
			ans += m[w][x];
		}
	}
	cout << ans / 2 << endl;
}

int main () {
	#ifdef LOCAL
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	#endif
    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}