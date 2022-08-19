#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <memory.h>
#include <string>
#include <set>
#include <map>
#include <queue>
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
#define eps 1e-11
#define EQ(a,b) (fabs((a)-(b))<eps)
#define SQ(a) ((a)*(a))
#define PI 3.14159265359
#define index asdindex
#define FI first
#define SE second
#define prev asdprev
#define ends asdends
#define PII pair<int,int> 
#define X first
#define Y second
#define mset(a,b) memset(a,b,sizeof(a))

char S0[2100];
char S[10100];
char U[2100];
int n,m;

int main(){
#ifdef __ASD__
	freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
	//ios_base::sync_with_stdio(false);

	gets(S0);
	gets(U);
	n=strlen(S0);
	m=strlen(U);
	int c=m-1;
	forn(i,n){
		S[i+c]=S0[i];
	}
	forn(i,c){
		S[i]=S[c+n+i]='.';
	}
	n+=c+c;
	int res=iinf;
	forn(k,n-m+1){
		int v=0;
		forn(i,m){
			if(S[i+k]!=U[i])
				++v;
		}
		res=min(res,v);
	}
	cout<<res;

	return 0;
}