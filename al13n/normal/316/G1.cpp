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

char src[11][2100];
int N[11];
int L[11],R[11];
char *ar[11][2100];
string S;
int n;

struct asd{
	int a,b;
	asd(int a,int b):a(a),b(b){}
	bool operator<(const asd &t)const{
		if(b-a!=t.b-t.a)
			return b-a<t.b-t.a;
		return memcmp(S.data()+a,S.data()+t.a,b-a)<0;
	}
	bool operator==(const asd &t)const{
		if(b-a!=t.b-t.a)
			return false;
		return memcmp(S.data()+a,S.data()+t.a,b-a)==0;
	}
};

bool cmpr(char *a,char *b){
	return strcmp(a,b)<0;
}

int main() {
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
	
	cin>>S>>n;
	forn(i,n){
		scanf("%s%d%d",src[i],L+i,R+i);
		N[i]=strlen(src[i]);
		forn(j,N[i]){
			ar[i][j]=src[i]+j;
		}
		sort(ar[i],ar[i]+N[i],cmpr);
	}
	
	vector<asd> res;
	forn(a,sz(S)){
		int l[11],r[11];
		forn(i,n){
			l[i]=0;
			r[i]=N[i]-1;
		}
		for(int b=a;b<sz(S);++b){
			bool ok=true;
			bool canok=true;
			forn(i,n){
				while(l[i]<=r[i] && ar[i][l[i]][b-a]!=S[b])
					++l[i];
				while(l[i]<=r[i] && ar[i][r[i]][b-a]!=S[b])
					--r[i];
				int c=r[i]-l[i]+1;
				if(c<L[i]){
					canok=false;
					ok=false;
					break;
				}
				if(c>R[i])
					ok=false;
			}
			if(ok)
				res.pb(asd(a,b+1));
			if(!canok)
				break;
		}
	}
	
	sort(all(res));
	res.erase(unique(all(res)),res.end());
	cout<<sz(res);
	
	return 0;
}