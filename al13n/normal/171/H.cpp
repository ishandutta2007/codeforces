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

PII doit(int a,int b){
	if(b<0)
		exit(123);
	if(!b)
		return mp(0,0);
	int l=(1<<(2*a))-1;
	int s=(1<<a)-1;
	if(b==l)
		return mp(s,0);
	if(b>l)
		exit(123);
	if(b>l/2){
		PII t=doit(a,l-b);
		t.X=s-t.X;
		return t;
	}
	if(b<=l/4){
		PII t=doit(a-1,b);
		swap(t.X,t.Y);
		return t;
	}else{
		PII t=doit(a-1,b-l/4-1);
		t.Y+=s/2+1;
		return t;
	}
}

int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
    //ios_base::sync_with_stdio(false);

	int a,b;
	cin>>a>>b;
	PII r=doit(a,b);
	cout<<r.X<<' '<<r.Y;

    return 0;
}