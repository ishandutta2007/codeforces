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
int k;
int m;
map<ll, vector<int> > M;
ll a[500500], b[500500], c[500500], P[500500];
ll mod = 1000*1000*1000+7;
int p[500500];
ll ans = 0;
int SZ;
void clr(int x){
	p[x] = x;
}

int get(int x){
	if(p[x] == x) return x;
	return p[x] = get(p[x]);
}

void merge(int x, int y){
	x = get(x);
	y =get(y);
	if(x == y) return;
	SZ--;
	p[x] = y;
}
void solve(){
	cin >> n >> m >> k;
	for(int i = 0; i < n; i++){
		scanf("%lld", &c[i]);
		p[i] = i;
	}	
	for(int i = 0; i < m; i++){
		scanf("%lld%lld", &a[i], &b[i]);
		--a[i];
		--b[i];
		ll d = c[a[i]]^c[b[i]];
		M[d].pb(i);
	}
	ll g = (1ll<<k) - M.size();
	P[0] = 1;
	for(int i = 1; i <= n; i++){
		P[i] = P[i-1]*2 % mod;	
	}
	ans = (g%mod * P[n]) % mod;
	forit(it, M){
		SZ = n;
		forit(it2, it->s){
			merge(a[*it2], b[*it2]);
		}
		ans = (ans + P[SZ]) % mod;
		forit(it2, it->s){
			clr(a[*it2]);
			clr(b[*it2]);
		}
	}
	cout << ans << "\n";
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