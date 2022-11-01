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
const int MOD = 1000000009; // check!!!
//const int INF = 100000000; //1e8

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(x) ((int)1e##x)
#define tenll(x) ((ll)1e##x)

int fastMin(int x, int y) { return (((y-x)>>(32-1))&(x^y))^x; }
int fastMax(int x, int y) { return (((y-x)>>(32-1))&(x^y))^y; }

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }


class seg_tree{

public:

	vector<int> dat;
	int n;

	void init(int* d,int size){

		n = 1;
		while(n < size) n <<= 1;

		dat.resize(2 * n - 1);
		fill(dat.begin(),dat.end(),0);

		copy(d,d + size,dat.begin() + n - 1);

		for(int i = n / 2; i > 0; i /= 2){
			for(int s = i - 1; s <= 2 * (i - 1); s++){
				dat[s] = max(dat[s * 2 + 1],dat[s * 2 + 2]); //calc
			}
		}
	}

	//k(0-indexed)valXV
	void update(int k,int val){
		k += n-1;
		dat[k] = val;
		while(k > 0){
			k = (k-1)/2;
			dat[k] = max(dat[k*2+1],dat[k*2+2]); //calc
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
		if(r <= a || b <= l) return 0; //O
		if(a <= l && r <= b) return dat[k]; //[l,r)  [a,b)

		//[l,r)[a,b)
		int md = (l + r) / 2; //[l,md),[md,r)
		int nl = k * 2 + 1,nr = nl + 1; //q_
		int lval = query(a,b,nl,l , md);
		int rval = query(a,b,nr,md , r);

		return max(lval,rval); //calc
	}
};


int a[ten(5)];
int rev_a[ten(5)];
int dummy[ten(5)];

int main(){
	int n; cin>>n;
	FOR(i,n) cin>>a[i];
	FOR(i,n) rev_a[a[i] - 1] = i;

	seg_tree seg;
	seg.init(dummy,n);
	
	int ans = 0;
	FOR(i,n){
		int tmp = seg.query(0,rev_a[i]);
		seg.update(rev_a[i],tmp + 1);
		ans = max(tmp + 1,ans);
	}

	cout << ans << endl;
}