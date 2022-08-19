#pragma comment(linker,"/STACK:256000000")
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
#include <memory.h>
using namespace std;
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
#define clr(a,v) memset((a),(v),sizeof(a))
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
#define div asddiv
#define all(v) (v).begin(),(v).end()
typedef long long lng;
typedef unsigned int uint;
typedef unsigned long long ulng;
typedef unsigned char uchar;
typedef double ld;
typedef pair<int,int> PII;
typedef pair<ld,ld> PDD;
typedef pair<lng,lng> PLL;
typedef complex<double> com;
const ld PI=3.1415926535897932384626433832795;
const ld EPS=1e-12;
const int inf=1000000000;
const lng linf=1000000000000000000LL;
template<class T> inline T sqr(T x) { return x * x; }
int gcd(int a,int b){return a?gcd(b%a,a):b;}
lng gcd(lng a,lng b){return a?gcd(b%a,a):b;}

int tree[510000];

void setv(int p,int v,int a,int b,int k){
	if(b==a+1){
		tree[k]=v;
		return;
	}
	int c=(a+b)/2;
	if(p<c)
		setv(p,v,a,c,k*2+1);
	else
		setv(p,v,c,b,k*2+2);
	tree[k]=max(tree[k*2+1],tree[k*2+2]);
}

int getmax(int l,int r,int a,int b,int k){
	if(l<=a&&r>=b)
		return tree[k];
	if(r<=a||l>=b)
		return 0;
	int c=(a+b)/2;
	return max(getmax(l,r,a,c,k*2+1),getmax(l,r,c,b,k*2+2));
}

const int B=201000;
int dp[110000];
int hei[110000];
int pos[310000];
set<int> anset[110000];
set<int> allset;

int main() {
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif

	clr(pos,-1);
	int n,m;
	cin>>n>>m;
	forn(qqq,m){
		int type;
		scanf("%d",&type);
		if(type==1){
			int p,h;
			scanf("%d%d",&p,&h);
			--p;
			h+=m-qqq;
			hei[p]=h;
			pos[h]=p;
			allset.insert(p);
			vector<int> small;
			for(int hh=h;hh>=h-20 && hh>=0;--hh){
				if(pos[hh]!=-1)
					small.pb(pos[hh]);
			}
			small.pb(n);
			sort(all(small));
			int mx=0;
			for(int i=sz(small)-2;i>=0;--i){
				int pp=small[i];
				mx=max(mx,getmax(pp+1,small[i+1],0,n,0));
				int r=mx;
				for(int j=i+1;j<sz(small)-1;++j){
					int ppp=small[j];
					if(hei[ppp]>hei[pp])
						r=max(r,dp[ppp]);
				}
				++r;
				if(pp==p || r!=dp[pp]){
					if(r<dp[pp])
						exit(33);
					anset[dp[pp]].erase(pp);
					dp[pp]=r;
					anset[dp[pp]].insert(pp);
					setv(pp,r,0,n,0);
				}
			}
		}else{
			int x;
			scanf("%d",&x);
			--x;
			vector<int> ps;
			
			set<int>::iterator it=allset.begin();
			forn(qq,x){
				if(it==allset.end())
					exit(44);
				ps.pb(*it);
				++it;
			}
			if(it==allset.end())
				exit(44);
			int p=*it;
			
			for(int i=sz(ps)-1;i>=0;--i){
				int pp=ps[i];
				int d=dp[pp];
				if(d>1){
					bool ok=false;
					for(set<int>::iterator it=anset[d-1].begin();it!=anset[d-1].end();++it){
						int ppp=*it;
						if(ppp>pp && ppp!=p){
							if(hei[ppp]>hei[pp])
								ok=true;
							break;
						}
					}
					if(!ok){
						anset[dp[pp]].erase(pp);
						--dp[pp];
						anset[dp[pp]].insert(pp);
						setv(pp,dp[pp],0,n,0);
					}
				}
			}
			
			pos[hei[p]]=-1;
			anset[dp[p]].erase(p);
			allset.erase(p);
			setv(p,0,0,n,0);
			hei[p]=0;
			dp[p]=0;
		}
		
		/*
		cout<<endl;
		forn(i,n){
			cout<<hei[i]<<' ';
		}
		cout<<endl;
		forn(i,m+12){
			if(pos[i]!=-1)
				cout<<i<<":"<<pos[i]<<' ';
		}
		cout<<endl;
		forn(i,n){
			cout<<dp[i]<<' ';
		}
		cout<<endl;//*/
		
		printf("%d\n",getmax(0,n,0,n,0));
	}

	return 0;
}