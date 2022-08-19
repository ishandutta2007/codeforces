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
const ld EPS=1e-12;
const int inf=1000000000;
const lng linf=1000000000000000000LL;
template<class T> inline T sqr(T x) { return x * x; }
int gcd(int a,int b){return a?gcd(b%a,a):b;}

bool check(vector<int> hs,vector<int> ss,int k,int T){
	if(sz(hs)>sz(ss)+k)
		return false;
	if(k>=sz(hs))
		return hs.back()+1<=T;
	int R=max(hs.back(),ss[sz(hs)-k-1]);
	int p=0;
	int x=-1;
	int mx=-1;
	forv(i,hs){
		int v=hs[i];
		T-=v-x;
		x=v;
		mx=max(mx,v);
		if(T<0)
			return false;
		if(k){
			--k;
			continue;
		}
		if(p==sz(ss))
			return false;
		int z=ss[p++];
		if(T-2*(R-v)>=0)
			return true;
		if(z>mx){
			T-=2*(z-mx);
			mx=z;
		}
		if(T<0)
			return false;
	}
	return true;
}

int main() {
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
	
	int n,T;
	cin>>n>>T;
	static char S[510000];
	gets(S);
	gets(S);
	vector<int> hs,ss;
	forn(i,n){
		if(S[i]=='H')
			hs.pb(i);
		if(S[i]=='S')
			ss.pb(i);
	}
	
	int a=-1,b=sz(hs)+1;
	while(b>a+1){
		int k=(a+b)/2;
		if(check(hs,ss,k,T))
			b=k;
		else
			a=k;
	}
	if(b==sz(hs)+1)
		cout<<-1;
	else
		cout<<b;
	
	return 0;
}