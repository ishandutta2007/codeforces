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

char A[1100];
char B[1100];
int m,k;
int n;

int doit(char a,char b){
	if(a==b)
		return 0;
	switch(a){
		case 'R':
			return b=='S'?1:-1;
		case 'S':
			return b=='P'?1:-1;
		case 'P':
			return b=='R'?1:-1;
		default:
			exit(123);
	}
}

int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
    //ios_base::sync_with_stdio(false);

	cin>>n;
	gets(A);
	gets(A);
	gets(B);
	m=strlen(A);
	k=strlen(B);

	int r[2]={0,0};
	for(int i=0;i<n&&i<m*k;++i){
		int d=doit(A[i%m],B[i%k]);
		if(d){
			int p=(d+1)/2;
			r[p]+=(n-i+m*k-1)/(m*k);
		}
	}
	cout<<r[0]<<' '<<r[1];

    return 0;
}