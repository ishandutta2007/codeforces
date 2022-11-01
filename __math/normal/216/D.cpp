#define _USE_MATH_DEFINES
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
#include <ctime>

using namespace std;
typedef long long ll;
const int MODULO = 1000000007;
const int INF = 100000000; //1e8

using namespace std;

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef complex<double> Cd;

//BEGIN!!!

#define FOR(i,n) for(int i = 0 ;i < (n); i++)


vector<int> e[1000];


void web_num(vector<int>& dest,vector<int>& cen,vector<int>& out){
	dest.resize((int)cen.size() - 1);
	int o = 0;
	while(o < out.size() && out[o] <= cen[0]){
		o++;
	}
	int d = 0;
	while(o < out.size() && d < dest.size()){
		int cnt = 0;
		while(o + cnt < out.size() && out[o + cnt] < cen[d+1])
			cnt++;
		dest[d++] = cnt;
		o += cnt;
	}

}

int main()
{
	int n; cin>>n;
	FOR(i,n){
		int m; cin>>m;
		e[i].resize(m);
		FOR(j,m) cin>>e[i][j];
		sort(e[i].begin(),e[i].end());
	}

	int ans = 0;

	FOR(i,n){
		int l = (i-1+n) % n,r = (i+1) % n;
		vector<int> lw,rw;
		web_num(lw,e[i],e[l]);
		web_num(rw,e[i],e[r]);

		FOR(j,lw.size())
			if(lw[j] != rw[j])
				ans++;
	}

	cout << ans << endl;

	return 0;
}