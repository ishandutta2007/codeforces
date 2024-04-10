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
ll a[100100];
ll b[100100];
int nxt[100100*62][2];
int cc;
int sz[100100 * 62];
void add(ll x){
	int cur = 0;
	for(int i = 61; i >= 0; i--){
		int bi = (x>>i)&1;
		if(nxt[cur][bi] == 0){
			nxt[cur][bi] = ++cc;
		}
		sz[cur]++;
		cur = nxt[cur][bi];
	}
	sz[cur]++;
}
void del(ll x){
	int cur = 0;
	for(int i = 61; i >= 0; i--){
		int bi = (x>>i)&1;
		sz[cur]--;
		cur = nxt[cur][bi];
	}
	sz[cur]--;
}
ll calc(int cur, ll x, int eq, int bit){
	if(sz[cur] == 0) return 0;
	if(bit == -1){
		if(eq) return -1;
		return 0;
	}
	int bi = (x>>bit)&1;
	int u1 = nxt[cur][0];
	int u2 = nxt[cur][1];
	if(eq){
		if(bi == 1){
			ll g=-1;
			
			if(u1&&sz[u1] > 0){
				g = calc(u1, x, 1, bit-1);
				if(g != -1) return g;
			}
			
			if(u2 && sz[u2] > 0){
				g = calc(u2, x, 0, bit-1);
				if(g != -1) return (g|(1ll<<bit));
			}
			return g;
		}else{
			ll g=-1;
			if(u1&&sz[u1] > 0){
				g = calc(u1, x, 1, bit-1);
				return g;
			}
			return -1;
		}
	}
	
	if(bi == 1){
		ll g=-1;
		
		if(u1&&sz[u1] > 0){
			g = calc(u1, x, 0, bit-1);
			if(g!=-1)return g;
		}
		
		if(u2 && sz[u2] > 0){
			g = calc(u2, x, 0, bit-1);
			if(g != -1) return (g|(1ll<<bit));
		}
		return g;
	}else{
		
		ll g=-1;
		
		if(u2 && sz[u2] > 0){
			g = calc(u2, x, 0, bit-1);
			if(g != -1) return (g|(1ll<<bit));
		}
		if(u1&&sz[u1] > 0){
			g = calc(u1, x, 0, bit-1);
			if(g != -1) return g;
		}
		return g;
	}
	return -1;
}
void solve(){
	scanf("%d", &n);
	vector<ll> v;
	
	ll cur= 0;
	for(int i = 0; i < n; i++){
		ll x;
		scanf("%lld", &x);
		add(x);
		cur ^= x;
	}
	for(int i = 0; i < n; i++){
		ll d = calc(0, cur, 1, 61);
		if(d == -1){
			cout << "No\n";
			return;
		}
		del(d);
		v.pb(d);
		cur ^= d;
	}
	reverse(all(v));
	cout << "Yes\n";
	forit(it, v){
		printf("%lld ", *it);
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