#pragma comment(linker,"/STACK:256000000")
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <memory.h>
#include <string>
#include <set>
#include <queue>
#include <map>
#include <iomanip>
#include <sstream>
#include <stack>
using namespace std;
#define forn(i,n) for(int i=0;i<(n);++i)
#define forv(i,v) forn(i,(int)(v).size())
#define iinf 1000000000
#define linf 1000000000000000000LL
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define mp make_pair
#define lng long long
#define eps 1e-10
#define EQ(a,b) (fabs((a)-(b))<eps)
#define SQ(a) ((a)*(a))
#define PI 3.14159265359
#define index asdindex
#define FI first
#define SE second
#define prev asdprev
#define PII pair<int,int> 
#define X first
#define Y second
#define unlink asdunlink
typedef unsigned char uchar;
typedef unsigned int uint;

inline int mymax(int a,int b){
	return a<b?b:a;
}
inline int mymin(int a,int b){
	return a>b?b:a;
}
inline lng mymax(lng a,lng b){
	return a<b?b:a;
}
inline lng mymin(lng a,lng b){
	return a>b?b:a;
}

int n,m,k;
int buy[11][110];
int sell[11][110];
int cnt[11][110];

int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
    //ios_base::sync_with_stdio(false);

	cin>>n>>m>>k;
	forn(i,n){
		string unused;
		cin>>unused;
		forn(j,m){
			cin>>buy[i][j]>>sell[i][j]>>cnt[i][j];
		}
	}
	lng res=0;
	forn(a,n){
		forn(b,n){
			vector<PII> v;
			forn(i,m){
				int d=sell[b][i]-buy[a][i];
				int c=cnt[a][i];
				if(d>0&&c>0)
					v.pb(mp(d,c));
			}
			sort(all(v));
			int c=0;
			lng r=0;
			while(c<k&&!v.empty()){
				++c;
				r+=v.back().X;
				--v.back().Y;
				if(!v.back().Y)
					v.pop_back();
			}
			res=max(res,r);
		}
	}
	cout<<res;

    return 0;
}