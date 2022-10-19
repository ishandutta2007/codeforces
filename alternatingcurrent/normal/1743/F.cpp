#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
const int Mod = 998244353;

int n;
const int A = 300010;
struct mat{
	int dat[2][2];
	mat(int v = 1){
		dat[0][0] = dat[1][1] = v;
		dat[1][0] = dat[0][1] = 0;
	}
	int* operator [](int id){ return dat[id]; }
};
mat operator *(mat a, mat b){
	mat ret;
	ret[0][0] = (1ll * a[0][0] * b[0][0] + 1ll * a[0][1] * b[1][0]) % Mod;
	ret[0][1] = (1ll * a[0][0] * b[0][1] + 1ll * a[0][1] * b[1][1]) % Mod;
	ret[1][0] = (1ll * a[1][0] * b[0][0] + 1ll * a[1][1] * b[1][0]) % Mod;
	ret[1][1] = (1ll * a[1][0] * b[0][1] + 1ll * a[1][1] * b[1][1]) % Mod;
	return ret;
}

namespace segt{
	mat laz[4 * A];
	void pushtag(int k, const mat &val){
		laz[k] = laz[k] * val;
	}
	void pushdown(int k){
		pushtag(k+k, laz[k]);
		pushtag(k+k+1, laz[k]);
		laz[k] = mat(1);
	}
	void update(int tl, int tr, const mat &val, int l, int r, int k){
//		cout << tl << " " << tr << "  " << l << " " << r << " " << k << endl;
		if(tl > r || l > tr)
			return ;
		if(tl <= l && r <= tr){
			pushtag(k, val);
			return ;
		}
		pushdown(k);
		int mid = (l+r) >> 1;
		update(tl, tr, val, l, mid, k+k);
		update(tl, tr, val, mid+1, r, k+k+1);
	}
	mat &query(int pos, int l, int r, int k){
		if(l == r)
			return laz[k];
		pushdown(k);
		int mid = (l+r) >> 1;
		if(pos <= mid)
			return query(pos, l, mid, k+k);
		else
			return query(pos, mid+1, r, k+k+1);
	}
}

mat trans[2];
int main(){
	trans[0][0][0] = 3, trans[0][0][1] = 0;
	trans[0][1][0] = 1, trans[0][1][1] = 2;
	trans[1][0][0] = 1, trans[1][0][1] = 2;
	trans[1][1][0] = 1, trans[1][1][1] = 2;
	ios::sync_with_stdio(false);
	
	cin >> n;
	int l0, r0;
	cin >> l0 >> r0;
	rep(i, n-1){
		int l, r;
		cin >> l >> r;
		segt::update(0, l-1, trans[0], 0, A, 1);
		segt::update(l, r, trans[1], 0, A, 1);
		segt::update(r+1, A, trans[0], 0, A, 1);
		
//		rep(j, 10){
//			mat now = segt::query(j, 0, A, 1);
//			cout << "-------" << j << "---------\n";
//			rep(x, 2){ rep(y, 2) cout << now[x][y] << " "; cout << endl; }
//		}
	}
	
	ll ans = 0;
	rep(i, A+1){
		mat ret = segt::query(i, 0, A, 1);
		ans += (i>=l0 && i<=r0) ? ret[1][1] : ret[0][1];
	}
	
	ans %= Mod;
	cout << ans << endl;
	
	return 0;
}