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

char src[55][55];
bool was[55][55];
int n,m;
int cnt;

int dfs(int a,int b){
	was[a][b]=true;
	const int da[]={0,0,-1,1};
	const int db[]={-1,1,0,0};
	int r=1;
	forn(d,4){
		int aa=a+da[d];
		int bb=b+db[d];
		if(aa<0||bb<0||aa>=n||bb>=m||was[aa][bb]||src[aa][bb]=='.')
			continue;
		r+=dfs(aa,bb);
	}
	return r;
}

bool conn(){
	memset(was,0,sizeof(was));
	forn(i,n){
		forn(j,m){
			if(src[i][j]=='#'){
				return dfs(i,j)==cnt-1;
			}
		}
	}
	return true;
}

int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
    //ios_base::sync_with_stdio(false);

	cin>>n>>m;
	gets(src[0]);
	forn(i,n){
		gets(src[i]);
		forn(j,m)
			if(src[i][j]=='#')
				++cnt;
	}

	if(cnt<=2){
		cout<<-1;
		return 0;
	}

	forn(i,n){
		forn(j,m){
			if(src[i][j]=='#'){
				src[i][j]='.';
				if(!conn()){
					cout<<1;
					return 0;
				}
				src[i][j]='#';
			}
		}
	}

	cout<<2;

    return 0;
}