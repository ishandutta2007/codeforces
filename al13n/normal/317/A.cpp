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

int main() {
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
	
	lng x,y,m;
	cin>>x>>y>>m;
	if(y<x)
		swap(x,y);
	if(y>=m){
		cout<<0;
		return 0;
	}
	if(y<=0){
		cout<<-1;
		return 0;
	}
	lng r=0;
	if(x<0){
		r+=(-x)/y;
		x+=y*r;
	}
	forn(qqq,1000){
		if(y<x)
			swap(x,y);
		if(y>=m){
			cout<<qqq+r;
			return 0;
		}
		x+=y;
	}
	
	return 0;
}