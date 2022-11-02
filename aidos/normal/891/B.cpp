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
pii a[1111];
int p[1111];
int b[1111];
void solve(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i].f;
		a[i].s = i;
		p[i] = i;
	}
	sort(a, a + n);
	for(int i = 1; i < n; i++){
		p[i-1] = i;
	}
	p[n-1] = 0;
	int bad = 0;
	for(int m = 1; m < (1<<n)-1; m++){
		ll sum = 0;
		for(int i = 0; i < n; i++){
			if(m&(1<<i)){
				sum += a[i].f - a[p[i]].f;
			}
		}
		if(sum == 0){
			bad = 1;
		}
	}
	if(!bad){
		for(int i = 0; i < n; i++){
			b[a[p[i]].s] = a[i].f;
		}
		for(int i = 0; i < n; i++){
			cout << b[i] << " ";
		}
		cout << endl;
		return;
	}
	cout << -1 << endl;
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