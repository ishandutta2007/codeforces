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
#include <bits/stdc++.h>

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
vector<pair<int, pii > > v;
vector<int> u;
vector<pii> li1, li2;
bool used[500100];
int cur[500100];
int T = 0;
int n;
ll get2(vector<int> &u, int q){
	ll ans = -((ll) 4e18);
	for(int i = 0; i < u.size(); i++){
		ans = max(ans, v[u[i]].s.f * 1ll * q + v[u[i]].s.s);
	}
	return ans;
}
vector<pii>cc1, cc2;
void add(vector<pii> &cc, pii x){
	int sz = cc.size();
	while(sz > 1 && (cc[sz-2].s-x.s)*1ll * (cc[sz-1].f-cc[sz-2].f)<=(cc[sz-2].s-cc[sz-1].s)*1ll * (x.f-cc[sz-2].f)){
		sz--;
		cc.pop_back();
	}
	cc.pb(x);
}
ll get(vector<pii> &cc, int q){
	int l = 0, r = (int)(cc.size()) - 1;
	while(r - l > 1){
		int mid = (l + r) >> 1;
		if(cc[mid].f * 1ll * q + cc[mid].s > cc[mid-1].f*1ll *q + cc[mid-1].s){
			l = mid;
		}else{
			r = mid;
		}
	}
	ll ans = -(ll) 3e18;
	for(int i = l; i <= r; i++){
		ans=max(ans, cc[i].f * 1ll * q + cc[i].s);
	}
	return ans;
}
int bls = 550;

void erase(vector<int> &u, int ind){
	for(int i = 0; i <u.size(); i++){
		if(u[i] == ind){
			u.erase(u.begin() + i);
			return;
		}
	}
	//assert(false);
}
int index[500500];
int con[500500];
void solve(){
	scanf("%d", &n);
	vector<pii> vx;
	for(int i = 0, type, x, y; i < n; i++){
		scanf("%d%d", &type, &x);
		y = -1;
		if(type == 1) scanf("%d", &y);
		v.pb(mp(type, mp(x, y)));
			vx.pb(mp(x, y));
	}
	sort(all(vx));
	vx.resize(unique(all(vx)) - vx.begin());
	for(int i = 0; i <n; i++){
		if(v[i].f == 1){
			index[i] = lower_bound(all(vx), v[i].s) - vx.begin();
		}
	}
	for(int i = 0; i < n; i++){
		if(i % bls == 0){
			int en = min(i + bls, n);
			++T;
			++T;
			li1.clear();
			li2.clear();
			u.clear();
			cc1.clear();
			cc2.clear();
			for(int j = i; j < en; j++){
				if(v[j].f == 2) cur[v[j].s.f-1] = T;
			}
			for(int j = 0;  j < i; j++){
				if(v[j].f == 1){
					if(used[j]) continue;
					if(cur[j] == T){
						u.pb(j);
					}else {
						con[index[j]] = T;
					}
				}
			}
			for(int j = 0; j < vx.size(); j++){
				if(con[j] == T){
					if(vx[j].f < 0) li1.pb(vx[j]);
					else li2.pb(vx[j]);
				}
			}
			for(int i = 0; i < li1.size(); i++){
				add(cc1, li1[i]);
			}
			for(int i = 0; i < li2.size(); i++){
				add(cc2, li2[i]);
			}

			for(int j = i; j < en; j++){
				if(v[j].f == 1) u.pb(j);
				else if(v[j].f == 2){
					erase(u, v[j].s.f-1);
				}else{
					ll ans = -(ll)3e18;
					bool ok = 0;
					if(li1.size()){
						ok =1;
						ans = max(get(cc1, v[j].s.f), ans);
					}
					if(li2.size()){
						ok =1;
						ans = max(get(cc2, v[j].s.f), ans);
					}
					if(u.size()){
						ans=max(ans, get2(u, v[j].s.f));
						ok = 1;
					}
					if(ok) printf("%I64d\n", ans);
					else printf("EMPTY SET\n");
				}
			}
			for(int j = i; j < en; j++){
				if(v[j].f == 2) used[v[j].s.f-1]=1;
			}
		}
	}
}

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif

    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Test case #%d\n", i);
      solve();
    }


    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}