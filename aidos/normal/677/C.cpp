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

const int inf = (1ll << 25) - 1;
const int maxn = (int)1e5+20;
const int mod = (int) 1e9 + 7;
using namespace std;
int n;
int a[maxn];
char c[maxn];
int cnt[100];

int get(char c) {
	if(c == '_') return 63;
	if(c == '-') return 62;
	if(c >= '0' && c <= '9') return c - '0';
	if(c >= 'A' && c <= 'Z') return c - 'A' + 10;
	return c - 'a' + 36;
}

void solve(){
	scanf("%s", c);
	n = strlen(c);
	for(int i = 0; i < 64; i++) {
		for(int j = 0; j < 64; j++) {
			cnt[i&j]++;
		}
	}
	ll ans = 1;
	for(int i = 0; i < n; i++) {
		ans = ans * cnt[get(c[i])] % mod;
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