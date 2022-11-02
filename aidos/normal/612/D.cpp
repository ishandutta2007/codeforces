#include <bits/stdc++.h>
using namespace std;


#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define pll pair < ll, ll >
#define all(s) s.begin(), s.end()
#define sz(s) (int) s.size()
#define vi vector < int >

const int inf = (int)1e9;
const int mod = (int) 1e9 + 7;

map < int, int > m;
vector < pii > v1, v;
int n, k;

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    scanf("%d %d\n", &n, &k);
    int prev = -2e9;
    int prev2 = -2e9;
    int last = 0;
    for(int i = 0,l,r; i < n; i++){
    	scanf("%d %d\n", &l, &r);
    	v1.pb(mp(2 * l, 1));
    	v1.pb(mp(2 * r, 0));
    	v1.pb(mp(2 * r+1, -1));
    }
    sort(v1.begin(), v1.end());
    n = v1.size();
    int pr = 0;
	for(int i = 0; i < n; ){
		int j = i;
		while(i < n && v1[j].f == v1[i].f) {
			pr += v1[i].s;
			i++;
		}
		if(pr >= k){
			if(last){
				prev2 = v1[j].f;
			}
			else {
				prev = v1[j].f;
				prev2 = v1[j].f;
			}
			last = 1;
		}
		else {
			if(last){
				v.pb(mp(prev, prev2));
			}
			last = 0;
		}
	}
	if(last) v.pb(mp(prev, prev2));
    cout << v.size() << endl;
    for(pii x: v)
    	printf("%d %d\n", x.f/2, x.s/2);



    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}