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

int lap[10000100];

int cnt[10000100];
int lim = 10000 * 1000;
int n;
int sum[1000100];
void solve(){
	for(int i = 2; i * i <= lim; i++){
		if(!lap[i]){
			for(int k = i * i; k <= lim; k+=i){
				if(!lap[k])
					lap[k] = i;
			}
		}
	}
	int cc = 0;
	vector<int> pr;
	for(int i = 2;	i  <= lim; i++){
		if(!lap[i]) lap[i] = i;
		if(lap[i] == i) cc++;
	}
	//cout << cc << endl;
	//return;
	scanf("%d", &n);
	if(n <= 3){
		printf("0\n");
		return;
	}
	ll ans = 0;
	for(int i = 2; i <= n; i++){
		if(lap[i] == i) pr.pb(i);
		int x = i;
		int phi = i;
		while(x > 1){
			int p = lap[x];
			while(x % p == 0) x/=p;
			phi -= phi/p;
		}
		ans += phi * 2 + i - phi-1;
		cnt[lap[i]]++;
	}
	ans -= 2*(n-1);
	ll ss = 0;
	while(pr.size() > 0 && pr.back() * 2 > n){
		ans -= 2ll*ss*cnt[pr.back()];
		ss += cnt[pr.back()];
		pr.pop_back();
	}
	for(int i = 0; i < pr.size(); i++){
		ans -= 2ll * ss * cnt[pr[i]];
		sum[i + 1] = sum[i] + cnt[pr[i]];
	}
	for(int i = 0; i < pr.size(); i++){
		int l = i+1, r = pr.size()-1;
		int res = i+1;
		while(l <= r){
			int mid = (l + r)>>1;
			if(pr[mid] * 1ll * pr[i] <= n){
				res = mid+1;
				l = mid+1;
			}
			else {
				r = mid-1;
			}
		}
		ans += (sum[pr.size()] - sum[res]) * 1ll * cnt[pr[i]];
	}
	cout << ans << endl;
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