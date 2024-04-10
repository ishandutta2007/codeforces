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
int n, m, x;
int p[100100];
int a[100100];
int b[100100];
int sum = 0;
int check(int d){
	ll cur = 0;
	for(int i = 0; i < d; i++){
		b[i] = a[n-d+i] - p[i];
		if(b[i] < 0)  cur -= b[i];
	}
	if(cur > x) return 0;
	ll dif = x - cur;
	for(int i = 0;  i < d; i++){
		if(b[i] < 0){
			dif -= b[i];
			cur += b[i];
			ll cc = min(dif, p[i] * 1ll);
			cur += cc;
			dif -= cc;
		}else{
			ll cc = min(dif, p[i] * 1ll);
			cur += cc;
			dif -= cc;
		}
		cur -= p[i];
	}
	sum = -cur;
	return 1;
}
void solve(){
	scanf("%d%d%d", &n, &m, &x);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	for(int i = 0; i < m; i++) scanf("%d", &p[i]);
	sort(a, a + n);
	sort(p, p + m);
	int l = 1, r = min(n, m);
	int res = 0;
	while(l <= r){
		int mid = (l + r)>>1;
		if(check(mid)){
			res = mid;
			l = mid+1;
		}
		else r = mid-1;
	}
	if(!res){
		cout << 0 << " " << 0 << endl;
		return;
	}
	check(res);
	cout << res << " "<<sum << endl;
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