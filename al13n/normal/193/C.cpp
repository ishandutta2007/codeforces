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
typedef unsigned char uchar;
typedef unsigned int uint;
inline int mymax(int a,int b){return a<b?b:a;}
inline int mymin(int a,int b){return a>b?b:a;}
inline lng mymax(lng a,lng b){return a<b?b:a;}
inline lng mymin(lng a,lng b){return a>b?b:a;}

inline lng abs(lng a){
	return a<0?-a:a;
}

lng gcd(lng a,lng b){
	return a?gcd(b%a,a):b;
}

lng ar[6][8];
lng v[7];
lng bs;
lng bv[7];

int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(false);

	forn(i,6)
		cin>>ar[i][7];
	const int ps[]={3,4,5,6,  1,2,5,6,  0,2,4,6,  1,2,3,4,  0,2,3,5,  0,1,4,5};
	forn(i,4*6)
		ar[i/4][ps[i]]=1;
	forn(i,6){
		int b=-1;
		for(int j=i;j<6;++j)
			if(ar[j][i]){
				b=j;
				break;
			}
		forn(j,8)
			swap(ar[i][j],ar[b][j]);
		forn(j,6){
			if(j==i||!ar[j][i])
				continue;
			lng v=abs(ar[i][i]*ar[j][i])/gcd(abs(ar[i][i]),abs(ar[j][i]));
			lng ci=v/ar[i][i];
			lng cj=v/ar[j][i];
			forn(k,8)
				ar[j][k]=ar[j][k]*cj-ar[i][k]*ci;
		}
	}

	forn(i,6){
		forn(j,8)
			cerr<<ar[i][j]<<' ';
		cerr<<endl;
	}

	bs=linf;
	for(v[6]=0;v[6]<=100000;++v[6]){
		bool ok=true;
		lng s=0;
		forn(i,7){
			if(i<6){
				lng t=ar[i][7]-v[6]*ar[i][6];
				if(t%abs(ar[i][i])){
					ok=false;
					break;
				}
				v[i]=t/ar[i][i];
			}
			if(v[i]<0){
				ok=false;
				break;
			}
			s+=v[i];
		}
		if(ok&&s<bs){
			bs=s;
			forn(i,7)
				bv[i]=v[i];
		}
	}

	if(bs==linf){
		cout<<-1;
		return 0;
	}

	if(bs>1000000)
		exit(123);

	string r[4];
	forn(i,(int)bv[0])
		r[0]+='a',r[1]+='a',r[2]+='a',r[3]+='b';
	forn(i,(int)bv[1])
		r[0]+='a',r[1]+='a',r[2]+='b',r[3]+='a';
	forn(i,(int)bv[2])
		r[0]+='a',r[1]+='a',r[2]+='b',r[3]+='b';
	forn(i,(int)bv[3])
		r[0]+='a',r[1]+='b',r[2]+='a',r[3]+='a';
	forn(i,(int)bv[4])
		r[0]+='a',r[1]+='b',r[2]+='a',r[3]+='b';
	forn(i,(int)bv[5])
		r[0]+='a',r[1]+='b',r[2]+='b',r[3]+='a';
	forn(i,(int)bv[6])
		r[0]+='a',r[1]+='b',r[2]+='b',r[3]+='b';

	cout<<bs<<'\n'<<r[0]<<'\n'<<r[1]<<'\n'<<r[2]<<'\n'<<r[3];

    return 0;
}