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
typedef pair<short, short> PSS;
typedef pair<PII, int> PIII;
typedef pair<lng, lng> PLL;
typedef pair<lng, int> PLI;
typedef pair<ld, ld> PDD;
#define left asdleft
#define right asdright
#define link asdlink
#define unlink asdunlink
//#define next asdnext
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
const ld EPS = 1e-14;
const int INF = 1000*1000*1000;
const char CINF = 102;
const lng LINF = INF * 1ll * INF;
const ld DINF = 1e200;
const ld PI = 3.1415926535897932384626433832795L;
int gcd(int a,int b){return a?gcd(b%a,a):b;}
lng gcd(lng a,lng b){return a?gcd(b%a,a):b;}

char S[25][25];
int cost[8];
int N,M;
int cnt;
int dist[25][25][1<<8];
PII pos[8];

int main(){
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
	
	cin>>N>>M;
	gets(S[0]);
	int a0,b0;
	forn(i,N){
		gets(S[i]);
		forn(j,M){
			if(S[i][j]>='0' && S[i][j]<='9'){
				++cnt;
				--S[i][j];
			}
			if(S[i][j]=='S')
				a0=i,b0=j;
		}
	}
	forn(i,cnt){
		cin>>cost[i];
	}
	forn(i,N){
		forn(j,M){
			if(S[i][j]=='B'){
				cost[cnt]=-INF/50;
				S[i][j]='0'+cnt;
				++cnt;
			}
		}
	}
	forn(i,N){
		forn(j,M){
			if(S[i][j]>='0' && S[i][j]<='9')
				pos[S[i][j]-'0']=mp(i,j);
			forn(m,1<<cnt){
				dist[i][j][m]=INF;
			}
		}
	}
	priority_queue<pair<int,pair<PII,int> > > qu;
	dist[a0][b0][0]=0;
	qu.push(mp(-0,mp(mp(a0,b0),0)));
	while(!qu.empty()){
		int d=-qu.top().X;
		int a=qu.top().Y.X.X;
		int b=qu.top().Y.X.Y;
		int m=qu.top().Y.Y;
		qu.pop();
		if(d!=dist[a][b][m])
			continue;
		//cout<<a<<' '<<b<<' '<<m<<": "<<d<<endl;
		const int da[]={-1,1,0,0};
		const int db[]={0,0,-1,1};
		forn(dd,4){
			int aa=a+da[dd];
			int bb=b+db[dd];
			if(aa<0||aa>=N||bb<0||bb>=M||(S[aa][bb]!='.' && S[aa][bb]!='S'))
				continue;
			int mm=m;
			if(bb!=b){
				forn(i,cnt){
					int ta=pos[i].X;
					int tb=pos[i].Y;
					if(ta<a && tb==min(b,bb))
						mm^=1<<i;
				}
			}
			if(d+1<dist[aa][bb][mm]){
				if(!aa && !bb && !mm){
					//cout<<"upchk\n";
				}
				dist[aa][bb][mm]=d+1;
				qu.push(mp(-(d+1),mp(mp(aa,bb),mm)));
			}
		}
	}
	forn(m,1<<cnt){
		forn(i,N){
			forn(j,M){
				//cout<<dist[i][j][m]<<' ';
			}
			//cout<<endl;
		}
		//cout<<endl;
	}
	int ans=0;
	forn(m,1<<cnt){
		int s=0;
		forn(i,cnt){
			if(m&(1<<i))
				s+=cost[i];
		}
		ans=max(ans,s-dist[a0][b0][m]);
	}
	cout<<ans;
	
	return 0;
}