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
#include<cassert>
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
int a[1000100];
pii b[1000100];
vector<int> ans;
int cnt[10000100];
int m, k;

void solve(){
	scanf("%d%d%d", &n, &m, &k);
	int l = (n+k-1)/k, r = (n+m+k-1)/k;
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		cnt[a[i]]++;
	}
	for(int i = 0; i < m; i++){
		scanf("%d", &b[i].f);
		b[i].s = i;
	}
	sort(a, a+n);
	sort(b, b+m);
	int mx = (int) 1e7 + 1;
	for(int i = mx; i > 0; i--){
		if(cnt[i] > k){
			cnt[i-1] += cnt[i] - k;
			cnt[i] = k;
		}
	}
	int ind = 0;
	if(cnt[0] > k){
		printf("-1\n");
		return;
	}
	for(int i = 0; i < m; i++){
		while(cnt[ind] == k){
			ind++;
		}
		if(ind <= b[i].f){
			cnt[ind]++;
			ans.pb(b[i].s + 1);
		}
	}
	sort(all(ans));
	printf("%d\n", (int)ans.size());
	for(int x:ans){
		printf("%d ", x);
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