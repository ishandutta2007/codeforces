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

pair<pair<int,double>,int> ar[110000];
int res[110000];
int n,k;

bool check(double t){
	int p=0;
	forn(i,n){
		if(ar[i].X.Y*(p+1)<=t){
			res[p++]=ar[i].Y;
			if(p==k)
				break;
		}
	}
	return p==k;
}

int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(false);

	int h;
	cin>>n>>k>>h;

	forn(i,n){
		ar[i].Y=i+1;
		cin>>ar[i].X.X;
	}
	forn(i,n){
		cin>>ar[i].X.Y;
	}

	sort(ar,ar+n);
	
	forn(i,n){
		ar[i].X.Y = 1./ar[i].X.Y;
	}

	double a=0,b=iinf;

	forn(qqq,100){
		double t=(a+b)/2;
		if(check(t))
			b=t;
		else
			a=t;
	}
	check(b);

	forn(i,k){
		cout<<res[i]<<' ';
	}

    return 0;
}