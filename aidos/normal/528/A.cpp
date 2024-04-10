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
#define forit(s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()

const int inf = (1ll << 31) - 1;
const int maxn = (int) 1e5 + 10;

using namespace std;
char c[11];

    set < pii > S1;
    set < int > w, h;
    set < pii > S2;
    int n, m, k;
int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif

	scanf("%d %d %d", &n, &m, &k);
	w.insert(0);
	h.insert(0);
	w.insert(n);
	h.insert(m);
	S1.insert(mp(n, n));
	S2.insert(mp(m, m));

	for(int i = 0, x; i < k; i++){
		scanf("%s %d\n", &c, &x);
		if(c[0] == 'H'){
			set < int > :: iterator it = h.lower_bound(x);	
			int val = *it;
			it--;
			int val2 = *it;
			S2.erase(mp(val - val2, val));
			S2.insert(mp(x-val2, x));
			S2.insert(mp(val - x, val));
			h.insert(x);
		}
		else {
		
			set < int > :: iterator it = w.lower_bound(x);	
			int val = *it;
			it--;
			int val2 = *it;
			S1.erase(mp(val - val2, val));
			S1.insert(mp(x-val2, x));
			S1.insert(mp(val - x, val));
			w.insert(x);
		}
		ll val = (--S1.end())->f;
		ll val2 = (--S2.end())->f;
		cout << val * 1ll * val2 << endl;
	}



    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}