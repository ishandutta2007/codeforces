#pragma comment(linker,"/STACK:1024000000")
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
#include <cstdlib>
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
#define div asddiv
#define divides asddivides
typedef unsigned char uchar;
typedef unsigned int uint;
typedef unsigned lng ulng;
inline int mymax(int a,int b){return a<b?b:a;}
inline int mymin(int a,int b){return a>b?b:a;}
inline lng mymax(lng a,lng b){return a<b?b:a;}
inline lng mymin(lng a,lng b){return a>b?b:a;}
inline lng abs(lng a){return a<0?-a:a;}
#ifdef __ASD__
#define LOG(x) cerr<<x<<endl
#else
#define LOG(x)
#endif



int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
    //ios_base::sync_with_stdio(false);

	string s;
	cin>>s;
	string r;
	int p=0;
	for(char c='z';c>='a';--c){
		for(int i=p;i<(int)s.length();++i)
			if(s[i]==c){
				r+=c;
				p=i;
			}
	}
	cout<<r;

    return 0;
}