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
int a[100100];
int ans[100100];
int mod = (int) (1e9) + 7;
int pw[100100];
vector<pii>Q[100100];
int q;
int d[35];
int val[35];
int sz = 0;
int cnt = 0;
int cc = 0;
void add(int x){
	++cc;
	for(int i = 0; i < sz; i++){
		if(x&d[i]){
			x ^= val[i];
		}
	}
	if(x==0){
		cnt++;
		return;
	}
	int j = 0; 
	while((x&(1<<j))==0)j++;
	val[sz] = x;
	d[sz] = (1<<j);
	for(int i = 0; i < sz; i++){
		if(val[i]&d[sz]){
			val[i] ^= val[sz];
		}
	}
	sz++;
}
int get(int x){
	if(x == 0) return pw[cc - sz];
	int dd = 0;
	for(int i = 0; i < sz; i++){
		if(x&d[i]){
			x ^= val[i];
			dd++;
		}
	}
	if(x) return 0;
	return pw[cc-sz];
}
void solve(){
	pw[0] = 1;
	for(int i = 1; i < 100100 - 10; i++) pw[i] = pw[i-1] * 2 % mod;
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	for(int i = 0, l, x; i < q; i++){
		scanf("%d%d", &l, &x);
		Q[l].pb(mp(x, i));
	}
	for(int i = 1; i <= n; ++i){
		add(a[i]);
		forit(it, Q[i]){
			ans[it->s] = get(it->f);
		}
	}
	for(int i = 0; i < q;i++) printf("%d\n", ans[i]);

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