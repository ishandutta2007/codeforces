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

typedef vector<vector<ll> > Mat;
Mat mul(const Mat& a, const Mat& b)
{
	int n = a.size();
	Mat c(n, vector<ll>(n));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			for (int k = 0; k < n; ++k)
				(c[i][j] += a[i][k] * b[k][j]) %= MODULO;
	return c;
}
Mat pow(const Mat& _a, ll e)
{
	Mat a = _a;
	int n = a.size();
	Mat res(n, vector<ll>(n));
	for (int i = 0; i < n; ++i)
		res[i][i] = 1;
 
	while (e > 0)
	{
		if (e & 1)
			res = mul(res, a);
		a = mul(a, a);
		e /= 2;
	}
 
	return res;
}

int get_num(char c){
	if('a' <= c && c <= 'z') return c - 'a';
	else return c - 'A' + 26;
}

int main(){
	ll n;
	int m,k;
	cin>>n>>m>>k;

	Mat mat(m,vector<ll>(m+1,1LL));
	mat.push_back(vector<ll>(m+1,0));

	FOR(i,k){
		char c1,c2; scanf(" %c%c",&c1,&c2);
		mat[get_num(c1)][get_num(c2)] = 0;
	}

	Mat ret = pow(mat,n);
	ll ans = 0;
	FOR(i,m){
		ans += ret[i][m];
	}

	cout << ans % MODULO << endl;

	return 0;
}