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
#define fors(i,s) forn(i,(int)(s).length())
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define mp make_pair
#define EQ(a,b) (fabs((a)-(b))<eps)
#define SQ(a) ((a)*(a))
#define index asdindex
#define prev asdprev
#define X first
#define Y second
#define unlink asdunlink
#define div asddiv
#define tr1 asdtr1
#define y0 asdy0
typedef unsigned char uchar;
typedef unsigned int uint;
typedef long long lng;
typedef pair<int,int> PII;
typedef pair<lng,lng> PLL;
typedef pair<double,double> PDD;
const int iinf=1000000000;
const lng linf=1000000000000000000LL;
const double dinf=1e200;
const double eps=1e-16;
const double PI=3.14159265359;
inline int mymax(int a,int b){return a<b?b:a;}
inline int mymin(int a,int b){return a>b?b:a;}
inline lng mymax(lng a,lng b){return a<b?b:a;}
inline lng mymin(lng a,lng b){return a>b?b:a;}
inline lng myabs(lng a){return a<0?-a:a;}
int gcd(int a,int b){return a?gcd(b%a,a):b;}
lng gcd(lng a,lng b){return a?gcd(b%a,a):b;}

int src[510000];

PII tree[4000000];

void build(int a,int b,int k){
	if(b==a+1){
		tree[k]=mp(src[a],a);
		return;
	}
	int c=(a+b)/2;
	build(a,c,k*2+1);
	build(c,b,k*2+2);
	tree[k]=min(tree[k*2+1],tree[k*2+2]);
}

PII getmin(int l,int r,int a,int b,int k){
	if(r<=a||l>=b)
		return mp(iinf,-1);
	if(l<=a&&r>=b)
		return tree[k];
	int c=(a+b)/2;
	return min(getmin(l,r,a,c,k*2+1),getmin(l,r,c,b,k*2+2));
}

int jmp[510000][20];
int dep[510000];

int main(){
#ifdef __ASD__
	freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(false);
	
	int n;
	cin>>n;
	forn(i,n){
		cin>>src[i];
		src[i]=i-src[i];
		src[i+n]=src[i]+n;
	}
	
	build(0,n*2,0);
	lng res=0;
	
	for(int i=1;i<n*2;++i){
		int v=src[i];
		int p=getmin(v,i,0,n*2,0).Y;
		if(p==-1)
			exit(123);
		jmp[i][0]=p;
		dep[i]=dep[p]+1;
		forn(j,19){
			jmp[i][j+1]=jmp[jmp[i][j]][j];
		}
		if(i>=n){
			int t=i;
			for(int j=19;j>=0;--j){
				if(src[jmp[t][j]]>i-n+1)
					t=jmp[t][j];
			}
			res+=dep[i]-dep[t]+1;
			if(src[t]>i-n+1)
				++res;
		}
	}
	
	cout<<res;
	
	return 0;
}