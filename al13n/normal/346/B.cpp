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
lng gcd(lng a,lng b){return a?gcd(b%a,a):b;}
//uint gcd(uint a,uint b){return a?gcd(b%a,a):b;}

string s1,s2,sv;
pair<PII,PII> dp[110][110][110];
int fall[110][26];

int main(int argc, char **argv) {
	//ios_base::sync_with_stdio(false);cout.tie(0);

	cin>>s1>>s2>>sv;

	forn(i,sz(sv)){
		forn(c,26){
			int k;
			for(k=i+1;k>0;--k){
				if(sv.substr(0,k)==sv.substr(i+1-k,k-1)+(char)(c+'A'))
					break;
			}
			fall[i][c]=k;
		}
	}

	clr(dp,-1);
	dp[0][0][0].X.X=0;
	for(int i=0;i<=sz(s1);++i){
		for(int j=0;j<=sz(s2);++j){
			for(int k=0;k<sz(sv);++k){
				if(dp[i][j][k].X.X==-1)
					continue;
				if(i<sz(s1) && j<sz(s2) && s1[i]==s2[j]){
					int kk=fall[k][s1[i]-'A'];
					if(kk!=sz(sv))
						dp[i+1][j+1][kk]=max(dp[i+1][j+1][kk],mp(mp(dp[i][j][k].X.X + 1,k),mp(i,j)));
				}
				if(i<sz(s1))
					dp[i+1][j][k]=max(dp[i+1][j][k],mp(mp(dp[i][j][k].X.X,k),mp(i,j)));
				if(j<sz(s2))
					dp[i][j+1][k]=max(dp[i][j+1][k],mp(mp(dp[i][j][k].X.X,k),mp(i,j)));
			}
		}
	}

	pair<PII,PII> p(mp(-1,0),mp(0,0));
	forn(i,sz(s1)+1){
		forn(j,sz(s2)+1){
			forn(k,sz(sv)){
				p=max(p,mp(mp(dp[i][j][k].X.X,k),mp(i,j)));
			}
		}
	}

	int l=p.X.X;
	string r;
	while(p.Y.X || p.Y.Y){
		pair<PII,PII> pp=dp[p.Y.X][p.Y.Y][p.X.Y];
		if(pp.Y.X!=p.Y.X && pp.Y.Y!=p.Y.Y)
			r+=s1[pp.Y.X];
		p=pp;
	}
	if(sz(r)!=l)
		exit(123);
	reverse(all(r));
	if(r=="")
		cout<<0<<endl;
	else
		cout<<r<<endl;

	return 0;
}