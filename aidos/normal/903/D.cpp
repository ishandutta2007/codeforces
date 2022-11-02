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
map<int, int > C;
ll cur = 1e9;
void add(pll &x, ll y){
	x.s += y;
	if(x.s >= cur){
		x.f += x.s/cur;
		x.s %= cur;
	}
}
void out(pll ans){
	if(ans.f == 0){
		cout << ans.s << endl;
		exit(0);
	}             
		printf("%I64d%09I64d\n", ans.f, abs(ans.s));
		exit(0);

}
void solve(){
	scanf("%d", &n);
	pll ans1 = mp(0, 0);
	pll ans2 = mp(0, 0);
	ll sum = 0;
	vector<ll> li;

	for(int i = 0, x; i < n; i++){
		scanf("%d", &x);
		ll cur = x * 1ll * i - sum + (ll) C[x+1] - (ll)C[x-1];
		if(cur > 0){
			add(ans1, cur);
		}
		else if(cur < 0){
			add(ans2, -cur);
		}
		sum += x;
		C[x]++;
	}
	ans1.f -= ans2.f;
	ans1.s -= ans2.s;
	if(ans1.f == 0){
		out(ans1);
		return;
	}
	if(ans1.s == 0){
		out(ans1);
		cout << ans1.f;
		for(int i = 0; i < 9; i++){
			cout << "0";
		}
		return;
	}
	if(ans1.f > 0){
		if(ans1.s < 0){
			ans1.f--;
			ans1.s += cur;
		}
		out(ans1);
	}
	if(ans1.f < 0){
		if(ans1.s > 0){
			ans1.f++;
			ans1.s-=cur;
		}
		out(ans1);
	}

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