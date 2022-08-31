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
typedef long double ld;
typedef pair<int, int> PII;
typedef pair<short, short> PSS;
typedef pair<PII, int> PIII;
typedef pair<lng, lng> PLL;
typedef pair<lng, int> PLI;
typedef pair<ld, ld> PDD;
#define left asdleft
#define right asdright
#define link asdlink
#define unlink asdunlink
//#define next asdnext
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
const ld EPS = 1e-14;
const int INF = 1000*1000*1000;
const char CINF = 102;
const lng LINF = INF * 1ll * INF;
const ld DINF = 1e200;
const ld PI = 3.1415926535897932384626433832795L;
int gcd(int a,int b){return a?gcd(b%a,a):b;}
lng gcd(lng a,lng b){return a?gcd(b%a,a):b;}

int S[45][45];
int A[45][45][45][45];
int n,m;

int main(){
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
	
	int tc;
	cin>>n>>m>>tc;
	char line[50];
	gets(line);
	forn(i,n){
		gets(line);
		forn(j,m){
			S[i+1][j+1]=S[i+1][j]+S[i][j+1]-S[i][j]+(line[j]-'0');
		}
	}
	/*
	forn(i,n+1){
		forn(j,m+1){
			cout<<S[i][j]<<' ';
		}
		cout<<endl;
	}*/
	forn(i2,n+1){
		forn(i1,i2){
			forn(j2,m+1){
				forn(j1,j2){
					if(i1==1 && j1==0 && i2==2 && j2==1){
						//cout<<S[i1][j1]<<' '<<S[i1][j2]<<' '<<S[i2][j1]<<' '<<S[i2][j2]<<endl;
					}
					if(S[i2][j2]-S[i2][j1]-S[i1][j2]+S[i1][j1]==0)
						++A[i1][i2][j1][j2];
				}
			}
		}
	}
	forn(i2,n+1){
		forn(i1,i2){
			forn(j1,m){
				for(int j2=j1+1;j2<m;++j2){
					A[i1][i2][j1][j2+1]+=A[i1][i2][j1][j2];
				}
			}
		}
	}
	forn(i2,n+1){
		forn(i1,i2){
			forn(j2,m+1){
				for(int j1=j2-1;j1>0;--j1){
					A[i1][i2][j1-1][j2]+=A[i1][i2][j1][j2];
				}
			}
		}
	}
	forn(i1,n){
		for(int i2=i1+1;i2<n;++i2){
			forn(j2,m+1){
				forn(j1,j2){
					A[i1][i2+1][j1][j2]+=A[i1][i2][j1][j2];
				}
			}
		}
	}
	forn(i2,n+1){
		for(int i1=i2-1;i1>0;--i1){
			forn(j2,m+1){
				forn(j1,j2){
					A[i1-1][i2][j1][j2]+=A[i1][i2][j1][j2];
				}
			}
		}
	}
	forn(qqq,tc){
		int i1,j1,i2,j2;
		scanf("%d%d%d%d",&i1,&j1,&i2,&j2);
		--i1;--j1;
		printf("%d\n",A[i1][i2][j1][j2]);
	}
	
	return 0;
}