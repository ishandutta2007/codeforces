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

lng doit(string p,int n){
	if(n==p.size())
		return p[0]==p[p.size()-1]?1:0;
	lng r=1;
	forn(i,n-(int)p.size()-1)
		r*=10;
	return r;
}

lng doit(lng a){
	stringstream ss;
	ss<<a;
	string s=ss.str();
	int n=s.size();
	lng r=0;
	for(int l=1;l<n;++l){
		for(char v='1';v<='9';++v)
			r+=doit(string()+v,l);
	}
	string p;
	forn(i,n){
		p+='0';
		for(char v=i?'0':'1';v<s[i];++v){
			p[p.size()-1]=v;
			r+=doit(p,n);
		}
		p[p.size()-1]=s[i];
	}
	return r;
}

int main(){
#ifdef __ASD__
	freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
	//ios_base::sync_with_stdio(false);

	lng a,b;
	cin>>a>>b;
	++b;
	cout<<doit(b)-doit(a);

	return 0;
}