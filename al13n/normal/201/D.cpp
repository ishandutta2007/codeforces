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

int n,m;
map<string,int> words;
vector<int> src[11];
char tmp[1000000];
int dp[1<<15][15*14/2+10];
int nxt[510000][15];

inline int bitcnt(int a){
	int r=0;
	while(a){
		r+=a&1;
		a>>=1;
	}
	return r;
}

int similarity(const vector<int> ar){
	int l=(int)ar.size();
	forn(i,n)
		nxt[l+1][i]=nxt[l][i]=l+1;
	for(int i=l-1;i>=0;--i){
		forn(j,n)
			nxt[i][j]=nxt[i+1][j];
		nxt[i][ar[i]]=i+1;
	}

	forn(i,1<<n)
		forn(j,n*(n-1)/2+1)
			dp[i][j]=l+1;

	dp[0][0]=0;

	forn(m,1<<n){
		forn(i,n*(n-1)/2+1){
			int p=dp[m][i];
			if(p==l+1)
				continue;
			forn(v,n){
				if(m&(1<<v))
					continue;
				int q=nxt[p][v];
				if(q==l+1)
					continue;
				int &t=dp[m|(1<<v)][i+bitcnt(m&((1<<v)-1))];
				if(q<t)
					t=q;
			}
		}
	}

	forn(i,n*(n-1)/2+1)
		if(dp[(1<<n)-1][i]<l+1)
			return n*(n-1)/2+1-i;

	return 0;
}

int main(){
#ifdef __ASD__
	freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
	//ios_base::sync_with_stdio(false);

	cin>>n;
	forn(i,n){
		string s;
		cin>>s;
		words[s]=n-1-i;
	}

	cin>>m;
	string stmp;
	stmp.reserve(500000);
	forn(i,m){
		int k;
		cin>>k;
		forn(j,k){
			scanf("%s",tmp);
			stmp=tmp;
			if(words.count(stmp))
				src[i].pb(words[stmp]);
		}
	}

	PII res(0,0);
	forn(i,m)
		res=max(res,mp(similarity(src[i]),-i));

	if(res.X){
		cout<<-res.Y+1<<"\n[:";
		forn(i,res.X)
			cout<<"|";
		cout<<":]";
	}else{
		cout<<"Brand new problem!";
	}

	return 0;
}