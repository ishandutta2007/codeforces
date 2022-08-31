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
typedef pair<PII, int> PIII;
typedef pair<lng, lng> PLL;
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
const double EPS = 1e-6;
const int INF = 1000*1000*1000;
const char CINF = 102;
const lng LINF = INF * 1ll * INF;
const ld PI = 3.1415926535897932384626433832795;

void answer(){
	forn(i,10){
		printf("???%d>>%d???\n",i,i);
	}
	printf("???>>??\n");
	forn(i,9){
		printf("%d??>>?%d\n",i,i+1);
	}
	printf("9??>>??0\n");
	forn(i,10){
		printf("%d?>>?%d\n",i,i);
	}
	printf("??>>?1\n");
	printf("?<>\n");
	forn(i,10){
		printf("%d>>%d???\n",i,i);
	}
}

struct move{
	string a,b;
	bool term;
};

typedef vector<move> algo;

algo read(){
	string s;
	algo res;
	while(cin>>s){
		move m;
		m.term=false;
		int p=0;
		while(s[p]!='<'&&s[p]!='>')
			++p;
		m.a=s.substr(0,p);
		if(s[p]=='<')
			m.term=true;
		p+=2;
		m.b=s.substr(p);
		res.pb(m);
	}
	return res;
}

bool apply(string &s,const move &m){
	forn(i,sz(s)-sz(m.a)+1){
		if(s.substr(i,sz(m.a))==m.a){
			s=s.substr(0,i)+m.b+s.substr(i+sz(m.a));
			return true;
		}
	}
	return false;
}

string run(string s,const algo &a){
	forn(step,200){
		bool found=false;
		forv(i,a){
			if(apply(s,a[i])){
				if(a[i].term)
					return s;
				found=true;
				break;
			}
		}
		if(!found)
			return s;
	}
	cout<<"too long"<<endl;
	exit(123);
}

void test(){
	algo a=read();
	for(int k=1;k<=1000;++k){
		string s0=tostr(k);
		string s1=tostr(k+1);
		string r=run(s0,a);
		if(r!=s1){
			cout<<"failed "<<k<<": "<<r<<endl;
			return;
		}
	}
	cout<<"passed"<<endl;
}

int main() {
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif

	answer();
	//test();
	
	return 0;
}