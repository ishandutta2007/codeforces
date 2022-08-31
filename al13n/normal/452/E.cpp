#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_DEFINES
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <climits>
#include <ctime>
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
typedef long long lng;
typedef unsigned long long ulng;
typedef unsigned int uint;
typedef unsigned char uchar;
typedef double ld;
typedef pair<int, int> PII;
typedef pair<short, short> PSS;
typedef pair<PII, int> PIII;
typedef pair<lng, lng> PLL;
typedef pair<ulng, ulng> PUU;
typedef pair<lng, int> PLI;
typedef pair<int, lng> PIL;
typedef pair<ld, ld> PDD;
template<class T> inline T sqr(T x) { return x * x; }
template<class T> inline string tostr(const T & x) { stringstream ss; ss << x; return ss.str(); }
inline lng parse(const string & s) { stringstream ss(s); lng x; ss >> x; return x; }
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
#define hash asdhash
#define move asdmove
const ld EPS = 1e-9;
const int INF = 1000*1000*1000;
const char CINF = 102;
const lng LINF = INF * 1ll * INF;
const ld DINF = 1e200;
const ld PI = 3.1415926535897932384626433832795l;
int gcd(int a,int b){return a?gcd(b%a,a):b;}
lng gcd(lng a,lng b){return a?gcd(b%a,a):b;}
lng powmod(lng a,lng p,lng m){lng r=1;while(p){if(p&1)r=r*a%m;p>>=1;a=a*a%m;}return r;}
#define fail(msg) { cerr<<msg<<endl; cout<<msg<<endl; exit((__LINE__-1) % 200 + 1);}

struct automaton {
	struct state {
		int len = 0;
		int link = -1;
		int next[27];
		bool term = false;
		
		int M = -1;
		int D[3] = {0, 0, 0};
		
		state() {
			clr(next, -1);
		}
	};
	
	vector<state> st=vector<state>(1);
	int last = 0;
	
	automaton() {}
	
	automaton(const string &s){
		forv(i,s){
			extend(s[i]);
		}
		terms();
	}
	
	void extend(char c) {
		c -= 'a';
		int cur = sz(st);
		st.pb(state());
		st[cur].len = st[last].len + 1;
		int p;
		for (p = last; p != -1 && st[p].next[c] == -1; p = st[p].link)
			st[p].next[c] = cur;
		if (p == -1)
			st[cur].link = 0;
		else {
			int q = st[p].next[c];
			if (st[p].len + 1 == st[q].len)
				st[cur].link = q;
			else {
				int clone = sz(st);
				st.pb(state());
				st[clone].len = st[p].len + 1;
				memcpy(st[clone].next, st[q].next, sizeof(st[clone].next));
				st[clone].link = st[q].link;
				for (; p!=-1 && st[p].next[c] == q; p = st[p].link)
					st[p].next[c] = clone;
				st[q].link = st[cur].link = clone;
			}
		}
		last = cur;
	}
	
	void terms() {
		for(int v = last; v != -1; v = st[v].link)
			st[v].term = true;
	}
	
	void dfs(int v){
		if(st[v].M!=-1)
			return;
		if(st[v].term){
			st[v].M=0;
			st[v].D[0]=1;
		}
		forn(i,27){
			int t=st[v].next[i];
			if(t==-1)
				continue;
			dfs(t);
			st[v].M=max(st[v].M,st[t].M+1);
			if(i==26){
				for(int j=1;j<3;++j){
					st[v].D[j]+=st[t].D[j-1];
				}
			}else{
				forn(j,3){
					st[v].D[j]+=st[t].D[j];
				}
			}
		}
	}
	
	void MD(){
		forv(i,st){
			dfs(i);
		}
	}
};

int main(){
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(0);cin.tie(0);

	string S[3];
	forn(i,3){
		cin>>S[i];
	}
	string s=S[0]+'{'+S[1]+'{'+S[2];
	automaton A(s);
	A.MD();
	
	const lng mod=INF+7;
	
	int L=min(min(sz(S[0]),sz(S[1])),sz(S[2]));
	vector<lng> add(L+2);
	
	for(int i=1;i<sz(A.st);++i){
		const auto &st=A.st[i];
		lng x=1ll*st.D[0]*st.D[1]%mod*st.D[2]%mod;
		if(!x)
			continue;

		int b=st.len;
		int a=A.st[st.link].len+1;
		int p=sz(s)-st.M;
		int ps=-1;
		if(sz(S[0])<p)
			ps=sz(S[0]);
		if(sz(S[0])+1+sz(S[1])<p)
			ps=sz(S[0])+1+sz(S[1]);
		b=min(b,p-ps-1);
		b=min(b,L);
		if(b<a)
			continue;
		++b;
		(add[a]+=x)%=mod;
		(add[b]+=mod-x)%=mod;
	}
	
	lng r=0;
	forv(i,add){
		(r+=add[i])%=mod;
		if(i>=1 && i<=L)
			cout<<r<<' ';
	}
	
	return 0;
}