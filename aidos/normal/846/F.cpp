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
int n, x;
long double ans = 0;
int last[1000100];
int a[1000100];
void solve(){
	scanf("%d", &n);
	for(int i = 1; i <=n; i++){
		scanf("%d", &x);
		a[i] = x;
		ans += (i - last[x]) * 1ll * (n - i + 1);
		last[x] = i;
	}
	reverse(a + 1, a + n + 1);
	for(int i = 1; i< 1000100-10; i++)
		last[i] = 0;
	for(int i = 1; i <= n; i++){
		x = a[i];
		ans += (i - last[x]) * 1ll * (n - i + 1);
		last[x] = i;
	}
	ans -= n;
	ll d = n * 1ll * (n+1) - n;
	ans/=d;
	printf("%.12lf", (double)ans);
}

int main () {
    //cout << "Hello world\n";
    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}