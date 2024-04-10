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

const int maxn = 1e6 + 6;

int x;
int lp[maxn];
int min_pos;

signed main(){
	sync;
	cin >> x;
	min_pos = x;
	F(i, 0, maxn)lp[i] = 0;
	F(i, 2, maxn){
		if(lp[i] != 0)continue;
		lp[i] = i;
		for(ll j = i * 1ll * i; j < maxn; j += i)if(lp[j] == 0)lp[j] = i;
	}
	int y = x;
	while(y > 1){
		int p = lp[y];
		int mx = max(x - p, p) + 1;
		min_pos = min(min_pos, mx);
		y /= p;	
	}
	int ans = x;
	F(i, min_pos, x + 1){
		int j = i;
		while(j > 1){
			int p = lp[j];
			int mx = max(i - p, p) + 1;
			ans = min(ans, mx);
			j /= p;
		}
	}
	cout << ans;
	ret 0;
}