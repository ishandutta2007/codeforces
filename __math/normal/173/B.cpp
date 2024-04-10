#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
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
#include <stdlib.h>
#include <stdio.h>
#include <numeric>
#include <string.h>
#include <cassert>

#ifdef _DEBUG
#define typeof(X) std::identity<decltype(X)>::type //C++0x (for vs2010)
#else
#define typeof(X) __typeof__(X) // for gcc
#endif

#define sz(a)  int((a).size())
#define FOREACH(it, c) for (typeof((c).begin()) it=(c).begin(); it != (c).end(); ++it)
#define FOR(i,count) for (int i = 0; i < (count); i++)
#define all(c) (c).begin(),(c).end()
#define FILL(c,val) memset((c),val,sizeof(c))

using namespace std;

static const double EPS = 1e-10;
const int MODULO = 1000000007;

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef complex<double> Cd;


//BEGIN!!!
int n,m;
char table[1000][1001];
int ray[2][1000];
queue<Pii> q;

int main(){

	cin>>n>>m;
	FOR(i,n) cin>>table[i];
	FOR(i,n) ray[0][i] = INT_MAX;
	FOR(j,m) ray[1][j] = INT_MAX;
	
	q.push(Pii(0,0)); ray[0][0] = 0;
	
	while(!q.empty()){
		int d = q.front().first,r = q.front().second; q.pop();
		int next = ray[d][r] + 1;
		if(d == 0){
			FOR(i,m){
				if(table[r][i] == '#' && ray[1][i] > next){
					ray[1][i] = next; q.push(Pii(1,i));
				}
			}
		} else {
			FOR(i,n){
				if(table[i][r] == '#' && ray[0][i] > next){
					ray[0][i] = next; q.push(Pii(0,i));
				}
			}
		}
	}

	int ans = ray[0][n-1];
	printf("%d\n",ans == INT_MAX ? -1 : ans);

	return 0;
}