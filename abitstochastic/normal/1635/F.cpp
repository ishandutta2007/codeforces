#include<bits/stdc++.h>
using namespace std;

#define int long long
const int _ = 3e5 + 7; int N , Q , x[_] , A[_] , ans[_]; vector < pair < int , int > > qry[_];
struct segt{
#define mid ((l + r)>> 1)
#define lch (x<<1)
#define rch (x<<1|1)
	int mn[_ << 2]; segt(){memset(mn , 0x3f , sizeof(mn));}
	void mdf(int x , int l , int r , int t , int v){
		if(l == r){mn[x] = min(mn[x] , v); return;}
		mid >= t ? mdf(lch , l , mid , t , v) : mdf(rch , mid + 1 , r , t , v); mn[x] = min(mn[lch] , mn[rch]);
	}
	int qry(int x , int l , int r , int L , int R){
		if(l >= L && r <= R) return mn[x];
		int v = mn[0]; if(mid >= L) v = qry(lch , l , mid , L , R);
		if(mid < R) v = min(v , qry(rch , mid + 1 , r , L , R));
		return v;
	}
}T1;
int calc(int l , int r){return (x[r] - x[l]) * (A[r] + A[l]);}

signed main(){
	ios::sync_with_stdio(0); cin >> N >> Q; for(int i = 1 ; i <= N ; ++i) cin >> x[i] >> A[i];
	for(int i = 1 ; i <= Q ; ++i){int l , r; cin >> l >> r; qry[r].push_back(make_pair(l , i));}
	vector < int > stk;
	for(int i = 1 ; i <= N ; ++i){
		while(stk.size()){
			T1.mdf(1 , 1 , N , stk.back() , calc(stk.back() , i));
			if(A[stk.back()] >= A[i]) stk.pop_back(); else break;
		}
		stk.push_back(i);
		for(auto t : qry[i]) ans[t.second] = T1.qry(1 , 1 , N , t.first , N);
	}
	for(int i = 1 ; i <= Q ; ++i) cout << ans[i] << '\n';
	return 0;
}