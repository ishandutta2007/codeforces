#pragma comment(linker, "/STACK:512000000")
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
typedef long double ld;
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
//#define unlink asdunlink
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
const ld EPS = 1e-12;
const int INF = 1000*1000*1000;
const char CINF = 102;
const lng LINF = INF * 1ll * INF;
const ld DINF = 1e200;
const ld PI = 3.1415926535897932384626433832795l;
int gcd(int a,int b){return a?gcd(b%a,a):b;}
lng gcd(lng a,lng b){return a?gcd(b%a,a):b;}
lng powmod(lng a,lng p,lng m){lng r=1;while(p){if(p&1)r=r*a%m;p>>=1;a=a*a%m;}return r;}
#define TASKA "iota"

int M;

struct state{
	int term;
	int sum;
	int go0[21];
	int go[21];
	vector<int> S;
	
	state(){
		clr(go,-1);
		term=sum=0;
	}
};

vector<state> st(1);

void add(vector<int> &s,int term){
	int v=0;
	forv(i,s){
		if(st[v].go[s[i]]==-1){
			st[v].go[s[i]]=sz(st);
			v=sz(st);
			st.pb(state());
			st[v].S=vector<int>(s.begin(),s.begin()+i+1);
		}else
			v=st[v].go[s[i]];
	}
	st[v].term+=term;
}

void mklinks(){
	forv(v,st){
		forn(c,M){
			st[v].go0[c]=st[v].go[c];
		}
	}

	forv(v,st){
		vector<int> s=st[v].S;
		
		for(int k=0;k<=sz(s);++k){
			int p=0;
			for(int i=k;i<sz(s) && p!=-1;++i){
				p=st[p].go0[s[i]];
			}
			if(p==-1)
				continue;
			st[v].sum+=st[p].term;
		}
		
		s.pb(-1);
		for(s.back()=0;s.back()<M;++s.back()){
			for(int k=0;k<=sz(s);++k){
				int p=0;
				for(int i=k;i<sz(s) && p!=-1;++i){
					p=st[p].go0[s[i]];
				}
				if(p==-1)
					continue;
				st[v].go[s.back()]=p;
				break;
			}
		}
	}
}

vector<int> tofu(){
	int a;
	cin>>a;
	vector<int> v(a);
	forn(i,a){
		cin>>v[i];
	}
	return v;
}

const int mod=INF+7;

vector<vector<vector<int> > > dp;
vector<vector<vector<int> > > sdp;
int K;

void dodp(int N){
	dp.resize(N+1,vector<vector<int> >(sz(st),vector<int>(K+1)));
	forv(i,st){
		if(st[i].sum<=K)
			dp[0][i][st[i].sum]=1;
	}
	for(int n=1;n<=N;++n){
		forv(s,st){
			forn(k,K+1){
				int kk=k-st[s].sum;
				if(kk<0)
					continue;
				forn(c,M){
					int ss=st[s].go[c];
					(dp[n][s][k]+=dp[n-1][ss][kk])%=mod;
				}
			}
		}
	}
	sdp=dp;
	forn(n,N){
		forv(s,st){
			for(int k=1;k<=K;++k){
				(sdp[n][s][k]+=sdp[n][s][k-1])%=mod;
			}
		}
	}
}

void add1(vector<int> &v){
	reverse(all(v));
	v.pb(0);
	int i=0;
	while(v[i]==M-1){
		v[i]=0;
		++i;
	}
	++v[i];
	while(v.back()==0){
		v.pop_back();
	}
	reverse(all(v));
}

void debug(vector<int> v,int c,int n,int t){
	forv(i,v){
		cout<<v[i];
	}
	cout<<c;
	forn(i,n){
		cout<<"*";
	}
	cout<<": "<<t<<endl;
}

int solve(vector<int> A){
	int res=0;
	for(int n=1;n<sz(A);++n){
		for(int c=1;c<M;++c){
			int t=sdp[n-1][st[0].go[c]][K];
			(res+=t)%=mod;
			//debug(vector<int>(),c,n-1,t);
		}
	}
	int s=0;
	int k=0;
	forv(i,A){
		k+=st[s].sum;
		if(k>K)
			break;
		for(int c=i?0:1; c<A[i];++c){
			int t=sdp[sz(A)-i-1][st[s].go[c]][K-k];
			(res+=t)%=mod;
			//debug(vector<int>(A.begin(),A.begin()+i),c,sz(A)-i-1,t);
		}
		s=st[s].go[A[i]];
	}
	return res;
}

int main(){
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen(TASKA".in", "r", stdin); freopen(TASKA".out", "w", stdout);
#endif

	int n;
	cin>>n>>M>>K;
	auto L=tofu();
	auto R=tofu();
	forn(i,n){
		auto t=tofu();
		int v;
		cin>>v;
		add(t,v);
	}
	mklinks();
	
	add1(R);
	dodp(sz(R));
	
	int a=solve(L);
	int b=solve(R);
	int ans=(b-a+mod)%mod;
	cout<<ans;
	
	return 0;
}