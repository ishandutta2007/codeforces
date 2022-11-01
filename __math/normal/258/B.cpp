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

int m;

vector<int> digits(int x){
	vector<int> ret;
	while(x){
		int a = x % 10;
		ret.push_back(a);
		x /= 10;
	}
	return ret;
}


ll cnt[11];

void digit_dp(){
	vector<int> a = digits(m);

	ll ls[22][10] ={} , eq[22][10] = {}, gt[22][10] = {};
    eq[0][0] = 1;
    FOR(i, sz(a)) FOR(j, 10)
    {
        FOR(d, 10)
        {
            int nj = j + (d == 4 || d == 7);
            if (d > a[i])
            {
                gt[i + 1][nj] += ls[i][j] + eq[i][j] + gt[i][j];
            }
            else if (d < a[i])
            {
                ls[i + 1][nj] += ls[i][j] + eq[i][j] + gt[i][j];
            }
            else
            {
                ls[i + 1][nj] += ls[i][j];
                eq[i + 1][nj] += eq[i][j];
                gt[i + 1][nj] += gt[i][j];
            }
        }
    }
    --ls[a.size()][0];

	FOR(i,11) cnt[i] += ls[sz(a)][i] + eq[sz(a)][i];
	FOR(i,11) cnt[i] %= MODULO;

}

ll calc_sum(ll sum_val,int depth){
	static int sum[7] = {};
	ll ret = 0;
	if(depth == 7){
		int sums = sum[6] - accumulate(sum,sum+6,0);
		if(sums > 0){
			ret = sum_val % MODULO;
		}
	} else {
		for(int i = 0; i < 11; i++){
			ll val = cnt[i];
			if(val > 0){
				cnt[i]--;
				sum[depth] = i;
				ret += calc_sum(sum_val * val % MODULO,depth + 1);
				cnt[i]++;
			}
		}
	}
	return ret % MODULO;
}

int solve(){
	digit_dp();

	ll ans = calc_sum(1,0);

	return ans % MODULO;
}


int main(){
	cin>>m;

	int ans = solve();

	cout << ans << endl;

    return 0;
}