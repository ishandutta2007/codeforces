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
#define pow10 asdpow10
#define pos asdpos
typedef unsigned char uchar;
typedef unsigned int uint;
typedef long long lng;
typedef unsigned long long ulng;
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

int n;
vector<int> gr0[210];
vector<int> gr[210];
int in0[210];
int in[210];
int col[210];

int solve(int c){
	int l=n;
	vector<int> v[3];
	forn(i,n){
		in[i]=in0[i];
		gr[i]=gr0[i];
		if(!in[i])
			v[col[i]].pb(i);
	}
	int r=n-1;
	while(l){
		++r;
		while(v[c].size()){
			int a=v[c].back();
			v[c].pop_back();
			--l;
			forv(i,gr[a]){
				int p=gr[a][i];
				--in[p];
				if(!in[p])
					v[col[p]].pb(p);
			}
		}
		c=(c+1)%3;
	}
	return r;
}

int main(){
#ifdef __ASD__
	freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
	//ios_base::sync_with_stdio(false);

	cin>>n;
	forn(i,n){
		cin>>col[i];
		--col[i];
	}
	forn(i,n){
		int k;
		cin>>k;
		forn(j,k){
			int a;
			cin>>a;
			--a;
			gr0[a].pb(i);
			++in0[i];
		}
	}

	int r=iinf;
	forn(i,3)
		r=min(r,solve(i));

	cout<<r;

	return 0;
}