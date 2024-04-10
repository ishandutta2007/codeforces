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
#define PLL pair<lng,lng> 
#define X first
#define Y second
#define unlink asdunlink
typedef unsigned char uchar;
typedef unsigned int uint;
inline int mymax(int a,int b){return a<b?b:a;}
inline int mymin(int a,int b){return a>b?b:a;}
inline lng mymax(lng a,lng b){return a<b?b:a;}
inline lng mymin(lng a,lng b){return a>b?b:a;}



int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
    //ios_base::sync_with_stdio(false);

	double s;
	PII as[3];
	cin>>s>>as[0].X>>as[1].X>>as[2].X;
	as[0].Y=0;
	as[1].Y=1;
	as[2].Y=2;
	sort(as,as+3);
	double res[3]={0};
	if(as[0].X){
		double cx1=-(as[0].X+as[2].X);
		double cy1=-as[0].X;
		double cf1=-s*as[0].X;
		double cx2=-as[1].X;
		double cy2=-(as[1].X+as[2].X);
		double cf2=-s*as[1].X;
		double d=cx1*cy2-cy1*cx2;
		res[0]=(cf1*cy2-cy1*cf2)/d;
		res[1]=(cx1*cf2-cf1*cx2)/d;
	}else if(as[1].X){
		res[1]=s/(1+1.*as[2].X/as[1].X);
	}

	res[2]=s-res[0]-res[1];
	double r[3];
	forn(i,3)
		r[as[i].Y]=res[i];
	forn(i,3)
		printf("%.15lf  ",r[i]);

    return 0;
}