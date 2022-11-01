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

vector<int> e[100000];
vector<int> ans;
int b[100000];
int n,m,k;

void dfs(int id){
	b[id] = sz(ans);
	ans.push_back(id);

	FOR(i,sz(e[id])){
		int nxt = e[id][i];

		if(b[nxt] == -1){
			dfs(nxt);
			return ;
		} else if(sz(ans) - b[nxt] >= k + 1){
			vector<int> tmp(ans.begin() + b[nxt],ans.end());
			ans = tmp;
			return ;
		}
	}
}

int main(){
	memset(b,-1,sizeof(b));
	cin>>n>>m>>k;

	FOR(i,m){
		int x,y; cin>>x>>y;
		x--;y--;
		e[x].push_back(y);
		e[y].push_back(x);
	}

	dfs(0);

	printf("%d\n",sz(ans));
	FOR(i,sz(ans)){
		printf("%d%c",ans[i] + 1,i == n-1?'\n':' ');
	}

	return 0;
}