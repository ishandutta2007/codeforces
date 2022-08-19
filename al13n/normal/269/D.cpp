#pragma comment(linker, "/STACK:256000000")
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <climits>
#include <numeric>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <complex>
#include <deque>
#include <functional>
#include <list>
#include <map>
#include <string>
#include <sstream>
#include <set>
#include <stack>
#include <queue>
using namespace std;
template<class T> inline T sqr(T x) { return x * x; }
template<class T> inline string tostr(const T & x) { stringstream ss; ss << x; return ss.str(); }
typedef long long lng;
typedef unsigned long long ulng;
typedef double ld;
typedef pair<int, int> PII;
typedef pair<lng, lng> PLL;
typedef pair<lng, int> PLI;
typedef pair<ld, ld> PDD;
#define left asdleft
#define right asdright
#define link asdlink
#define unlink asdunlink
#define next asdnext
#define prev asdprev
#define y0 asdy0
#define y1 asdy1
#define mp make_pair
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define clr(ar,val) memset(ar, val, sizeof(ar))
#define istr stringstream
#define forn(i,n) for(int i=0;i<(n);++i)
#define forv(i,v) forn(i,sz(v))
#define X first
#define Y second
const double EPS = 1e-9;
const int INF = 1000*1000*1000;
const lng LINF = INF * 1ll * INF;
const ld PI = 3.1415926535897932384626433832795;

pair<int,PII> src[110000];
vector<int> gr[110000];
vector<int> agr[110000];
int dp[110000];
int n,T;

int doit(int v){
	if(dp[v]!=-1)
		return dp[v];
	int r=0;
	forv(i,gr[v]){
		int p=gr[v][i];
		r=max(r,min(doit(p),min(src[v].Y.Y,src[p].Y.Y)-max(src[v].Y.X,src[p].Y.X)));
	}
	return dp[v]=r;
}

int main() {
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	
	clr(dp,-1);
	cin>>n>>T;
	forn(i,n){
		cin>>src[i].X>>src[i].Y.X>>src[i].Y.Y;
	}
	src[n++]=mp(0,mp(-INF,INF));
	src[n++]=mp(T,mp(-INF,INF));
	sort(src,src+n);
	vector<PII> evs;
	forn(i,n){
		evs.pb(mp(src[i].Y.X,i));
		evs.pb(mp(src[i].Y.Y,~i));
	}
	sort(all(evs));
	set<PII> st;
	forv(i,evs){
		int v=evs[i].Y;
		if(v<0){
			v=~v;
			set<PII>::iterator it=st.lower_bound(mp(src[v].X,v));
			set<PII>::iterator it2=it;
			if(it!=st.begin()){
				--it;
				gr[v].pb(it->Y);
				gr[it->Y].pb(v);
				++it;
			}
			++it;
			if(it!=st.end()){
				gr[v].pb(it->Y);
				gr[it->Y].pb(v);
			}
			st.erase(it2);
			it2=it;
			if(it2!=st.begin() && it!=st.end()){
				--it2;
				agr[it->Y].pb(it2->Y);
				agr[it2->Y].pb(it->Y);
			}
		}else{
			set<PII>::iterator it=st.lower_bound(mp(src[v].X,v));
			if(it!=st.begin() && it!=st.end()){
				set<PII>::iterator it2=it;
				--it;
				agr[it2->Y].pb(it->Y);
				agr[it->Y].pb(it2->Y);
				++it;
			}
			if(it!=st.end()){
				gr[v].pb(it->Y);
				gr[it->Y].pb(v);
			}
			it=st.insert(mp(src[v].X,v)).X;
			if(it!=st.begin()){
				--it;
				gr[v].pb(it->Y);
				gr[it->Y].pb(v);
			}
		}
	}
	
	forn(v,n){
		sort(all(agr[v]));
		vector<int> tv=gr[v];
		sort(all(tv));
		tv.erase(unique(all(tv)),tv.end());
		gr[v].clear();
		forv(i,tv){
			int p=tv[i];
			int t=lower_bound(all(agr[v]),p)-agr[v].begin();
			if((t==sz(agr[v]) || agr[v][t]!=p) && src[p].X>src[v].X)
				gr[v].pb(p);
		}
	}
	
	dp[n-1]=INF*2;
	cout<<doit(0);
	
	return 0;
}