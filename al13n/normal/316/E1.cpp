#pragma comment(linker, "/STACK:512000000")
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <climits>
#include <ctime>
#include <numeric>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <complex>
#include <deque>
#include <functional>
#include <list>
#include <map>
#include <string>
#include <sstream>
#include <set>
#include <stack>
#include <queue>
using namespace std;
template<class T> inline T sqr(T x) { return x * x; }
template<class T> inline string tostr(const T & x) { stringstream ss; ss << x; return ss.str(); }
typedef long long lng;
typedef unsigned long long ulng;
typedef unsigned int uint;
typedef unsigned char uchar;
typedef double ld;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;
typedef pair<int, lng> PLL;
typedef pair<lng, int> PLI;
typedef pair<ld, ld> PDD;
#define left asdleft
#define right asdright
#define link asdlink
#define unlink asdunlink
#define next asdnext
#define prev asdprev
#define y0 asdy0
#define y1 asdy1
#define mp make_pair
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define clr(ar,val) memset(ar, val, sizeof(ar))
#define istr stringstream
#define forn(i,n) for(int i=0;i<(n);++i)
#define forv(i,v) forn(i,sz(v))
#define X first
#define Y second
#define hash asdhash
#define move asdmove
#define pow10 asdpow10
const double EPS = 1e-6;
const int INF = 1000*1000*1000;
const char CINF = 102;
const lng LINF = INF * 1ll * INF;
const ld PI = 3.1415926535897932384626433832795;
lng gcd(lng a,lng b){return a?gcd(b%a,a):b;}
uint gcd(uint a,uint b){return a?gcd(b%a,a):b;}

const lng mod=INF;
lng fmat[210000][2][2];
lng fsum[210000];
lng tree[810000][3];

void pre(int a,int b,int k){
	if(!tree[k][2])
		return;
	lng v=tree[k][2];
	tree[k][2]=0;
	(tree[k][0]+=fsum[b-a]*v)%=mod;
	(tree[k][1]+=(fsum[b-a+1]+mod-1)*v)%=mod;
	if(b==a+1)
		return;
	(tree[k*2+1][2]+=v)%=mod;
	(tree[k*2+2][2]+=v)%=mod;
}

void post(int a,int b,int k){
	int c=(a+b)/2;
	pre(a,c,k*2+1);
	pre(c,b,k*2+2);
	tree[k][0]=(tree[k*2+1][0]+tree[k*2+2][0]*fmat[c-a][0][0]+tree[k*2+2][1]*fmat[c-a][0][1])%mod;
	tree[k][1]=(tree[k*2+1][1]+tree[k*2+2][0]*fmat[c-a][1][0]+tree[k*2+2][1]*fmat[c-a][1][1])%mod;
}

void add(int l,int r,lng v,int a,int b,int k){
	if(b<=l||a>=r)
		return;
	if(a>=l&&b<=r){
		(tree[k][2]+=v)%=mod;
		return;
	}
	pre(a,b,k);
	int c=(a+b)/2;
	add(l,r,v,a,c,k*2+1);
	add(l,r,v,c,b,k*2+2);
	post(a,b,k);
}

lng getsum(int l,int r,int a,int b,int k){
	if(b<=l||a>=r)
		return 0;
	pre(a,b,k);
	if(a>=l&&b<=r){
		lng *as=tree[k];
		lng *bs=fmat[a-l][0];
		return (as[0]*bs[0]+as[1]*bs[1])%mod;
	}
	int c=(a+b)/2;
	return (getsum(l,r,a,c,k*2+1)+getsum(l,r,c,b,k*2+2))%mod;
}

lng ar[1000];
void brute_add(int a,int b,lng v){
	for(int i=a;i<b;++i){
		(ar[i]+=v)%=mod;
	}
}
lng brute_sum(int a,int b){
	lng f1=1,f2=1;
	lng s=0;
	for(int i=a;i<b;++i){
		(s+=f1*ar[i])%=mod;
		lng t=f2;
		(f2+=f1)%=mod;
		f1=t;
	}
	return s;
}

void stress(){
	for(int n=3;n<100;++n){
		for(int m=1;m<100;++m){
			cerr<<n<<' '<<m<<endl;
			forn(qqq,10000){
				memset(ar,0,sizeof(ar));
				memset(tree,0,10000);
				forn(q,m){
					int a=rand()%n;
					int b=rand()%n;
					if(b<a)
						swap(a,b);
					++b;
					if(rand()%2==0){
						int v=rand();
						brute_add(a,b,v);
						add(a,b,v,0,n,0);
					}else{
						lng br=brute_sum(a,b);
						lng r=getsum(a,b,0,n,0);
						if(r!=br){
							cout<<"failed "<<n<<' '<<m<<' '<<q<<": "<<br<<" "<<r<<endl;
							return;
						}
					}
				}
			}
		}
	}
	cout<<"passed"<<endl;
}

int main() {
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
	
	{
		lng m[2][2]={{1,0},{0,1}};
		lng s=0;
		forn(i,205000){
			forn(a,2){
				forn(b,2){
					fmat[i][a][b]=m[a][b];
				}
			}
			fsum[i]=s;
			lng f=(m[0][0]+m[0][1])%mod;
			(s+=f)%=mod;
			m[0][0]=fmat[i][1][0];
			m[0][1]=fmat[i][1][1];
			m[1][0]=(fmat[i][0][0]+fmat[i][1][0])%mod;
			m[1][1]=(fmat[i][0][1]+fmat[i][1][1])%mod;
		}
	}
	
	//stress();return 0;
	
	int n,m;
	cin>>n>>m;
	forn(i,n){
		int a;
		scanf("%d",&a);
		add(i,i+1,a,0,n,0);
	}
	forn(i,m){
		int t;
		scanf("%d",&t);
		if(t==1){
			int x,v;
			scanf("%d%d",&x,&v);
			--x;
			lng y=getsum(x,x+1,0,n,0);
			add(x,x+1,v-y+mod,0,n,0);
		}else if(t==2){
			int a,b;
			scanf("%d%d",&a,&b);
			--a;
			printf("%d\n",(int)getsum(a,b,0,n,0));
		}else{
			int a,b,v;
			scanf("%d%d%d",&a,&b,&v);
			--a;
			add(a,b,v,0,n,0);
		}
	}
	
	return 0;
}