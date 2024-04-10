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

pii a[200200], b[200200];
pii sa[200200], sb[200200];
pii pa[200200], pb[200200];
int n;
pii merge(pii a, pii b){
	return mp(max(a.f, b.f), min(b.s, a.s));
}
void calc(pii *a, pii *p, pii *s){
	p[0] = s[n-1] = mp(-inf, inf);
	for(int i = 1; i < n; i++){
		p[i] = merge(p[i-1], a[i-1]);
	}
	for(int i = n-2; i >= 0; i--){
		s[i] = merge(s[i+1], a[i+1]);
	}
}
void solve(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d%d%d%d", &a[i].f, &b[i].f, &a[i].s, &b[i].s);
	}
	calc(a, pa, sa);
	calc(b, pb, sb);
	for(int i = 0; i < n; i++){
		pii d = merge(pa[i], sa[i]);
		pii e = merge(pb[i], sb[i]);
		if(d.f <= d.s && e.f <= e.s){
			cout << d.f << " " << e.f << "\n";
			return;
		}
	}
}

int main () {

    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}