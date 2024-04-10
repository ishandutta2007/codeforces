#include<bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")

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

int n, bnd;
int a[maxn];
int ptr;

signed main(){
	sync;
	cin >> n >> bnd;
	F(i, 0, n)cin >> a[i];
	ptr = 0;
	ll bp = 0, bq = 1;
	F(i, 0, n){
		while(ptr < n && a[ptr] - a[i] <= bnd)++ptr;
		int j = i + 1;
		int k = ptr - 1;
		if(k <= j)cont;
		ll p = a[k] - a[j], q = a[k] - a[i];
		if(p * bq > q * bp){bp = p; bq = q;}
	}
	if(bp == 0)cout << -1;
	else{
		dbl ans = bp/dbl(bq);
		cout.precision(15);
		cout << fixed << ans;
	}
	ret 0;
}