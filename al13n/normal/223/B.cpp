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
typedef double ld;
typedef pair<int,int> PII;
typedef pair<ld,ld> PDD;
typedef pair<lng,lng> PLL;
typedef complex<double> com;
const ld PI=3.1415926535897932384626433832795;
const ld EPS=1e-3;
const int inf=1000000000;
const lng linf=1000000000000000000LL;
template<class T> inline T sqr(T x) { return x * x; }
int gcd(int a,int b){return a?gcd(b%a,a):b;}

string A,B;
int mt1[210000];
int mt2[210000];
int cnt[210000][26];

int main() {
#ifdef __ASD__
    freopen("input.txt","rt",stdin);freopen("output.txt","wt",stdout);
#endif
	
	cin>>A>>B;
	forv(i,A){
		mt1[i+1]=mt1[i];
		if(mt1[i]<sz(B) && A[i]==B[mt1[i]])
			++mt1[i+1];
	}
	forv(i,B){
		forn(j,26){
			cnt[i+1][j]=cnt[i][j];
		}
		++cnt[i+1][B[i]-'a'];
	}
	reverse(all(A));
	reverse(all(B));
	forv(i,A){
		mt2[i+1]=mt2[i];
		if(mt2[i]<sz(B) && A[i]==B[mt2[i]])
			++mt2[i+1];
	}
	reverse(all(A));
	reverse(all(B));
	
	forv(i,A){
		int a=mt1[i+1];
		int b=mt2[sz(A)-i];
		if(cnt[a][A[i]-'a']<=cnt[sz(B)-b][A[i]-'a']){
			cout<<"No";
			return 0;
		}
	}
	cout<<"Yes";
	
	return 0;
}