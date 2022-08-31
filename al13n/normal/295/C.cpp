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
const double EPS = 1e-6;
const int INF = 1000*1000*1000;
const char CINF = 102;
const lng LINF = INF * 1ll * INF;
const ld PI = 3.1415926535897932384626433832795;

int K;
const lng mod=INF+7;
PLL dist[55][55][2];
bool done[55][55][2];
int A,B;

lng C[55][55];

int main() {
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
	
	ios_base::sync_with_stdio(false);

	forn(i,53){
		C[i][0]=C[i][i]=1;
		for(int j=1;j<i;++j){
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
		}
	}
	
	int n0;
	cin>>n0>>K;
	K/=50;
	forn(i,n0){
		int x;
		cin>>x;
		if(x==50)
			++A;
		else
			++B;
	}
	
	forn(a,A+1){
		forn(b,B+1){
			forn(f,2){
				dist[a][b][f]=mp(INF,0);
			}
		}
	}
	priority_queue<pair<lng,pair<PII,int> > > qu;
	dist[A][B][0]=mp(0,1);
	qu.push(mp(-0,mp(mp(A,B),0)));
	while(!qu.empty()){
		int a,b,f;
		do{
			a=qu.top().Y.X.X;
			b=qu.top().Y.X.Y;
			f=qu.top().Y.Y;
			qu.pop();
		}while(!qu.empty() && done[a][b][f]);
		if(done[a][b][f])
			break;
		done[a][b][f]=true;
		for(int x=0;x<=a;++x){
			for(int y=0;y<=b;++y){
				if((!x&&!y) || x+y*2>K)
					continue;
				int aa=A-a+x;
				int bb=B-b+y;
				int ff=1-f;
				if(dist[a][b][f].X+1<dist[aa][bb][ff].X){
					dist[aa][bb][ff]=mp(dist[a][b][f].X+1,dist[a][b][f].Y*C[a][x]%mod*C[b][y]%mod);
					qu.push(mp(-dist[aa][bb][ff].X,mp(mp(aa,bb),ff)));
				}else if (dist[a][b][f].X+1==dist[aa][bb][ff].X){
					dist[aa][bb][ff].Y=(dist[aa][bb][ff].Y+dist[a][b][f].Y*C[a][x]%mod*C[b][y]%mod)%mod;
				}
			}
		}
	}
	
	if(!done[A][B][1]){
		cout<<"-1\n0";
		return 0;
	}
	cout<<dist[A][B][1].X<<'\n'<<dist[A][B][1].Y;

	return 0;
}