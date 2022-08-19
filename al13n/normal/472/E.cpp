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
//typedef pair<short, short> PSS;
typedef pair<string, string> PSS;
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
#define FAIL { cerr<<"assertion failed on line "<<__LINE__<<endl; exit(123);}

int n,m;
vector<vector<int> > A,G;
vector<PII> ans;
int a,b;

void nope(){
	cout<<-1;
	exit(0);
}

void go(int aa,int bb){
	if(mp(aa,bb)==mp(a,b) || abs(a-aa)>1 || abs(b-bb)>1 || aa<0 || bb<0 || aa>=n || bb>=m)
		FAIL;
	swap(A[aa][bb],A[a][b]);
	a=aa;
	b=bb;
	ans.pb(mp(a,b));
}

void trans(){
	swap(n,m);
	vector<vector<int> > AA(n,vector<int>(m)),GG;
	GG=AA;
	forn(i,n){
		forn(j,m){
			AA[i][j]=A[j][i];
			GG[i][j]=G[j][i];
		}
	}
	forv(i,ans){
		swap(ans[i].X,ans[i].Y);
	}
	A=AA;
	G=GG;
}

void solve(){
	if(n==1 || m==1){
		bool tra=false;
		if(n>1){
			trans();
			tra=true;
		}
		
		bool f=false;
		forn(x,m){
			if(f)
				break;
			forn(y,m){
				if(f)
					break;
				if(x==y)
					continue;
				vector<int> T=A[0];
				if(y>x)
					rotate(T.begin()+x,T.begin()+x+1,T.begin()+y+1);
				else
					rotate(T.begin()+y,T.begin()+x,T.begin()+x+1);
				if(T==G[0]){
					f=true;
					a=0;
					b=x;
					ans.pb(mp(a,b));
					while(b>y)
						go(a,b-1);
					while(b<y)
						go(a,b+1);
				}
			}
		}
		
		if(!f)nope();
		
		if(tra)
			trans();
	}else{
		a=-1;
		for(int i=0;i<n&&a==-1;++i){
			for(int j=0;j<m&&a==-1;++j){
				if(A[i][j]==G[n-1][m-1])
					a=i,b=j;
			}
		}
		if(a==-1)
			FAIL;
		ans.pb(mp(a,b));
		
		for(int r=0;r<n-2;++r){
			for(int c=0;c<m;++c){
				while(b<c)
					go(a,b+1);
				while(b>c)
					go(a,b-1);
				while(a>r)
					go(a-1,b);
				if(a<r)
					FAIL;
				
				int aa=-1,bb=-1;
				for(int i=r;i<n && aa==-1;++i){
					for(int j=(i==r?c+1:0);j<m && aa==-1;++j){
						if(G[r][c]==A[i][j])
							aa=i,bb=j;
					}
				}
				if(aa==-1)
					FAIL;
				
				vector<PII> tr;
				if(bb>=c && c+1<m){
					go(a,b+1);
					if(aa==r)
						++aa;
					if(bb==c)
						++bb;
					for(int j=c+2;j<=bb;++j)
						tr.pb(mp(r,j));
					for(int i=r+1;i<=aa;++i)
						tr.pb(mp(i,bb));
					for(int j=bb-1;j>=c;--j)
						tr.pb(mp(aa,j));
					for(int i=aa-1;i>=r;--i)
						tr.pb(mp(i,c));
					tr.pb(mp(r,c+1));
				}else{
					go(a+1,b-1);
					if(aa==r+1)
						++aa;
					if(bb==c)
						--bb;
					for(int j=c-2;j>=bb;--j)
						tr.pb(mp(r+1,j));
					for(int i=r+2;i<=aa;++i)
						tr.pb(mp(i,bb));
					for(int j=bb+1;j<=c;++j)
						tr.pb(mp(aa,j));
					for(int i=aa-1;i>=r;--i)
						tr.pb(mp(i,c));
					tr.pb(mp(r+1,c-1));
				}
				
				int it=0;
				while(A[r][c]!=G[r][c]){
					if(it++>200)
						FAIL;
					forv(i,tr){
						go(tr[i].X,tr[i].Y);
					}
				}
			}
		}
		
		for(int c=0;c<m-1;++c){
			for(int r=n-2;r<n;++r){
				while(a<r)
					go(a+1,b);
				while(a>r)
					go(a-1,b);
				while(b>c)
					go(a,b-1);
				if(b<c)
					FAIL;
				
				go(n-2,c+1);
				
				vector<PII> tr;
				for(int j=c+2;j<m;++j)
					tr.pb(mp(n-2,j));
				tr.pb(mp(n-1,m-1));
				for(int j=m-2;j>=c;--j)
					tr.pb(mp(n-1,j));
				if(r==n-2)
					tr.pb(mp(n-2,c));
				tr.pb(mp(n-2,c+1));
				
				int it=0;
				while(A[r][c]!=G[r][c]){
					if(mp(a,b)!=mp(n-2,c+1))
						FAIL;
					if(it++>200)
						FAIL;
					forv(i,tr){
						go(tr[i].X,tr[i].Y);
					}
				}
			}
		}
		
		if(a!=n-1)
			go(n-1,m-1);
	}
	
	forn(i,n){
		forn(j,m){
			if(A[i][j]!=G[i][j])
				FAIL;
		}
	}
}

void stress(){
	for(n=2;n<=10;++n){
		for(m=2;m<=10;++m){
			cerr<<n<<' '<<m<<endl;
			forn(it,1000){
				ans.clear();
				A.clear();
				A.resize(n,vector<int>(m));
				G=A;
				vector<int> P1(n*m),P2(n*m);
				forn(i,n*m){
					P1[i]=P2[i]=i;
				}
				random_shuffle(all(P1));
				random_shuffle(all(P2));
				forn(i,n){
					forn(j,m){
						A[i][j]=P1[i*m+j];
						G[i][j]=P2[i*m+j];
					}
				}
				
				solve();
			}
		}
	}
}

int main(){
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false);cin.tie(0);
	
	//stress();return 0;

	cin>>n>>m;
	A.resize(n,vector<int>(m));
	G=A;
	multiset<int> As,Gs;
	forn(i,n){
		forn(j,m){
			cin>>A[i][j];
			As.insert(A[i][j]);
		}
	}
	forn(i,n){
		forn(j,m){
			cin>>G[i][j];
			Gs.insert(G[i][j]);
		}
	}
	
	if(As!=Gs)
		nope();
		
	solve();
	
	cout<<sz(ans)-1<<endl;
	forv(i,ans){
		cout<<ans[i].X+1<<' '<<ans[i].Y+1<<'\n';
	}

	return 0;
}