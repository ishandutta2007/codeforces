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



int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
    //ios_base::sync_with_stdio(false);

	int n,k;
	cin>>n>>k;
	lng b;
	cin>>b;
	vector<PII> ar(n-1);
	forn(i,n-1){
		cin>>ar[i].X;
		ar[i].Y=i+1;
	}
	sort(all(ar));
	reverse(all(ar));
	lng s=0;
	int mn=n;
	forn(i,k-1){
		s+=ar[i].X;
		mn=min(mn,ar[i].Y);
	}
	int res=n;
	if(b<s+ar[k-1].X)
		res=mn;
	for(int i=k-1;i<n-1;++i){
		if(b<s+ar[i].X)
			res=min(res,ar[i].Y);
	}
	cout<<res;

    return 0;
}