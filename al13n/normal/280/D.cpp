#pragma comment(linker, "/STACK:256000000")
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
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
typedef pair<int, PII> PIII;
typedef pair<lng, lng> PLL;
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
const double EPS = 1e-10;
const int INF = 1000*1000*1000;
const lng LINF = INF * 1ll * INF;
const ld PI = 3.1415926535897932384626433832795;

const int lim=20;

void mx(int &a,int b){
	if(b>a)
		a=b;
}

struct node{
	int v[lim+1][2][2];
	int len;
	
	void clear(){
		forn(k,lim+1){
			forn(i,2){
				forn(j,2){
					v[k][i][j]=-INF;
				}
			}
		}
	}
	
	void calc(const node &a,const node &b){
		clear();
		len=a.len+b.len;
		for(int i=0;i<=lim && i+i<=a.len+1;++i){
			for(int j=0;i+j<=lim+1 && j+j<=b.len+1 && j<=lim;++j){
				if(i+j<=lim){
					mx(v[i+j][0][0],a.v[i][0][0]+b.v[j][0][0]);
					mx(v[i+j][0][1],a.v[i][0][0]+b.v[j][0][1]);
					mx(v[i+j][1][0],a.v[i][1][0]+b.v[j][0][0]);
					mx(v[i+j][1][1],a.v[i][1][0]+b.v[j][0][1]);
				}
				
				mx(v[i+j-1][0][0],a.v[i][0][1]+b.v[j][1][0]);
				mx(v[i+j-1][0][1],a.v[i][0][1]+b.v[j][1][1]);
				mx(v[i+j-1][1][0],a.v[i][1][1]+b.v[j][1][0]);
				mx(v[i+j-1][1][1],a.v[i][1][1]+b.v[j][1][1]);
			}
		}
		for(int k=0;k<=lim && k+k<=len+1;++k){
			mx(v[k][1][0],v[k][1][1]);
			mx(v[k][0][1],v[k][1][1]);
			mx(v[k][0][0],v[k][0][1]);
			mx(v[k][0][0],v[k][1][0]);
		}
	}
	
	void leaf(int a){
		clear();
		len=1;
		v[0][0][0]=0;
		v[1][1][1]=a;
		v[1][1][0]=v[1][0][1]=v[1][0][0]=max(a,0);
	}
};

node tree[410000];
int src[110000];

void init(int a,int b,int k){
	if(b==a+1){
		tree[k].leaf(src[a]);
		return;
	}
	int c=(a+b)/2;
	init(a,c,k*2+1);
	init(c,b,k*2+2);
	tree[k].calc(tree[k*2+1],tree[k*2+2]);
}

void setval(int p,int v,int a,int b,int k){
	if(b==a+1){
		tree[k].leaf(v);
		return;
	}
	int c=(a+b)/2;
	if(p<c)
		setval(p,v,a,c,k*2+1);
	else
		setval(p,v,c,b,k*2+2);
	tree[k].calc(tree[k*2+1],tree[k*2+2]);
}

node getmax(int l,int r,int a,int b,int k){
	if(l==a&&r==b){
		return tree[k];
	}
	int c=(a+b)/2;
	if(r<=c)
		return getmax(l,r,a,c,k*2+1);
	if(l>=c)
		return getmax(l,r,c,b,k*2+2);
	node t1=getmax(l,c,a,c,k*2+1);
	node t2=getmax(c,r,c,b,k*2+2);
	node t;
	t.calc(t1,t2);
	return t;
}

void gentest(){
	freopen("input.txt", "w", stdout);freopen("output.txt", "r", stdin);
	
	int n=100000;
	int m=100000;
	cout<<n;
	forn(i,n){
		if(i%1000==0)
			cout<<endl;
		cout<<rand()%1001-500<<' ';
	}
	cout<<m<<endl;
	forn(i,m){
		if(rand()%2){
		//if(false){
			cout<<"0 "<<rand()%n+1<<' '<<rand()%1001-500<<'\n';
		}else{
			int a=rand()%n+1;
			int b=rand()%n+1;
			if(b<a)
				swap(a,b);
			cout<<"1 "<<a<<' '<<b<<' '<<rand()%20+1<<'\n';
		}
	}
}

int main() {
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif

	int n;
	cin>>n;
	forn(i,n){
		scanf("%d",src+i);
	}
	
	init(0,n,0);
	
	int m;
	cin>>m;
	forn(qqq,m){
		int type,a,b;
		scanf("%d%d%d",&type,&a,&b);
		--a;
		if(!type){
			setval(a,b,0,n,0);
		}else{
			int k;
			scanf("%d",&k);
			node t=getmax(a,b,0,n,0);
			int res=0;
			forn(i,k+1){
				res=max(res,t.v[i][0][0]);
			}
			if(res<0 || res>100000*500){
				cout<<"failed"<<endl;
				exit(66);
			}
			printf("%d\n",res);
		}
	}
	
	return 0;
}