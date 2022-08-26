#include<bits/stdc++.h>
using namespace std;

#define int long long
const int _ = 5e5 + 3 , __ = _ << 2; int A[3][_] , N , Q; struct pot{int l , r , c;}P[_]; int ans = -1e18;

#define lch (x << 1)
#define rch (x << 1 | 1)
#define mid ((l + r) >> 1)
struct dat{int mxl , mxr , mxv;}tr[_ << 2];
dat operator +(dat p , dat q){dat r; r.mxl = max(p.mxl , q.mxl); r.mxr = max(p.mxr , q.mxr); r.mxv = max(max(p.mxv , q.mxv) , p.mxl + q.mxr); return r;}

void init(int x , int l , int r){
	if(l == r){
		tr[x].mxl = A[0][l] - A[1][l - 1];
		tr[x].mxr = A[1][l] + A[2][N] - A[2][l - 1];
		tr[x].mxv = tr[x].mxl + tr[x].mxr; return;
	}
	init(lch , l , mid); init(rch , mid + 1 , r); tr[x] = tr[lch] + tr[rch];
}

dat qry(int x , int l , int r , int L , int R){
	if(l >= L && r <= R) return tr[x];
	if(mid >= L && mid < R) return qry(lch , l , mid , L , R) + qry(rch , mid + 1 , r , L , R);
	if(mid < L) return qry(rch , mid + 1 , r , L , R);
	return qry(lch , l , mid , L , R);
}

void mdf(int x , int l , int r , int t , int v){
	if(l == r){tr[x].mxl = max(tr[x].mxl , v); tr[x].mxv = tr[x].mxl + tr[x].mxr; return;}
	mid >= t ? mdf(lch , l , mid , t , v) : mdf(rch , mid + 1 , r , t , v); tr[x] = tr[lch] + tr[rch];
}

signed main(){
	ios::sync_with_stdio(0); cin >> N >> Q; for(int i = 0 ; i < 3 ; ++i) for(int j = 1 ; j <= N ; ++j){cin >> A[i][j]; A[i][j] += A[i][j - 1];}
	for(int i = 1 ; i <= Q ; ++i){cin >> P[i].l >> P[i].r >> P[i].c;} sort(P + 1 , P + Q + 1 , [&](pot p , pot q){return p.r < q.r;});
	init(1 , 1 , N);
	for(int i = 1 ; i <= Q ; ++i){dat val = qry(1 , 1 , N , P[i].l , P[i].r); ans = max(ans , val.mxv - P[i].c); if(P[i].r != N) mdf(1 , 1 , N , P[i].r + 1 , val.mxl - P[i].c);}
	cout << ans;
	return 0;
}