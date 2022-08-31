#pragma comment(linker,"/STACK:256000000")
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <complex>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cstdlib>
#include <cstring>
using namespace std;
#define bublic public:
#define sz(v) ((int)(v).size())
#define forn(i,n) for(int i=0;i<(n);++i)
#define forv(i,v) forn(i,sz(v))
#define pb push_back
#define mp make_pair
#define istr stringstream
#define fi first
#define se second
#define X first
#define Y second
#define clr(a) memset((a),0,sizeof(a))
#define clr2(a) memset((a),-1,sizeof(a))
#define y0 asdy0
#define y1 asdy1
#define j0 asdj0
#define j1 asdj1
#define next asdnext
#define prev asdprev
#define link asdlink
#define unlink asdunlink
#define left asdleft
#define right asdright
#define hash asdhash
#define all(v) (v).begin(),(v).end()
typedef long long lng;
typedef unsigned int uint;
typedef unsigned long long ulng;
typedef unsigned char uchar;
typedef long double ld;
typedef pair<int,int> PII;
typedef pair<ld,ld> PDD;
typedef pair<lng,lng> PLL;
typedef complex<double> com;
const ld PI=3.1415926535897932384626433832795;
const ld EPS=1e-3;
const int inf=1000000000;
const lng linf=1000000000000000000LL;
template<class T> inline T sqr(T x) { return x * x; }

struct segtree{
	int tree[410000];

	void clear(int a,int b,int k){
		tree[k]=0;
		if(b==a+1)
			return;
		int c=(a+b)/2;
		clear(a,c,k*2+1);
		clear(c,b,k*2+2);
	}

	void add(int p,int v,int a,int b,int k){
		tree[k]+=v;
		if(b==a+1){
			return;
		}
		int c=(a+b)/2;
		if(p<c)
			add(p,v,a,c,k*2+1);
		else
			add(p,v,c,b,k*2+2);
	}

	int getsum(int l,int r,int a,int b,int k){
		if(r<=l||r<=a||l>=b)
			return 0;
		if(l<=a&&r>=b)
			return tree[k];
		int c=(a+b)/2;
		return getsum(l,r,a,c,k*2+1)+getsum(l,r,c,b,k*2+2);
	}
};

int src0[110000];
int src[110000];
int n;
lng K;

void gen(int nn){
	n=nn;
	forn(i,n){
		src0[i]=rand()%10;
	}
	K=rand()%(n*(n-1)/2+1);
}

int vals[110000];
lng pref[110000];
lng suff[110000];
segtree tmp;
segtree tre1,tre2;

lng clever(){
	forn(i,n){
		src[i]=src0[i];
		vals[i]=src0[i];
	}
	sort(vals,vals+n);
	int c=unique(vals,vals+n)-vals;
	forn(i,n){
		src[i]=lower_bound(vals,vals+c,src[i])-vals;
	}

	tmp.clear(0,c,0);
	forn(i,n){
		pref[i+1]=pref[i]+tmp.getsum(src[i]+1,c,0,c,0);
		tmp.add(src[i],1,0,c,0);
	}
	tmp.clear(0,c,0);
	for(int i=n-1;i>=0;--i){
		suff[i]=suff[i+1]+tmp.getsum(0,src[i],0,c,0);
		tmp.add(src[i],1,0,c,0);
	}

	lng res=0;
	tre1.clear(0,c,0);
	tre2.clear(0,c,0);

	forn(i,n)
		tre2.add(src[i],1,0,c,0);
	lng cur=0;
	int a=0;
	for(int b=1;b<n;++b){
		cur-=tre1.getsum(src[b-1]+1,c,0,c,0);
		tre2.add(src[b-1],-1,0,c,0);
		while(a<b&&cur+pref[a]+suff[b]<=K){
			cur+=tre2.getsum(0,src[a],0,c,0);
			tre1.add(src[a],1,0,c,0);
			++a;
		}
		if(a){
			res+=a-1;
			if(cur+pref[a]+suff[b]<=K)
				++res;
		}
	}

	return res;
}

lng brute(){
	int r=0;
	for(int a=1;a<n;++a){
		for(int b=a;b<n;++b){
			vector<int> v(src0,src0+a);
			v.insert(v.end(),src0+b,src0+n);
			int c=0;
			forv(j,v)
				forn(i,j)
					if(v[j]<v[i])
						++c;
			if(c<=K)
				++r;
		}
	}
	return r;
}

void stress(){
	for(int nn=1;nn<=50;++nn){
		forn(qqq,10000){
			gen(nn);
			lng b=brute();
			lng r=clever();
			if(b!=r){
				cout<<"failed "<<nn<<' '<<qqq<<endl<<endl;
				cout<<n<<' '<<K<<endl;
				forn(i,n)
					cout<<src0[i]<<' ';
				exit(123);
			}
		}
	}
	cout<<"passed"<<endl;
}

int main() {
#ifdef __ASD__
    freopen("q.in","rt",stdin);freopen("q.out","wt",stdout);
#endif

	//stress();return 0;

	cin>>n>>K;
	forn(i,n){
		scanf("%d",src0+i);
	}
	cout<<clever();

	return 0;
}