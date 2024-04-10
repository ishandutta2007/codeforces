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

char A[2100];
char B[2100];
int k;
int n;

const lng mod=iinf+7;

int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
    //ios_base::sync_with_stdio(false);

	gets(A);
	gets(B);
	cin>>k;
	n=strlen(A);
	
	lng d1=1,d2=0;
	forn(i,k){
		lng dd1=d1;
		lng dd2=d2;
		d1=dd2*(n-1)%mod;
		d2=(dd2*(n-2)+dd1)%mod;
	}

	memcpy(B+n,B,n);
	lng res=0;
	for(int i=n-1;i>=0;--i){
		B[i+n]=0;
		if(!strcmp(A,B+i))
			res=(res+(i?d2:d1))%mod;
	}
	cout<<res;

    return 0;
}