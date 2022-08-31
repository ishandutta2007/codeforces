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

struct grandi{
	map<int,int> mem;
	
	int doit(int k,int m){
		if(mem.count(m))
			return mem[m];
		int &res=mem[m];
		bool was[35]={false};
		forn(i,k){
			if(!(m&(1<<i)))
				continue;
			int mm=m;
			for(int a=1;(i+1)*a<=k;++a){
				mm&=~(1<<((i+1)*a-1));
			}
			was[doit(k,mm)]=true;
		}
		while(was[res])
			++res;
		return res;
	}
};

bool pw[1000000];

void precalc(){
	cout<<"{";
	for(int k=1;k<=29;++k){
		cout<<grandi().doit(k,(1<<k)-1)<<","<<endl;
	}
	cout<<"}"<<endl;
}

const int gr[]={1,
	2,
	1,
	4,
	3,
	2,
	1,
	5,
	6,
	2,
	1,
	8,
	7,
	5,
	9,
	8,
	7,
	3,
	4,
	7,
	4,
	2,
	1,
	10,
	9,
	3,
	6,
	11,
	12
};


int main() {
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
	
	//precalc();return 0;
	
	lng n;
	cin>>n;
	map<int,int> chains;
	lng s=0;
	for(lng a=2;a*a<=n;++a){
		if(pw[a])
			continue;
		lng t=a;
		int k=1;
		while(true){
			t*=a;
			if(t>n)
				break;
			++k;
			if(t<800000)
				pw[t]=true;
		}
		if(k<2)
			exit(123);
		++chains[k];
		s+=k;
	}
	chains[1]=n-s;
	
	int g=0;
	for(map<int,int>::iterator it=chains.begin();it!=chains.end();++it){
		int k=it->X;
		int c=it->Y;
		if(c%2==0)
			continue;
		g^=gr[k-1];
		//g^=grandi().doit(k,(1<<k)-1);
	}
	
	cout<<(g?"Vasya":"Petya");
	
	return 0;
}