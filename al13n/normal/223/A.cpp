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

int cnt[110000];
bool ok[110000];

int main() {
#ifdef __ASD__
    freopen("input.txt","rt",stdin);freopen("output.txt","wt",stdout);
#endif
	
	string s;
	cin>>s;
	int n=sz(s);
	forn(i,n){
		cnt[i+1]=cnt[i]+(s[i]=='[');
	}
	vector<int> st;
	pair<int,PII> res(0,mp(0,0));
	forn(b,n+1){
		char ch=s[b];
		if(b<n && (ch=='('||ch=='[')){
			st.pb(b);
		}else{
			if(b==n || st.empty() || s[st.back()] != (ch==')'?'(':'[')){
				st.clear();
			}else{
				ok[st.back()]=ok[b]=true;
				st.pop_back();
			}
		}
	}
	int a=0;
	forn(i,n){
		if(!ok[i]){
			a=i+1;
		}else{
			res=max(res,mp(cnt[i+1]-cnt[a],mp(a,i+1)));
		}
	}
	
	cout<<res.X<<endl;
	cout<<s.substr(res.Y.X,res.Y.Y-res.Y.X);
	
	return 0;
}