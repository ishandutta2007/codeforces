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

struct str{
	lng ac;
	char x,y;
	str(){}
	str(lng ac,char x,char y):ac(ac),x(x),y(y){}
	str operator+(const str &b)const{
		return str(ac+b.ac+(y=='A'&&b.x=='C'),x,b.y);
	}
};

int main(){
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false);
	
	lng k,x,n,m;
	cin>>k>>x>>n>>m;
	
	string a(n,'B');
	string b(m,'B');
	for(a[0]='A';a[0]<='C';++a[0]){
		for(a[sz(a)-1]='A';a[sz(a)-1]<='C';++a[sz(a)-1]){
			for(int i=1;i+1<sz(a);++i)
				a[i]='B';
			for(int i1=0;i1+1<max(2,sz(a));++i1){
				if(i1)
					a[i1]=a[i1-1]=='A'?'C':'A';
				int ac1=0;
				forn(i,sz(a)-1){
					if(a[i]=='A'&&a[i+1]=='C')
						++ac1;
				}
				for(b[0]='A';b[0]<='C';++b[0]){
					for(b[sz(b)-1]='A';b[sz(b)-1]<='C';++b[sz(b)-1]){
						for(int i=1;i+1<sz(b);++i)
							b[i]='B';
						for(int i2=0;i2+1<max(2,sz(b));++i2){
							if(i2)
								b[i2]=b[i2-1]=='A'?'C':'A';
							int ac2=0;
							forn(i,sz(b)-1){
								if(b[i]=='A'&&b[i+1]=='C')
									++ac2;
							}
							str t1(ac1,a[0],a[sz(a)-1]);
							str t2(ac2,b[0],b[sz(b)-1]);
							forn(q,k-2){
								str t=t1+t2;
								t1=t2;
								t2=t;
								if(t2.ac>x)
									break;
							}
							if(t2.ac==x){
								cout<<a<<'\n'<<b<<endl;
								return 0;
							}
						}
					}
				}
			}
		}
	}
	cout<<"Happy new year!";
	
	return 0;
}