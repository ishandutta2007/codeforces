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

int n;
lng ar[110000];
lng len[2][2][110000];

int main(){
#ifdef __ASD__
	freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
	//ios_base::sync_with_stdio(false);

	cin>>n;
	forn(i,n-1)
		cin>>ar[i];

	forn(qq,2){
		forn(i,n-1){
			len[qq][0][i+1]=(ar[i]<=1)?0:(ar[i]/2*2+len[qq][0][i]);
			len[qq][1][i+1]=max(len[qq][0][i+1],(ar[i]==0)?0:((ar[i]-1)/2*2+1+len[qq][1][i]));
		}
		reverse(ar,ar+n-1);
	}
	reverse(len[1][0],len[1][0]+n);
	reverse(len[1][1],len[1][1]+n);

	lng res=0;
	forn(i,n){
		res=max(res,max(len[0][0][i]+len[1][1][i],len[0][1][i]+len[1][0][i]));
	}

	cout<<res;

	return 0;
}