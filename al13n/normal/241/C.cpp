#pragma comment(linker,"/STACK:256000000")
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
#include <memory.h>
using namespace std;
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
#define clr(a,v) memset((a),(v),sizeof(a))
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
#define div asddiv
#define all(v) (v).begin(),(v).end()
typedef long long lng;
typedef unsigned int uint;
typedef unsigned long long ulng;
typedef unsigned char uchar;
typedef double ld;
typedef pair<int,int> PII;
typedef pair<ld,ld> PDD;
typedef pair<lng,lng> PLL;
typedef complex<double> com;
const ld PI=3.1415926535897932384626433832795;
const ld EPS=1e-8;
const int inf=1000000000;
const lng linf=1000000000000000000LL;
template<class T> inline T sqr(T x) { return x * x; }
int gcd(int a,int b){return a?gcd(b%a,a):b;}



int main() {
#ifdef __ASD__
    freopen("input.txt","rt",stdin);freopen("output.txt","wt",stdout);
#endif

	double hl,hr;
	int n;
	cin>>hl>>hr>>n;
	vector<pair<pair<double,double>,int> > segs[2];
	forn(i,n){
		int v,a,b;
		char c;
		cin>>v>>c>>a>>b;
		if(c=='T')
			segs[1].pb(mp(mp(a,b),v));
		else
			segs[0].pb(mp(mp(a,b),v));
	}
	sort(all(segs[0]));
	sort(all(segs[1]));
	reverse(all(segs[0]));
	reverse(all(segs[1]));
	double w=100000;
	double h=100;
	int best=0;
	for(int p=-110;p<=110;++p){
		if(!p)
			continue;
		double yl=hl;
		double yr=p*h;
		if(abs(p)%2)
			yr+=h-hr;
		else
			yr+=hr;
		int res=0;
		vector<pair<pair<double,double>,int> > sg[2];
		sg[0]=segs[0];
		sg[1]=segs[1];
		if(p<0){
			for(double y=0;y>yr;y-=h){
				double x=w*(y-yl)/(yr-yl);
				while(sg[0].size() && sg[0].back().X.Y<x-EPS)
					sg[0].pop_back();
				if(!sg[0].size() || sg[0].back().X.X>x+EPS){
					res=0;
					break;
				}
				res+=sg[0].back().Y;
				sg[0].pop_back();
				sg[0].swap(sg[1]);
			}
		}else{
			sg[0].swap(sg[1]);
			for(double y=h;y<yr;y+=h){
				double x=w*(y-yl)/(yr-yl);
				while(sg[0].size() && sg[0].back().X.Y<x-EPS)
					sg[0].pop_back();
				if(!sg[0].size() || sg[0].back().X.X>x+EPS){
					res=0;
					break;
				}
				res+=sg[0].back().Y;
				sg[0].pop_back();
				sg[0].swap(sg[1]);
			}
		}
		if(res>best){
			best=res;
		}
	}
	
	cout<<best;
	
	return 0;
}