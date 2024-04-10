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

void test(){
	forn(n0,100){
		const int N=41;
		static int A[N][N],T[N][N];
		clr(A,0);
		A[N/2][N/2]=n0;
		while(true){
			memcpy(T,A,sizeof(A));
			bool was=false;
			forn(i,N){
				forn(j,N){
					if(T[i][j]>=4){
						was=true;
						A[i][j]-=4;
						const int da[]={0,0,-1,1};
						const int db[]={-1,1,0,0};
						forn(d,4){
							int ii=i+da[d];
							int jj=j+db[d];
							if(ii<0||ii>=N||jj<0||jj>=N)
								continue;
							++A[ii][jj];
						}
					}
				}
			}
			if(!was)
				break;
		}
		forn(i,N){
			forn(j,N){
				cout<<A[i][j]<<' ';
			}
			cout<<endl;
		}
		cout<<endl;
	}
}

const int lim=501;
pair<short,short> A[lim][lim];
pair<short,short> qu[2][10000000];

int main() {
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
	
	cin>>A[lim/2][lim/2].X;
	int s=0;
	int qq=0;
	if(A[lim/2][lim/2].X>=4)
		qu[qq][s++]=mp(lim/2,lim/2);
	int c1=0,c2=0;
	while(s){
		++c1;
		forn(i,s){
			++c2;
			int a=qu[qq][i].X;
			int b=qu[qq][i].Y;
			A[a][b].X-=4;
			++A[a-1][b].X;
			++A[a+1][b].X;
			++A[a][b-1].X;
			++A[a][b+1].X;
		}
		int ss=0;
		forn(i,s){
			int a=qu[qq][i].X;
			int b=qu[qq][i].Y;
			const int da[]={0,0,-1,1,0};
			const int db[]={-1,1,0,0,0};
			forn(d,5){
				int aa=a+da[d];
				int bb=b+db[d];
				if(A[aa][bb].X>=4 && A[aa][bb].Y!=c1){
					A[aa][bb].Y=c1;
					qu[1-qq][ss++]=mp(aa,bb);
				}
			}
		}
		s=ss;
		qq=1-qq;
	}
	
	cerr<<c1<<' '<<c2<<endl;
	
//	for(int i=lim/2-10;i<=lim/2+10;++i){
//		for(int j=lim/2-10;j<=lim/2+10;++j){
//			cout<<A[i][j]<<' ';
//		}
//		cout<<endl;
//	}
//	return 0;
	
	int tc;
	cin>>tc;
	forn(qqq,tc){
		int a,b;
		scanf("%d%d",&a,&b);
		a+=lim/2;
		b+=lim/2;
		int r;
		if(a<0||a>=lim||b<0||b>=lim)
			r=0;
		else
			r=A[a][b].X;
		printf("%d\n",r);
	}
	
	return 0;
}