#include<bits/stdc++.h>

//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair<int, int> pii;

#define F(i, l, r) for(int i = (l); i < (r); i++)
#define DF(i, l, r) for(int i = (l); i >= (r); i--)
#define I(x, a) for(auto x : (a))
#define mp make_pair
#define X first
#define Y second
#define clean(x) memset((x), 0, sizeof(x))
#define ret return
#define cont continue
#define brk break
#define ins insert
#define all(x) (x).begin(),(x).end()
#define sync ios_base::sync_with_stdio(false);cin.tie(0)
#define pb push_back
#define y1 fjfg

const int maxn = 1e5 + 5;

int v[maxn];
int t[maxn];
ll ans[maxn];
int add[maxn];
ll pref[maxn];
ll ex[maxn];
int n;

signed main(){
	sync;
	cin >> n;
	F(i, 0, n)cin >> v[i];
	F(i, 0, n)cin >> t[i];
	F(i, 0, n){
		pref[i] = (i == 0) ? 0 : pref[i - 1];
		pref[i] += t[i];
	}
	F(i, 0, n){
		ll dcp = (i == 0) ? 0 : pref[i - 1];
		int l = i, r = n - 1;
		if(pref[r] - dcp < v[i]){
			add[i]++;
			continue;
		}
		while(r - l > 1){
			int mid = (l + r)/2;
			ll val = pref[mid] - dcp;
			if(val >= v[i])r = mid;
			else l = mid + 1;
		}
		if(pref[l] - dcp >= v[i])r = l;
		add[i]++;
		add[r]--;
		ll rax = (r == 0) ? 0 : pref[r - 1];
		ex[r] += min((ll)t[r], v[i] - (rax - dcp));
	}
	ll bal = 0;
	F(i, 0, n){
		bal += add[i];
		ans[i] = ex[i] + bal * 1ll * t[i];
	}
	F(i, 0, n)cout << ans[i] << ' ';
	ret 0;
}