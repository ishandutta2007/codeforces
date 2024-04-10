#pragma comment(linker, "/STACK:512000000")
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
const double EPS = 1e-6;
const int INF = 1000*1000*1000;
const char CINF = 102;
const lng LINF = INF * 1ll * INF;
const ld PI = 3.1415926535897932384626433832795;

char S[2100000];
char T[2100000];

int main() {
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif

	int n;
	cin>>n;
	n*=2;
	gets(S);
	gets(S);
	gets(T);
	
	int cnt[4]={0};
	forn(i,n){
		if(S[i]=='0'){
			if(T[i]=='0'){
				++cnt[3];
			}else{
				++cnt[2];
			}
		}else{
			if(T[i]=='0'){
				++cnt[1];
			}else{
				++cnt[0];
			}
		}
	}
	
	int s=0;
	int p=-1;
	while(true){
		p*=-1;
		int i=0;
		while(i<3&&!cnt[i])
			++i;
		if(i==3)
			break;
		--cnt[i];
		
		if(i==0){
			s+=p;
			continue;
		}
		
		if(p==1){
			if(i==1)
				++s;
		}else{
			if(i==2)
				--s;
		}
	}
	
	if(s>0)
		cout<<"First";
	else if(s<0)
		cout<<"Second";
	else
		cout<<"Draw";

	return 0;
}