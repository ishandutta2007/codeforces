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

// 1-indexed
template<class T>
class BIT {
	T bit[ten(5) * 3];
	int n;

public :
	BIT(){}

	BIT(int N) {
		clear(N);
	}

	void clear(int N){
		n=N;
		memset(bit,0,sizeof(bit));
	}

	T sum(int i) {
		T s=0;
		while (i > 0) {
			s += bit[i];
			i -= i & -i;
		}
		return s;
	}
	T at(int i){
		return sum(i) - sum(i-1);
	}

	void add(int i, T x) {
		while (i <= n) {
			bit[i] += x;
			i += i & -i;
		}
	}
};

BIT<ll> b0,b1;
ll cur_sum(int cur_size){
	ll ans = 0;
	ans += b0.sum(cur_size-1) + b1.sum(cur_size-1) * (cur_size-1);
	return ans;
}

int main(){
	b0.clear(2 * ten(5) + 10);
	b1.clear(2 * ten(5) + 10);
	int cur_size = 2;
	int n; cin>>n;
	FOR(i,n){
		int t; cin>>t;
		if(t == 1){
			int a;
			ll x; cin>>a>>x;
			//b0.add(0, -x * 0);
			b1.add(1,x);
			b0.add(a+1,x*a);
			b1.add(a+1,-x);
		} else if(t == 2){
			int k; cin>>k;
			b0.add(cur_size,k);
			cur_size++;
		} else {
			ll val = cur_sum(cur_size);
			val -= cur_sum(cur_size - 1);
			b0.add(cur_size-1,-val);
			cur_size--;
		}

		//FOR(i,cur_size){
		//	cout << i << " " << cur_sum(i+1) - cur_sum(i) << endl;
		//}

		ll ans = cur_sum(cur_size);
		printf("%.10f\n",ans/(double)(cur_size-1));
	}

	return 0;
}