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
const int mod = (int) 1e9 + 7;
using namespace std;
int n;
int a[200200];
pii c[200200];
void solve(){
	cin >> n;
	for(int i = 0; i < n; i++) c[i] = mp(0, 0);
	for(int i = 0; i < n; i++) {
		int x, d;
		cin >> x >> d;
		c[x-1].f++;
		c[x-1].s+=d;
	}
	sort(c, c + n);
	int k = 0;
	set<pair<pii, int>> S;
	for(int i = 0; i < n; i++) {
		if(c[i].f > k) k++;
		S.insert(mp(c[i], i));
	}
	int ans = 0;
	int ans2 = 0;
	int cur=inf;
	while(k>0) {
		while((--S.end())->f.f >= cur) {
			pair<pii, int> d = *(--S.end());
			S.erase(d);
			d.f.f = cur-1;
			S.insert(d);
		}
		k--;
		
		pair<pii, int> d = *(--S.end());
		S.erase(d);
		ans += d.f.f;
		ans2 += max(d.f.f-d.f.s, 0);
		cur = d.f.f;
	}
	cout<<ans << " "<<ans-ans2 << "\n";
}

int main () {
    int t=1;
    scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }
    
    return 0;
}