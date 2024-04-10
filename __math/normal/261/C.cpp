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


ll cnt[60];

vector<int> digits(ll m){
	vector<int> ret;
	while(m){
		ret.push_back(m&1);
		m>>=1;
	}
	return ret;
}

void digit_dp(ll m){
	vector<int> a = digits(m);

	// vZl
	ll lseq[60][60] ={} , gt[60][60] = {};
    lseq[0][0] = 1;
    FOR(i, sz(a)) FOR(j, 59)
    {
        FOR(d, 2)
        {
            int nj = j + (d == 1);
            if (d > a[i])
            {
                gt[i + 1][nj] += lseq[i][j] + gt[i][j];
            }
            else if (d < a[i])
            {
                lseq[i + 1][nj] += lseq[i][j] + gt[i][j];
            }
            else
            {
                lseq[i + 1][nj] += lseq[i][j];
                gt[i + 1][nj] += gt[i][j];
            }
        }
    }
    --lseq[a.size()][0]; // 0
    --lseq[a.size()][1]; // 1

	memset(cnt,0,sizeof(cnt));
	FOR(i,60) cnt[i] += lseq[sz(a)][i];

	//FOR(i,60) printf("%d ",cnt[i]);
	//puts("");

}


int main(){
	ll n,t;
	while(cin>>n>>t){
		ll c = 1,m = 1;
		while(t > c) c <<= 1,m++;
		if(t != c){
			puts("0");
			break;
		}

		digit_dp(n + 1);

		cout << cnt[m] << endl;
	}
	return 0;
}