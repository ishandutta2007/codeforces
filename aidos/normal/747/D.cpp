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
int n, k;
int t[200200];
void solve(){
	scanf("%d%d", &n, &k);
	int cnt = 0;
	for(int i = 0; i < n; i++){
		scanf("%d", &t[i]);
		if(t[i] < 0) cnt++;
	}
	if(cnt == 0){
		printf("0\n");
		return;
	}
	if(cnt > k){
		printf("-1\n");
		return;
	}
	k-=cnt;
	int ind = -1;
	for(int i = 0; i < n; i++){
		if(t[i] >= 0) continue;
		ind = i;
		break;
	}
	
	int cur = 1;
	
	if(t[n-1] >= 0) cur++;
	int last = n-1;
	while(t[last] >= 0) last--;
	set<pii> S;
	int z = -1;
	for(int i = 0; i < n; i++){
		if(t[i] < 0){
			if(z != -1){
				S.insert(mp(i-z-1, z));
			}
			z = i;
		}
	}
	cur += S.size() * 2;
	while(S.size() > 0){
		pii xx = *S.begin();
		if(xx.f > k){
			break;
		}
		S.erase(S.begin());
		k-=xx.f;
		cur -= 2;
	}
	if(last < n-1 && n - last - 1 <= k) cur--;
	printf("%d\n", cur);
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