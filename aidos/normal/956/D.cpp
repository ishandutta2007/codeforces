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
int n, w;
pii a[200200];
int t[2][4 * 200300];
int sz = 0;
int get(int id, int v, int l, int r, int tl, int tr){
	if(l > tr || r < tl) return 0;
	if(tl <= l && r <= tr) return t[id][v];
	int mid = (l + r)>>1;
	return get(id, v * 2, l, mid, tl, tr) + get(id, v * 2 + 1, mid+1, r, tl, tr);
}
void add(int id, int v, int l, int r, int pos){
	if(l == r){
		t[id][v]++;
	}else{
		int mid = (l + r)>>1;
		if(pos <= mid) add(id, v * 2, l, mid, pos);
		else add(id, v * 2+1, mid+1, r, pos);
		t[id][v] = t[id][v * 2] + t[id][v * 2 + 1];
	}
}
pii getP(int a, int b){
	int g = __gcd(a, b);
	a/=g;
	b/=g;
	return mp(a, b);
}
int cmp(pii a, pii b){
	return a.f * 1ll * b.s < a.s * 1ll * b.f;
}

int findPos(pii c){
	int l = 0, r = sz-1;
	int res = 0;
	while(l <= r){
		int mid = (l + r)>>1;
		if(a[mid] == c) return mid;
		else if(cmp(c, a[mid])){
			r = mid-1;
		}else {
			l = mid+1;
			res = mid;
		}
	}
	return res;
}
ll calc1(vector<pii> d){
	sz = 0;
	sort(all(d));
	for(int i = 0; i < d.size(); i++){
		a[sz++] = getP(d[i].f, d[i].s - w);
		a[sz++] = getP(d[i].f, d[i].s + w);	
	}
	sort(a, a + sz);
	sz = unique(a, a + sz) - a;
	sort(a, a + sz, cmp);
	memset(t, 0, sizeof t);
	ll ans = 0;
	for(int i = 0; i < d.size(); i++){
		ans += i;
		{
			pii c = getP(d[i].f, d[i].s - w);
			int pos = findPos(c);
			ans -= get(0, 1, 0, sz-1, 0, pos-1);
			add(0, 1, 0, sz-1, pos);		
		}
		{
		
			pii c = getP(d[i].f, d[i].s + w);
			int pos = findPos(c);
			ans -= get(1, 1, 0, sz-1, pos+1, sz-1);	
			add(1, 1, 0, sz-1, pos);	
		}
	}
	return ans;
}
ll calc2(vector<pii> d1, vector<pii> d2){
	memset(t, 0, sizeof t);
	sz = 0;
	for(int i = 0; i < d1.size(); i++){
		a[sz++] = getP(d1[i].f, d1[i].s - w);
		a[sz++] = getP(d1[i].f, d1[i].s + w);	
	}
	for(int i = 0; i < d2.size(); i++){
		a[sz++] = getP(d2[i].f, d2[i].s - w);
		a[sz++] = getP(d2[i].f, d2[i].s + w);	
	}
	sort(a, a + sz);
	sz = unique(a, a + sz) - a;
	sort(a, a + sz, cmp);
	ll ans = 0;
	for(int i = 0; i < d1.size(); i++){
		{
			pii c = getP(d1[i].f, d1[i].s - w);
			int pos = findPos(c);
			add(0, 1, 0, sz-1, pos);		
		}
		{
			pii c = getP(d1[i].f, d1[i].s + w);
			int pos = findPos(c);
			add(1, 1, 0, sz-1, pos);		
		}
	}
	for(int i = 0; i < d2.size(); i++){
		ans += d1.size();
		{
			pii c = getP(d2[i].f, d2[i].s + w);
			int pos = findPos(c);
			ans -= get(0, 1, 0, sz-1, 0, pos-1);		
		}
		{
			pii c = getP(d2[i].f, d2[i].s - w);
			int pos = findPos(c);
			ans -= get(1, 1, 0, sz-1, pos+1, sz-1);
			
		}
	}
	return ans;
}
void solve(){
	vector<pii> d1, d2;
	scanf("%d%d", &n, &w);
	for(int i = 0, a, b; i < n; i++){
		scanf("%d%d", &a, &b);
		b = abs(b);
		if(a < 0){
			d1.pb(mp(-a, b));
		}else d2.pb(mp(a, b));		
	}
	ll ans = 0;
	ans += calc1(d1);
	ans += calc1(d2);
	ans += calc2(d1, d2);
	cout << ans << endl;
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