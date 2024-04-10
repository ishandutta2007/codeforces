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
#ifdef ONLINE_JUDGE
#define typeof(X) __typeof(X)
#else
#define typeof(X) decltype(X)
#endif
#define FOREACH(it,c) for(typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define sz(c) ((int)(c).size())

int n,m,h,t;
vector<int> ve[100000];
vector<Pii> e;

bool OK(int l,int r){
	if(sz(ve[l]) <= h || sz(ve[r]) <= t) return false;
	static bool use[100000] = {};
	memset(use,0,sizeof(use));
	int cnt = sz(ve[l]);
	FOR(i,sz(ve[l])) use[ve[l][i]] = true;
	FOR(i,sz(ve[r])) if(!use[ve[r][i]]) cnt++;
	return cnt-2 >= h+t;
}

void print(int l,int r){
	vector<int> head,tail,both;
	FOR(i,sz(ve[l])){
		if(ve[l][i] == r) continue;
		if(find(ve[r].begin(),ve[r].end(),ve[l][i]) != ve[r].end()) both.push_back(ve[l][i]);
		else head.push_back(ve[l][i]);
	}
	FOR(i,sz(ve[r])){
		if(ve[r][i] == l) continue;
		if(find(ve[l].begin(),ve[l].end(),ve[r][i]) != ve[l].end()) continue;
		else tail.push_back(ve[r][i]);
	}
	int cnt = 0;
	while(sz(head) < h) head.push_back(both[cnt++]);
	while(sz(tail) < t) tail.push_back(both[cnt++]);

	puts("YES");
	printf("%d %d\n",l+1,r+1);
	FOR(i,h) printf("%d%c",head[i]+1,i==h-1?'\n':' ');
	FOR(i,t) printf("%d%c",tail[i]+1,i==t-1?'\n':' ');
}

int main(){
	cin>>n>>m>>h>>t;
	FOR(i,m){
		int a,b; cin>>a>>b;
		a--;b--;
		if(sz(ve[a]) < 210) ve[a].push_back(b);
		if(sz(ve[b]) < 210) ve[b].push_back(a);
		e.push_back(Pii(a,b));
	}

	FOR(i,m){
		if(OK(e[i].first,e[i].second)){
			print(e[i].first,e[i].second);
			return 0;
		}
		if(OK(e[i].second,e[i].first)){
			print(e[i].second,e[i].first);
			return 0;
		}
	}

	puts("NO");
    return 0;
}