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

lng dp[15][15];
lng cnt[15];
lng cnt2[15];
const lng mod=inf+7;

void doit(lng &t,lng &c){
	if(!c){
		t=0;
		return;
	}
	t=t*c%mod;
	--c;
}

int main() {
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
	
	dp[0][0]=1;
	for(int i=1;i<13;++i){
		for(int j=0;j<13;++j){
			for(int d=0;d<=9;++d){
				if(d==4||d==7){
					if(j)
						dp[i][j]+=dp[i-1][j-1];
				}else{
					dp[i][j]+=dp[i-1][j];
				}
			}
		}
	}
	
	lng m;
	cin>>m;
	++m;
	stringstream ss;
	ss<<m;
	string s=ss.str();
	lng c=0;
	forv(i,s){
		for(int d=0;d+'0'<s[i];++d){
			lng cc=c;
			if(d==4||d==7)
				++cc;
			forn(j,13){
				if(j>=cc)
					cnt[j]+=dp[sz(s)-i-1][j-cc];
			}
		}
		if(s[i]=='4'||s[i]=='7')
			++c;
	}
	--cnt[0];
	
	int sum=0;
	forn(i,13){
		sum+=cnt[i];
	}
	if(sum!=m-1){
		cout<<"UPCHK!"<<endl;
		exit(33);
	}
	
	lng res=0;
	forn(i1,10){
		forn(i2,i1){
			forn(i3,i1-i2){
				forn(i4,i1-i2-i3){
					forn(i5,i1-i2-i3-i4){
						forn(i6,i1-i2-i3-i4-i5){
							forn(i7,i1-i2-i3-i4-i5-i6){
								forn(i,10){
									cnt2[i]=cnt[i];
								}
								lng t=1;
								doit(t,cnt2[i1]);
								doit(t,cnt2[i2]);
								doit(t,cnt2[i3]);
								doit(t,cnt2[i4]);
								doit(t,cnt2[i5]);
								doit(t,cnt2[i6]);
								doit(t,cnt2[i7]);
								if(t>0){
									res=(res+t)%mod;
								}
							}
						}
					}
				}
			}
		}
	}
	cout<<res;
	
	return 0;
}