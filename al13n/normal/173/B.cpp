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
using namespace std;
#define forn(i,n) for(int i=0;i<(n);++i)
#define forv(i,v) forn(i,(int)(v).size())
#define iinf 1000000000
#define linf 1000000000000000000LL
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define mp make_pair
#define lng long long
#define eps 1e-10
#define EQ(a,b) (fabs((a)-(b))<eps)
#define SQ(a) ((a)*(a))
#define PI 3.14159265359
#define index asdindex
#define FI first
#define SE second
#define prev asdprev
#define PII pair<int,int> 
#define X first
#define Y second
#define unlink asdunlink
typedef unsigned char uchar;
typedef unsigned int uint;

char src[1100][1100];
int dist[1100][1100][4];
const int da[4]={0,0,-1,1};
const int db[4]={-1,1,0,0};
const int qul=4100000;
pair<PII,int> qu[qul];
int qu1,qu2;
int n,m;

void push_front(int a,int b,int d){
	--qu1;
	if(qu1<0)
		qu1=qul-1;
	qu[qu1]=mp(mp(a,b),d);
}

void push_back(int a,int b,int d){
	qu[qu2]=mp(mp(a,b),d);
	++qu2;
	if(qu2==qul)
		qu2=0;
}

void pop_front(int &a,int &b,int &d){
	a=qu[qu1].X.X;
	b=qu[qu1].X.Y;
	d=qu[qu1].Y;
	++qu1;
	if(qu1==qul)
		qu1=0;
}

bool empty(){
	return qu1==qu2;
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
	}

	qu1=qu2=2000000;
	dist[0][0][1]=1;
	push_front(0,0,1);

	while(!empty()){
		int a,b,d;
		pop_front(a,b,d);
		if(src[a][b]=='#'){
			forn(dd,4){
				if(!dist[a][b][dd]){
					dist[a][b][dd]=dist[a][b][d]+1;
					push_back(a,b,dd);
				}
			}
		}
		int aa=a+da[d];
		int bb=b+db[d];
		if(aa>=0&&aa<n&&bb>=0&&bb<m&&!dist[aa][bb][d]){
			dist[aa][bb][d]=dist[a][b][d];
			push_front(aa,bb,d);
		}
	}

	cout << dist[n-1][m-1][1]-1;

    return 0;
}