#pragma comment(linker,"/STACK:256000000")
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <complex>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cstdlib>
#include <cstring>
using namespace std;
#define bublic public:
#define sz(v) ((int)(v).size())
#define forn(i,n) for(int i=0;i<(n);++i)
#define forv(i,v) forn(i,sz(v))
#define pb push_back
#define mp make_pair
#define istr stringstream
#define fi first
#define se second
#define X first
#define Y second
#define clr(a) memset((a),0,sizeof(a))
#define clr2(a) memset((a),-1,sizeof(a))
#define y0 asdy0
#define y1 asdy1
#define j0 asdj0
#define j1 asdj1
#define next asdnext
#define prev asdprev
#define link asdlink
#define unlink asdunlink
#define left asdleft
#define right asdright
#define hash asdhash
#define all(v) (v).begin(),(v).end()
typedef long long lng;
typedef unsigned int uint;
typedef unsigned long long ulng;
typedef unsigned char uchar;
typedef long double ld;
typedef pair<int,int> PII;
typedef pair<ld,ld> PDD;
typedef pair<lng,lng> PLL;
typedef complex<double> com;
const ld PI=3.1415926535897932384626433832795;
const ld EPS=1e-3;
const int inf=1000000000;
const lng linf=1000000000000000000LL;
template<class T> inline T sqr(T x) { return x * x; }

const lng mod=inf+7;

int brute(int w,int h){
	int res=0;
	forn(x1,w+1){
		forn(y1,h+1){
			forn(x2,w+1){
				forn(y2,h+1){
					forn(x3,w+1){
						forn(y3,h+1){
							if(min(min(x1,x2),x3)!=0 || min(min(y1,y2),y3)!=0 || max(max(x1,x2),x3)!=w || max(max(y1,y2),y3)!=h)
								continue;
							int t=(x2-x1)*(y3-y1)-(x3-x1)*(y2-y1);
							if(!t||t%2)
								continue;
							++res;
							if(res==mod)
								res=0;
						}
					}
				}
			}
		}
	}
	return res;
}

lng gcd(lng a,lng b){
	return a?gcd(b%a,a):b;
}

int clever(ulng w,ulng h){
	ulng res=0;
	
	if(w*h%2==0)
		res=(res+2*(w+h-2))%mod;
	
	if(w%2==0&&h%2==0)
		res=(res+2*((w+1)*(h+1)-1-gcd(w,h)));
	else if(w%2==0&&h%2==1)
		res=(res+2*((w/2+1)*(h+1)-1-gcd(w,h)));
	else if(w%2==1&&h%2==0)
		res=(res+2*((w+1)*(h/2+1)-1-gcd(w,h)));
	else
		res=(res+2*((w+1)/2*(h+1)-1-gcd(w,h)));

	if(h*w%2==0)
		res=(res+4*((w-1)*(h-1)-w/2*(h/2)));
	else
		res=(res+4*((w-1)/2*((h-1)/2)));

	return (int)(res%(ulng)mod);
}

int main() {
#ifdef __ASD__
    freopen("q.in","rt",stdin);freopen("q.out","wt",stdout);
#endif

	/*for(int w=1;w<=15;++w){
		for(int h=1;h<=15;++h){
			cerr<<w<<' '<<h<<endl;
			int b=brute(w,h);
			int c=clever(w,h);
			if(b!=c*6){
				cout<<"failed"<<endl;
				exit(123);
			}
		}
	}
	cout<<"passed"<<endl;*/

	lng w,h;
	cin>>w>>h;
	lng res=0;
	for(lng i=1;i<=w||i<=h;++i){
		for(int j=1;j<=i;++j){
			lng v=clever(i,j);
			if(i<=w && j<=h)
				res+=v*6*(w-i+1)*(h-j+1);
			if(i!=j && i<=h && j<=w)
				res+=v*6*(h-i+1)*(w-j+1);
			res%=mod;
		}
	}
	cout<<res;

	return 0;
}