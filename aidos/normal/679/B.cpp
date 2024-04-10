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
ll m;
vector<ll>curr;
ll get(ll x){
	int ind= upper_bound(all(curr), x) - curr.begin();
	return curr[ind-1];
}
bool can(vector<ll> &x, ll cur, ll sum){
	vector<ll> y = x, z;
	while(y.size() >0 && y.back() >= cur){
		z.pb(y.back());
		y.pop_back();
	}
	if(y.size() == 0)return 0;
	z.pb(cur );
	y.pop_back();
	while(y.size() > 0){
		z.pb(y.back());
		y.pop_back();
	}
	sort(all(z));
	ll sumx = 0;
	for(int i = 0; i < z.size(); i++){
		sumx += z[i];
	}
	
	if(sumx > sum) return 0;
	for(int i = (int) (z.size())-1; i >= 0; i--){
		if(get(sumx) != z[i]) return 0;
		sumx -= z[i];
	}
	x = z;
	return 1;
}
void solve(){
	cin >> m;
	ll sum = 0;
	ll cnt= 0;
	vector<ll> g;
	for(int i = 0; i <= 200100; i++){
		curr.pb(i * 1ll * i * 1ll * i);
	}
	for(ll i = 1;  sum + i * 1ll * i * 1ll * i<= m; i++){
		ll j = (i + 1);
		while(sum + i * 1ll * i * 1ll *i < j *1ll * j * 1ll * j && sum + i * 1ll * i * 1ll *i <= m){
			g.pb(i * 1ll * i * 1ll * i);
			sum += i * 1ll * i * 1ll * i;
		}
	}
	cnt = g.size();
	cout <<cnt << " ";
	int ok  = 1;
	for(int i = 100200; ok && i > 0; i--){
		while(can(g, i * 1ll * i * 1ll * i, m)){
	
			//i++;
			//cout << i << " ! " << endl;
		}
	}
	sum = 0;
	for(int i = 0; i < g.size(); i++)
		sum += g[i];
	cout << sum<< endl;
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