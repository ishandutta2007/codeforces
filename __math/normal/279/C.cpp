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


using namespace std;
typedef long long ll;
const unsigned int MODULO = 1000000007;
const int INF = 100000000; //1e8

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef complex<double> Cd;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(n) ((int)1e##n)

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

enum F{ EQ,LESS,GRATE,LADDER,INVAL};

class seg_tree{

public:

	vector<int> mx;
	int n;

	F conbi_flag(int l,int r){
		int val = -1;
		if(l == INVAL || r == INVAL){
			val = INVAL;
		} else {
			if(l == EQ){
				if(r == EQ) val = EQ;
				else if(r == LESS) val = LESS;
				else if(r == GRATE) val = GRATE;
				else if(r == LADDER) val = LADDER;
			} else if(l == LESS){
				if(r == EQ) val = LESS;
				else if(r == LESS) val = LESS;
				else if(r == GRATE) val = LADDER;
				else if(r == LADDER) val = LADDER;
			} else if(l == GRATE){
				if(r == EQ) val = GRATE;
				else if(r == LESS) val = INVAL;
				else if(r == GRATE) val = GRATE;
				else if(r == LADDER) val = INVAL;
			} else if(l == LADDER){
				if(r == EQ) val = LADDER;
				else if(r == LESS) val = INVAL;
				else if(r == GRATE) val = LADDER;
				else if(r == LADDER) val = INVAL;
			}
		}
		return (F)val;
	}

	void init(vector<int>& d){
		n = 1;
		while(n < sz(d)) n <<= 1;

		vector<int> dat(n+1);
		FOR(i,sz(dat)) dat[i] = d[sz(d)-1];
		copy(d.begin(),d.end(),dat.begin());

		mx.resize(2*n-1);

		for(int i = n-1,j = 0; i < 2*n-1; i++,j++){
			int diff = dat[j+1] - dat[j];
			if(diff == 0) mx[i] = EQ;
			else if(diff > 0) mx[i] = LESS;
			else mx[i] = GRATE;
		}

		for(int i = n / 2; i > 0; i /= 2){
			for(int s = i - 1; s <= 2 * (i - 1); s++){
				int l = mx[s * 2 + 1];
				int r = mx[s * 2 + 2];
				mx[s] = conbi_flag(l,r);
			}
		}
	}


	F query(int a,int b)
	{
		return query(a,b,0,0,n);
	}

	F query(int a,int b,int k,int l,int r)
	{
		if(r <= a || b <= l) return EQ; //O
		if(a <= l && r <= b) return (F)mx[k];

		int md = (l + r) / 2;
		int nl = k * 2 + 1,nr = nl + 1;
		F l_flg = query(a,b,nl,l , md);
		F r_flg = query(a,b,nr,md , r);
		return conbi_flag(l_flg,r_flg);
	}
};


int main(){
	int n,m; cin>>n>>m;
	vector<int> a(n);
	FOR(i,n) cin>>a[i];

	seg_tree seg;
	seg.init(a);

	FOR(i,m){
		int l,r; cin>>l>>r;
		l--; r--;
		F ans = seg.query(l,r);
		if(ans != INVAL){
			puts("Yes");
		} else {
			puts("No");
		}
	}

	return 0;
}