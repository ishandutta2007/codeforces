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
ll t[100100];
int a[100100];
ll get(int pos){
	ll res = 0;
	while(pos >= 0){
		res += t[pos];
		pos = (pos & (pos + 1)) - 1;
	}
	return res;
}
void inc(int pos, int val){
	while(pos <= n){
		t[pos] += val;
		pos |= (pos + 1);
	}
}
void clr(){
	for(int i = 0; i <= n; i++)
		t[i] = 0;	
}


void solve(){
	scanf("%d", &n);
	//n = 100000;
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		//a[i] = n-i + 1;
	}
	clr();
	ll X = 0;
	for(int i = n; i > 0; i--){
		X += get(a[i]-1);
		inc(a[i], 1);
	}
	clr();
	long double ans = 0;
	long double del = n;
	del *= n + 1;
	del/=2;
	for(int i = n; i > 0; i--){
		ll g = get(a[i] - 1);
		g *= i;
		ans -= g;
		inc(a[i], n - i + 1);
	}
	long double xx = 0.0;
	for(int i = 2; i <= n; i++){
		xx += (i-1) * 1.0/2;
		ans += xx * (n -i + 1);
	}
	ans/=del;
	ans += X;
	printf("%.15lf\n", (double) ans);
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