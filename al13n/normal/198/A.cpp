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
#define fors(i,s) forn(i,(int)(s).length())
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define mp make_pair
#define EQ(a,b) (fabs((a)-(b))<eps)
#define SQ(a) ((a)*(a))
#define index asdindex
#define prev asdprev
#define X first
#define Y second
#define unlink asdunlink
#define div asddiv
#define tr1 asdtr1
#define y0 asdy0
typedef unsigned char uchar;
typedef unsigned int uint;
typedef long long lng;
typedef pair<int,int> PII;
typedef pair<lng,lng> PLL;
typedef pair<double,double> PDD;
const int iinf=1000000000;
const lng linf=1000000000000000000LL;
const double dinf=1e200;
const double eps=1e-8;
const double PI=3.14159265359;
inline int mymax(int a,int b){return a<b?b:a;}
inline int mymin(int a,int b){return a>b?b:a;}
inline lng mymax(lng a,lng b){return a<b?b:a;}
inline lng mymin(lng a,lng b){return a>b?b:a;}
inline lng myabs(lng a){return a<0?-a:a;}

struct num{
	double v;
	int e;
	num(){}
	void norm(){
		if(!v){
			e=-iinf;
			return;
		}
		while(v>=2){
			v*=.5;
			++e;
		}
		while(v<1){
			v*=2;
			--e;
		}
	}
	num(double v):v(v),e(0){
		norm();
	}
	num operator+(const num &b)const{
		if(e==-iinf)
			return b;
		if(b.e==-iinf)
			return *this;
		double v1=v,v2=b.v;
		int e1=e,e2=b.e;
		int e=max(e1,e2);
		while(e1<e){
			++e1;
			v1*=.5;
		}
		while(e2<e){
			++e2;
			v2*=.5;
		}
		num r;
		r.v=v1+v2;
		r.e=e;
		r.norm();
		return r;
	}
	num operator*(double b)const{
		num r=*this;
		r.v*=b;
		r.norm();
		return r;
	}

	bool operator<(const num &b)const{
		if(e!=b.e)
			return e<b.e;
		return v<b.v;
	}
};

num pw[1100000];
num su[1100000];

int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(false);

	int k,b,n,t;
	cin>>k>>b>>n>>t;
	
	pw[0]=1;
	su[0]=0;
	for(int i=1;i<=n;++i){
		pw[i]=pw[i-1]*k;
		su[i]=su[i-1]+pw[i-1];
	}

	num v0=pw[n]+su[n]*b;

	int m=n;
	while(m>0&&!(pw[m-1]*t+su[m-1]*b<v0))
		--m;

	cout<<m;

    return 0;
}