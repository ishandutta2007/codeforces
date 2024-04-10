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
ll n;
int k;
void solve(){
	cin >> n >> k;
	map<ll, int> M;
	int kk = k;
	for(int i = 60; i >= 0; i--){
		if(n&(1ll<<i)){
			M[i]++;
			k--;
		}
	}
	if(k<0){
		printf("No\n");
		return;
	}

	while(k>0){
		map<ll, int>:: iterator it = M.end();
		it--;
		ll val = it->f-1;
		if(it->s == 1){
			M.erase(it);
		}
		else M[it->f]--;
		M[val]+=2;
		k--;
	}
	int opt = (--M.end())->f;
	M.clear();
	k = kk;
	for(int i = 60; i >= 0; i--){
		if(n&(1ll<<i)){
			n -= (1ll<<i);
			M[i]++;
			k--;
		}
	}
	while(k>0){
		map<ll, int>:: iterator it = M.end();
		it--;
		ll val = it->f-1;
		if(it->f == opt) break;
		if(it->s == 1){
			M.erase(it);
		}
		else M[it->f]--;
		M[val]+=2;
		k--;
	}
	while(k>0){
		map<ll, int>:: iterator it = M.begin();
		ll val = it->f-1;
		if(it->s == 1){
			M.erase(it);
		}
		else M[it->f]--;
		M[val]+=2;
		k--;
	}
	vector<int> ans;
	forit(it, M){
		for(int j = 0; j < it->s; j++) ans.pb(it->f);
	}
	reverse(all(ans));
	printf("Yes\n");
	for(int i = 0; i < ans.size(); i++){
		printf("%d ", ans[i]);
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