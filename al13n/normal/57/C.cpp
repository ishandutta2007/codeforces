#pragma comment(linker,"/STACK:228000000")
#include <vector>
#include <string.h>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <queue>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <stdlib.h>
#include <ctime>
#include <limits>
using namespace std;
#define forn(i,n) for(int i=0;i<n;++i)
#define fornr(i,n) for(int i=(n)-1;i>=0;--i)
#define forv(i,v) forn(i,(int)v.size())
#define time asdtime
#define pb push_back
#define lng long long
#define mp make_pair
#define iinf 1000000000
#define prev asdprev
#define next asdnext
#define all(v) v.begin(),v.end()
#define SQ(a) ((a)*(a))
#define eps 1e-8
#define y1 asdy1
#define y2 asdy2

lng gcdex(lng a,lng b,lng &x,lng &y){
	if(!a){
		x=0;
		y=1;
		return b;
	}
	lng k=b/a;
	lng g=gcdex(b-k*a,a,y,x);
	x-=k*y;
	return g;
}

const lng mod=1000000007;

lng divide(lng a,lng b){
	lng x,y;
	if(gcdex(b,mod,x,y)!=1)
		exit(123);
	return ((a*x)%mod+mod)%mod;
}

int main(int argc,char **argv){
#ifdef __ASD__
	freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif

	int n;
	cin>>n;
	lng r=1;
	for(int i=n+1;i<2*n;++i)
		r=(r*i)%mod;
	for(int i=2;i<=n-1;++i)
		r=divide(r,i);
	cout<<((r*2-n)%mod+mod)%mod;

	return 0;
}