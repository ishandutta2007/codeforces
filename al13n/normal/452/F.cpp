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

void gensome(){
	for(int n=1;n<=12;++n){
		cerr<<n<<endl;
		cout<<n<<":"<<endl;
		
		vector<int> P(n);
		forn(i,n){
			P[i]=i;
		}
		map<string,vector<vector<int> > > ss;
		do{
			if(P[0]%2)
				continue;
			bool ok=false;
			forn(j,n){
				forn(i,j){
					int t=P[i]+P[j];
					if(t&1)
						continue;
					t>>=1;
					for(int k=i+1;k<j;++k){
						if(P[k]==t){
							ok=true;
							break;
						}
					}
					if(ok)
						break;
				}
				if(ok)
					break;
			}
			if(!ok){/*
				forv(i,P){
					cout<<P[i]<<' ';
				}
				cout<<endl;//*/
				string s;
				forv(i,P){
					s+=('0'+P[i]%2);
				}
				ss[s].pb(P);
			}
		}while(next_permutation(all(P)));
		
		for(auto it : ss){
			cout<<it.X<<":\n";
			forv(i,it.Y){
				forv(j,it.Y[i]){
					cout<<it.Y[i][j]<<' ';
				}
				cout<<endl;
			}
			cout<<endl;
		}
		cout<<endl<<endl;
	}
}






clock_t t0;

void yup(){
	cout<<"YES";
	exit(0);
}

void tl(){
	static int cnt=0;
	if(cnt%10000==0 && clock()-t0>CLOCKS_PER_SEC*.95)
		yup();
}

int n;
int A[310000];
int T[310000];

bool was[310000];
int ar[310000];

void doit(int a,int b){
	if(b-a<3)
		return;
		
	if(A[a]%2)
		reverse(A+a,A+b);

	memset(was,1,b-a);
	int l=0;
	for(int i=a;i<b;++i){
		tl();
		int x=A[i];
		if(x&1){
			forn(k,l){
				int t=x*2-ar[k];
				if(t>=0 && t<b-a && was[t])
					yup();
				tl();
			}
		}else{
			was[x]=false;
			ar[l++]=x;
			if(l>(b-a+1)/4)
				break;
		}
	}
	
	memset(was,1,b-a);
	l=0;
	for(int i=b-1;i>=a;--i){
		tl();
		int x=A[i];
		if(x&1){
			forn(k,l){
				int t=x*2-ar[k];
				if(t>=0 && t<b-a && was[t])
					yup();
				tl();
			}
		}else{
			was[x]=false;
			ar[l++]=x;
			if(l>(b-a+1)/4)
				break;
		}
	}
	
	memset(was,1,b-a);
	l=0;
	for(int i=a;i<b;++i){
		tl();
		int x=A[i];
		if(x&1){
			was[x]=false;
			ar[l++]=x;
			if(l>(b-a)/4)
				break;
		}else{
			forn(k,l){
				int t=x*2-ar[k];
				if(t>=0 && t<b-a && was[t])
					yup();
				tl();
			}
		}
	}
	
	memset(was,1,b-a);
	l=0;
	for(int i=b-1;i>=a;--i){
		tl();
		int x=A[i];
		if(x&1){
			was[x]=false;
			ar[l++]=x;
			if(l>(b-a)/4)
				break;
		}else{
			forn(k,l){
				int t=x*2-ar[k];
				if(t>=0 && t<b-a && was[t])
					yup();
				tl();
			}
		}
	}
	
	memcpy(T+a,A+a,(b-a)*sizeof(A[0]));
	int p=a;
	for(int i=a;i<b;++i){
		if(T[i]&1){
			A[p++]=T[i]>>1;
		}
	}
	int p0=p;
	for(int i=a;i<b;++i){
		if(!(T[i]&1)){
			A[p++]=T[i]>>1;
		}
	}
	doit(a,p0);
	doit(p0,b);
}

int main(){
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif

	t0=clock();
	ios_base::sync_with_stdio(0);cin.tie(0);

	cin>>n;
	forn(i,n){
		cin>>A[i];
		--A[i];
	}
	
	doit(0,n);
	
	cout<<"NO";

	return 0;
}