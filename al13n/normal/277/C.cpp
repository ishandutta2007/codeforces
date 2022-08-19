#pragma comment(linker, "/STACK:256000000")
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
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
typedef pair<int, PII> PIII;
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
const double EPS = 1e-10;
const int INF = 1000*1000*1000;
const lng LINF = INF * 1ll * INF;
const ld PI = 3.1415926535897932384626433832795;

lng sign(int a){
	if(a<0)
		return -1;
	if(a>0)
		return 1;
	return 0;
}

struct line{
	int x0,y0,x2,y2;
	
	vector<PII> evs;
	vector<PII> pos;
	int cnt;
	int len;
	
	void add(int a,int b){
		evs.pb(mp(a,-1));
		evs.pb(mp(b,1));
	}
	
	void process(){
		len=abs(x2-x0)+abs(y2-y0);
		sort(all(evs));
		int d=0;
		int p=0;
		cnt=0;
		forv(i,evs){
			int x=evs[i].X;
			if(!d && x>p){
				pos.pb(mp(p,x));
				cnt+=x-p;
			}
			d+=evs[i].Y;
			if(!d)
				p=x;
		}
		if(p<len){
			pos.pb(mp(p,len));
			cnt+=len-p;
		}
	}
	
	void print_cut(int s){
		int i=0;
		while(pos[i].Y-pos[i].X<s){
			s-=pos[i].Y-pos[i].X;
			++i;
		}
		int p=pos[i].X+s;
		cout<<x0<<' '<<y0<<' '<<x0+p*sign(x2-x0)<<' '<<y0+p*sign(y2-y0)<<'\n';
	}
};

line ls[210000];
int lc;
map<int,int> rows;
map<int,int> cols;
int W,H;

line & get_row(int a){
	if(rows.count(a))
		return ls[rows[a]];
	line &res=ls[lc++];
	res.x0=0;
	res.x2=W;
	res.y0=res.y2=a;
	rows[a]=lc-1;
	return res;
}

line & get_col(int a){
	if(cols.count(a))
		return ls[cols[a]];
	line &res=ls[lc++];
	res.y0=0;
	res.y2=H;
	res.x0=res.x2=a;
	cols[a]=lc-1;
	return res;
}

int main() {
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif

	int k;
	cin>>W>>H>>k;
	forn(i,k){
		int x0,x2,y0,y2;
		scanf("%d%d%d%d",&x0,&y0,&x2,&y2);
		if(x2<x0)
			swap(x0,x2);
		if(y2<y0)
			swap(y0,y2);
		if(x0==x2)
			get_col(x0).add(y0,y2);
		else
			get_row(y0).add(x0,x2);
	}
	
	int q=0;
	for(int i=1;i<W;++i){
		if(q>=2 && (W-1-sz(cols))%2==0)
			break;
		if(cols.count(i))
			continue;
		get_col(i);
		++q;
	}
	q=0;
	for(int i=1;i<H;++i){
		if(q>=2 && (H-1-sz(rows))%2==0)
			break;
		if(rows.count(i))
			continue;
		get_row(i);
		++q;
	}
	
	int x=0;
	forn(i,lc){
		ls[i].process();
		x^=ls[i].cnt;
	}
	if(!x){
		cout<<"SECOND";
		return 0;
	}
	cout<<"FIRST\n";
	forn(i,lc){
		int y=x^ls[i].cnt;
		if(y<ls[i].cnt){
			ls[i].print_cut(ls[i].cnt-y);
			return 0;
		}
	}
	exit(123);

	return 0;
}