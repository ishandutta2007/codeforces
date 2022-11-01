#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_DEPRECATE

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cfloat>
#include <ctime>
#include <cassert>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <list>
#include <iomanip>
#include <fstream>
#include <iterator>

using namespace std;
const int MOD = 1000000007; // check!!!
const int INF = 100000000; //1e8

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(x) ((int)1e##x)
#define tenll(x) ((ll)1e##x)

// http://codeforces.com/contest/331/problem/B2
struct P{
	int lpos,rpos,ans;
	P() : lpos(INF) , rpos(INF) , ans(0) {};

};

//0-indexed
//       k
//     /   \
// 2k+1     2k+2
// ke (k-1)/2
// //calc AX\[X
class seg_tree{

public:

	vector<P> dat;
	int n;

	void init(int size){

		n = 1;
		while(n < size) n <<= 1;

		dat.resize(2 * n - 1);
	}

	//k(0-indexed)valXV
	void update(int k,int val){
		k += n-1;

		dat[k].lpos = dat[k].rpos = val;

		while(k > 0){
			k = (k-1)/2;
			dat[k].lpos = dat[2*k+1].lpos;
			dat[k].rpos = dat[2*k+2].rpos;
			dat[k].ans = dat[2*k+1].ans + dat[2*k+2].ans + (dat[2*k+1].rpos > dat[2*k+2].lpos);
		}
	}

	//[a,b)l
	int query(int a,int b)
	{
		return query(a,b,0,0,n);
	}

	//[a,b)l
	// k = _
	// [l,r)k
	int query(int a,int b,int k,int l,int r)
	{
		if(r <= a || b <= l) return -1; //O
		if(a <= l && r <= b) return dat[k].ans; //[l,r)  [a,b)

		//[l,r)[a,b)
		int md = (l + r) / 2; //[l,md),[md,r)
		int nl = k * 2 + 1,nr = nl + 1; //q_
		int lval = query(a,b,nl,l , md);
		int rval = query(a,b,nr,md , r);

		int ret = 0;
		if(lval != -1 && rval != -1){
			ret += (dat[2*k+1].rpos > dat[2*k+2].lpos);
		}
		lval = max(0,lval);
		rval = max(0,rval);

		ret += lval + rval;

		return ret;
	}
};

seg_tree seg;


int a[3 * ten(5) + 1];
int d[3 * ten(5) + 1];


int main(){
	
	int n; cin>>n;
	FOR(i,n){
		cin>>a[i];
		d[a[i]-1] = i;
	}
	
	seg.init(n);

	for(int i = 0; i < n; i++){
		seg.update(i,d[i]);
	}

	int q; cin>>q;
	FOR(i,q){
		int b,x,y; cin>>b>>x>>y;
		if(b == 2){
			x--; y--;
			swap(a[x],a[y]);
			swap(d[a[x] - 1],d[a[y] - 1]);

			seg.update(a[x] - 1,d[a[x] - 1]);
			seg.update(a[y] - 1,d[a[y] - 1]);
		} else {
			x--;

			int ans = seg.query(x,y);
			cout << ans + 1 << endl;
		}
	}

	return 0;
}