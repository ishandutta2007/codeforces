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
map<vector<int>, int> mm;
int n, k, x;
vector<int> c;
void solve(){
	scanf("%d%d%d", &n, &k, &x);
	for(int i = 0, y; i < n; i++){
		scanf("%d", &y);
		c.pb(y);
	}
	sort(all(c));
	mm[c] = 0;
	int it = 1;
	while(k > 0){
		for(int i = 0; i < n; i+=2)
			c[i] ^= x;
		sort(all(c));
		if(mm.count(c)) {
			k--;
			break;
		}
		k--;
		mm[c] = it;
		it++;
	}
	vector<int> y = c;
	int sz = 0;
	while(k > 0){
		for(int i = 0; i < n; i+=2)
			c[i] ^= x;
		sort(all(c));
		sz++;
		k--;
		if(c == y) break;
	}
	if(sz > 0)
		k %= sz;
	while(k > 0){
		for(int i = 0; i < n; i+=2)
			c[i] ^= x;
		sort(all(c));
		k--;
	}
	cout << c[n-1] << " "<< c[0] << endl;
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