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
#include <ctime>
using namespace std;
#define forn(i,n) for(int i=0;i<(n);++i)
#define forv(i,v) forn(i,(int)(v).size())
#define iinf 1000000000
#define linf 1000000000000000000LL
#define dinf 1e200
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define mp make_pair
#define lng long long
#define eps 1e-5
#define EQ(a,b) (fabs((a)-(b))<eps)
#define SQ(a) ((a)*(a))
#define PI 3.14159265359
#define index asdindex
#define FI first
#define SE second
#define prev asdprev
#define PII pair<int,int> 
#define PLL pair<lng,lng> 
#define PDD pair<double,double> 
#define X first
#define Y second
#define unlink asdunlink
typedef unsigned char uchar;
typedef unsigned int uint;
inline int mymax(int a,int b){return a<b?b:a;}
inline int mymin(int a,int b){return a>b?b:a;}
inline lng mymax(lng a,lng b){return a<b?b:a;}
inline lng mymin(lng a,lng b){return a>b?b:a;}

int n;
lng R;
lng B[32];
int P[32];
lng K[32];
lng res=-linf;

struct state{
	lng ar[32];

	void op1(){
		forn(i,n)
			ar[i]^=B[i];
	}

	void op2(const state &s){
		forn(i,n){
			ar[i]=s.ar[P[i]]+R;
		}
	}

	lng ans()const{
		lng r=0;
		forn(i,n){
			r+=ar[i]*K[i];
		}
		return r;
	}
};

void doit(const state &s,int u,bool xord){
	if(u%2==0)
		res=max(res,s.ans());
	if(!u)
		return;
	state t;
	if(!xord){
		t=s;
		t.op1();
		doit(t,u-1,true);
	}
	t.op2(s);
	doit(t,u-1,false);
}

int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
    //ios_base::sync_with_stdio(false);

	int u;
	cin>>n>>u>>R;
	state s;
	forn(i,n)
		cin>>s.ar[i];
	forn(i,n)
		cin>>B[i];
	forn(i,n)
		cin>>K[i];
	forn(i,n){
		cin>>P[i];
		--P[i];
	}
	doit(s,u,false);
	cout<<res;

    return 0;
}