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
using namespace std;
#define forn(i,n) for(int i=0;i<(n);++i)
#define forv(i,v) forn(i,(int)(v).size())
#define iinf 1000000000
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
typedef unsigned char uchar;
typedef unsigned int uint;

pair<double,int> evs[1000000];
double res[110000];
int cnt;

int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
    //ios_base::sync_with_stdio(false);

	int n;
	double l,v1,v2;
	cin>>n>>l>>v1>>v2;
	double s=l*v2/(v1+v2);
	forn(i,n){
		double x;
		scanf("%lf",&x);
		if(x-s>=0){
			evs[cnt++]=mp(x-s,1);
			evs[cnt++]=mp(x,-1);
		}else{
			evs[cnt++]=mp(0,1);
			evs[cnt++]=mp(x,-1);
			evs[cnt++]=mp(l*2+x-s,1);
		}
	}
	evs[cnt++]=mp(0,0);
	evs[cnt++]=mp(l*2,0);

	sort(evs,evs+cnt);

	int d=0;
	for(int i=0;i<cnt-1;++i){
		d+=evs[i].Y;
		res[d]+=(evs[i+1].X-evs[i].X)/(l*2);
	}

	forn(i,n+1){
		printf("%.15lf\n",res[i]);
	}

    return 0;
}