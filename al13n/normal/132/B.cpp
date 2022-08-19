#pragma comment(linker,"/STACK:256000000")
#include <vector>
#include <cstring>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <queue>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <stdlib.h>
#include <ctime>
#include <string>
#include <complex>
#include <memory.h>
using namespace std;
#define all(a) a.begin(),a.end()
#define forn(i,n) for(int i=0;i<(n);++i)
#define fornn(i,n) for(i=0;i<(n);++i)
#define lng long long
#define SQ(a) ((a)*(a))
#define forv(i,v) for(int i=0;i<(int)v.size();++i)
#define mp make_pair
#define pb push_back
#define ABS(a) ((a)<0?-(a):(a))
#define iinf 1000000000
#define linf SQ(1LL*iinf)
#define left asdleft
#define prev asdprev
#define hash asdhash
#define div asddiv
#define time asdtime
#define eps 1e-9
#define y1 asdy1
#define y2 asdy2
#define EQ(a,b) abs((a)-(b))<eps
#define PI 3.1415926535897932384626433832795
#define DEG2RAD PI/180
#define ulng unsigned lng
const double dinf = 1e200;
void ext(int c){
#ifdef __ASD__
    exit(c);
#endif
}

char src[100][100];
int ind[100][100];
int anya[10000];
int anyb[10000];
int da[4]={0,1,0,-1};
int db[4]={1,0,-1,0};
int go[10000*8];
int n;
int K;

#define taska "vigenere"
int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#else
    //freopen(taska".in","r",stdin);freopen(taska".out","w",stdout);
#endif

    //ios_base::sync_with_stdio(false);

	cin>>n>>K;
	gets(src[0]);
	forn(i,n)
		gets(src[i+1]+1);
	memset(ind,-1,sizeof(ind));
	int c=0;
	int m=strlen(src[1]+1);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(ind[i][j]!=-1||src[i][j]=='0')
				continue;
			anya[c]=i;
			anyb[c]=j;
			for(int a=i;src[a][j]==src[i][j];++a)
				for(int b=j;src[a][b]==src[i][j];++b)
					ind[a][b]=c;
			++c;
		}
	}

	forn(p,c){
		forn(ds,8){
			int d=ds/2;
			int dd=(d+(ds%2*2-1)+4)%4;
			int a=anya[p];
			int b=anyb[p];
			while(src[a+da[d]][b+db[d]]==src[a][b])
				a+=da[d],b+=db[d];
			while(src[a+da[dd]][b+db[dd]]==src[a][b])
				a+=da[dd],b+=db[dd];
			int ni=ind[a+da[d]][b+db[d]];
			if(ni==-1)
				go[p*8+ds]=p*8+(ds+1)%8;
			else
				go[p*8+ds]=ni*8+ds;
		}
	}

	int v=ind[1][1]*8+0;
	forn(i,K)
		v=go[v];

	cout<<src[anya[v/8]][anyb[v/8]];

    return 0;
}