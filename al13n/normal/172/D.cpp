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

const int lim=10010000;
int sq[lim];
bool unprime[lim];

int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(false);

	forn(i,lim){
		sq[i]=1;
	}

	for(int i=2;i*i<lim;++i){
		if(unprime[i])
			continue;
		for(int j=i+i;j*j<lim;j+=i)
			unprime[j]=true;
		int s=i*i;
		for(int j=s;j<lim;j+=s){
			sq[j]=sq[j/s]*s;
		}
	}

	int a,n;
	cin>>a>>n;
	lng r=0;
	forn(i,n){
		int v=a+i;
		if(v%sq[v])
			exit(123);
		r+=v/sq[v];
	}
	cout<<r;

    return 0;
}