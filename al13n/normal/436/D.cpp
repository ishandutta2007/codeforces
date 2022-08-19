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

vector<PII> go[110000];

int solve(vector<int> &A,vector<int> &B){
	int n=sz(A);
	int m=sz(B);
	sort(all(A));
	sort(all(B));
	
	vector<int> Al(n),Ar(n);
	Al[0]=0;
	for(int i=1;i<n;++i){
		if(A[i]==A[i-1]+1)
			Al[i]=Al[i-1]+1;
		else
			Al[i]=0;
	}
	Ar[n-1]=0;
	for(int i=n-2;i>=0;--i){
		if(A[i]==A[i+1]-1)
			Ar[i]=Ar[i+1]+1;
		else
			Ar[i]=0;
	}
	
	vector<int> Ai(n);
	vector<int> Bi(m);
	forv(i,B){
		Bi[i]=(int)(lower_bound(all(A),B[i])-A.begin());
	}
	forv(i,A){
		Ai[i]=(int)(lower_bound(all(B),A[i])-B.begin());
	}
	vector<int> on(n+1);
	forv(i,A){
		on[i]=Ai[i]<m && B[Ai[i]]==A[i];
	}
	
	forn(i,n){
		go[i].clear();
	}
	forv(b,B){
		int a=Bi[b];
		if(a==n)
			break;
		if(b+1<m && B[b+1]<=A[a])
			continue;
		for(int bb=b;bb>=0;--bb){
			int aa=a-(A[a]-B[bb]);
			if(aa<0)
				break;
			if(a+Ar[a]==aa-Al[aa])
				continue;
			go[aa-Al[aa]].pb(mp(a+Ar[a],b-bb+1));
		}
	}
	
	vector<int> D(n+1),S(n+1);
	for(int a=n-1;a>=0;--a){
		D[a]=D[a+1];
		S[a]=max(S[a+1]+on[a+1],D[a+1]);
		int b=Ai[a];
		if(b<m && !(a+1<n && A[a+1]<=B[b])){
			for(int bb=b;bb<m;++bb){
				int aa=a+(B[bb]-A[a]);
				if(aa>=n)
					break;
				S[a]=max(S[a],D[aa+Ar[aa]+1]+(bb-b+1)-on[a]);
			}
		}
		forv(i,go[a]){
			int aa=go[a][i].X;
			int d=go[a][i].Y;
			D[a]=max(D[a],S[aa]+d);
		}
		
		D[a]=max(D[a],S[a]+on[a]);
	}
	
	return D[0];
}

void gen(vector<int> &A,vector<int> &B,int lim){
	forv(i,A){
		A[i]=rand()%(lim-sz(A)+1);
	}
	forv(i,B){
		B[i]=rand()%(lim-sz(B)+1);
	}
	sort(all(A));
	sort(all(B));
	forv(i,A){
		A[i]+=i;
	}
	forv(i,B){
		B[i]+=i;
	}
}

vector<int> C;
int ans;

void tryans(vector<int> &B){
	int r=0;
	forv(i,C){
		int t=lower_bound(all(B),C[i])-B.begin();
		if(t<sz(B) && B[t]==C[i])
			++r;
	}
	ans=max(ans,r);
}

void doit(int a,vector<int> &A,vector<int> &B){
	if(a==sz(A)){
		tryans(B);
		return;
	}
	int sz0=sz(C);
	for(int b=a+1;b<=sz(A);++b){
		for(int k=a+1;k<=b;++k){
			if(a==-1 && k>a+1)
				continue;
			if(b==sz(A) && k<b)
				continue;
			if(a>-1 && b<sz(A) && A[k-1]+1==A[k])
				continue;
			forn(i,k-a-1){
				C.pb(A[a]+i+1);
			}
			for(int i=b-k;i>=(b==sz(A)?1:0);--i){
				C.pb(A[b]-i);
			}
			doit(b,A,B);
			C.erase(C.begin()+sz0,C.end());
		}
	}
}

int brute(vector<int> &A,vector<int> &B){
	ans=0;
	C.clear();
	doit(-1,A,B);
	return ans;
}

void stress(){
	for(int s=2;s<=100;++s){
		for(int lim=1;lim<=s;++lim){
			for(int n=1;n<=lim && n+lim<=s;++n){
				int m=s-lim-n;
				if(m<=lim){
					cerr<<lim<<' '<<n<<' '<<m<<endl;
					vector<int> A(n);
					vector<int> B(m);
					forn(qqq,1000){
						gen(A,B,lim);
						int b=brute(A,B);
						int r=solve(A,B);
						if(b!=r){
							cout<<"failed "<<lim<<' '<<n<<' '<<m<<' '<<qqq<<": "<<b<<' '<<r<<endl;
							cout<<n<<' '<<m<<endl;
							forv(i,A){
								cout<<A[i]<<' ';
							}
							cout<<endl;
							forv(i,B){
								cout<<B[i]<<' ';
							}
							return;
						}
					}
				}
			}
		}
	}
	cout<<"passed";
}

int main(){
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen(TASKA".in", "r", stdin); freopen(TASKA".out", "w", stdout);
#endif

	//stress();return 0;

	int n,m;
	cin>>n>>m;
	vector<int> A(n),B(m);
	forn(i,n){
		scanf("%d",&A[i]);
	}
	forn(i,m){
		scanf("%d",&B[i]);
	}
	cout<<solve(A,B);
	
	return 0;
}