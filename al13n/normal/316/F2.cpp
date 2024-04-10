#pragma comment(linker, "/STACK:512000000")
#define _CRT_SECURE_NO_DEPRECATE
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
template<class T> inline T sqr(T x) { return x * x; }
template<class T> inline string tostr(const T & x) { stringstream ss; ss << x; return ss.str(); }
typedef long long lng;
typedef unsigned long long ulng;
typedef unsigned int uint;
typedef unsigned char uchar;
typedef double ld;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;
typedef pair<int, lng> PLL;
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
#define hash asdhash
#define move asdmove
#define pow10 asdpow10
const double EPS = 1e-6;
const int INF = 1000*1000*1000;
const char CINF = 102;
const lng LINF = INF * 1ll * INF;
const ld PI = 3.1415926535897932384626433832795;
lng gcd(lng a,lng b){return a?gcd(b%a,a):b;}
uint gcd(uint a,uint b){return a?gcd(b%a,a):b;}

int n,m;
const int B=50;

struct image{
	bool a[1700][1700];
};

struct comps{
	int a[1700][1700];
};

void filter(const image &src,image &dst,int W,bool grow){
	if(grow){
		clr(dst.a,0);
		forn(i,n){
			forn(j,m){
				if(!src.a[i][j])
					continue;
				for(int di=-W;di<=W;++di){
					int ii=i+di;
					int t=(int)sqrt((double)(W*W-di*di));
					for(int dj=-t;dj<=t;++dj){
						int jj=j+dj;
						dst.a[ii+B][jj+B]=true;
					}
				}
			}
		}
		forn(i,n){
			forn(j,m){
				dst.a[i][j]=dst.a[i+B][j+B];
			}
		}
	}else{
		forn(i,n){
			forn(j,m){
				bool b=true;
				for(int di=-W;di<=W;++di){
					int ii=i+di;
					int t=(int)sqrt((double)(W*W-di*di));
					for(int dj=-t;dj<=t;++dj){
						int jj=j+dj;
						bool v=src.a[ii][jj];
						b&=v;
						if(!b)
							break;
					}
					if(!b)
						break;
				}
				dst.a[i][j]=b;
			}
		}
	}
}

void subtract(const image &a,const image &b,image &dst){
	forn(i,n){
		forn(j,m){
			dst.a[i][j]=a.a[i][j]&&!b.a[i][j];
		}
	}
}

void fill(image &a,comps &c,int x,int i,int j){
	if(i<0||j<0||i>=n||j>=m||!a.a[i][j])
		return;
	a.a[i][j]=false;
	c.a[i][j]=x;
	fill(a,c,x,i,j-1);
	fill(a,c,x,i,j+1);
	fill(a,c,x,i-1,j);
	fill(a,c,x,i+1,j);
}

int getcomps(image &a,comps &c){
	int k=0;
	forn(i,n){
		forn(j,m){
			if(!a.a[i][j])
				continue;
			fill(a,c,++k,i,j);
		}
	}
	return k;
}

void save(const image &a,string file){
	ofstream f(file.c_str());
	f<<"P2\n"<<m<<' '<<n<<" 1\n";
	forn(i,n){
		forn(j,m){
			f<<a.a[i][j]<<'\n';
		}
	}
}

int main() {
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	freopen("11.in.txt", "r", stdin);
#endif
	
	static image src,tmp;
	cin>>n>>m;
	forn(i,n){
		forn(j,m){
			int a;
			scanf("%d",&a);
			src.a[i][j]=!!a;
		}
	}
	
	tmp=src;
	filter(tmp,src,1,false);
	
	static image core,big,rays;
	filter(src,core,4,false);
	filter(core,big,7,true);
	subtract(src,big,rays);
	
	//save(src,"src.pgm");
	//save(core,"core.pgm");
	//save(big,"big.pgm");
	//save(rays,"rays.pgm");
	
	static comps sunid,rayid;
	int k=getcomps(src,sunid);
	getcomps(rays,rayid);
	
	vector<set<int> > res(k);
	forn(i,n){
		forn(j,m){
			int r=rayid.a[i][j];
			int s=sunid.a[i][j]-1;
			if(s!=-1&&r!=0){
				res[s].insert(r);
			}
		}
	}
	
	vector<int> ans(k);
	forn(i,k){
		ans[i]=sz(res[i]);
	}
	
	sort(all(ans));
	cout<<k<<'\n';
	forn(i,k){
		printf("%d ",ans[i]);
	}
	
	return 0;
}