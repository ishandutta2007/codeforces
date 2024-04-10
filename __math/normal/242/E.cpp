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
const int MODULO = 1000000007;
const int INF = 100000000; //1e8

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef complex<double> Cd;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())

template<class T>
class seg_tree{

public:

	vector<T> dat;
	vector<char> flg;
	int n;
	T _padding;

	template<class iter>
	void init(iter _First,iter _Last,T padding){
		_padding = padding;
		int dist = distance(_First,_Last);
		n = 1;
		while(n < dist) n <<= 1;

		dat.resize(2 * n - 1);
		flg.resize(2 * n - 1);
		fill(dat.begin(),dat.end(),padding);
		fill(flg.begin(),flg.end(),0);
		copy(_First,_Last,dat.begin() + n - 1);

		for(int i = n / 2; i > 0; i /= 2){
			for(int s = i - 1; s <= 2 * (i - 1); s++){
				dat[s] = dat[s * 2 + 1] + dat[s * 2 + 2];
			}
		}
	}

	int update(int a,int b,int k,int l,int r)
	{
		if(r <= a || b <= l) return dat[k]; //O
		if(a <= l && r <= b){
			flg[k] ^= 1;
			return dat[k] = (r-l) - dat[k];
		} else{

			int md = (l + r) / 2;
			int nl = k * 2 + 1,nr = nl + 1;
			int val = 0;
			val += update(a,b,nl,l , md);
			val += update(a,b,nr,md , r);
			dat[k] = val;
			if(flg[k])
				dat[k] = (r-l) - dat[k];
			return dat[k];
		}
	}

	void update(int a,int b){
		update(a,b,0,0,n);
	}

	int query(int a,int b)
	{
		return query(a,b,0,0,n);
	}

	int query(int a,int b,int k,int l,int r)
	{
		if(r <= a || b <= l) return 0; //O
		if(a <= l && r <= b) return dat[k];

		int md = (l + r) / 2;
		int nl = k * 2 + 1,nr = nl + 1;
		int val = 0;
		val += query(a,b,nl,l , md);
		val += query(a,b,nr,md , r);
		int dist = min(b,r) - max(a,l);
		if (flg[k]) return dist - val;
		else return val;
	}
};

int a[100000];
seg_tree<int> seg[25];

int main(){
	int n; scanf("%d",&n);
	FOR(i,n) scanf("%d",a+i);
	FOR(i,25){
		static int val[100000];
		FOR(j,n) val[j] = (a[j] & (1 << i)) != 0;
		seg[i].init(val,val+n,0);
	}

	int m; scanf("%d",&m);
	while(m--){
		int t; scanf("%d",&t);
		if(t == 1){
			int l,r; scanf("%d%d",&l,&r);
			l--;
			ll val = 0;
			FOR(i,25){
				ll add = seg[i].query(l,r);
				val += add * (1LL << i);
			}
			printf("%I64d\n",val);
		} else{
			int l,r,v; scanf("%d%d%d",&l,&r,&v);
			l--;
			ll val = 0;
			FOR(i,25){
				if(v & (1 << i)){
					seg[i].update(l,r);
				}
			}
		}
	}

	return 0;
}