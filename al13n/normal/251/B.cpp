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

void yep(){
	cout<<"YES";
	exit(0);
}
void nope(){
	cout<<"NO";
	exit(0);
}

int main() {
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
	
	int n,k;
	cin>>n>>k;
	vector<int> q(n),s(n);
	forn(i,n){
		cin>>q[i];
		--q[i];
	}
	forn(i,n){
		cin>>s[i];
		--s[i];
	}
	int p1=k+10,p2=k+10;
	vector<int> t1(n),t2(n);
	forn(i,n){
		t1[i]=t2[i]=i;
	}
	forn(qqq,k+10){
		if(t1==s&&p1==k+10)
			p1=qqq;
		if(t2==s&&p2==k+10)
			p2=qqq;
		vector<int> t=t1;
		forn(i,n){
			t1[i]=t[q[i]];
		}
		t=t2;
		forn(i,n){
			t2[q[i]]=t[i];
		}
	}

	if(p1==k||p2==k)
		yep();
	if(!p1)
		nope();
	if(p1==1&&p2==1)
		nope();
	if(p1<k&&p1%2==k%2)
		yep();
	if(p2<k&&p2%2==k%2)
		yep();
	nope();
	
	return 0;
}