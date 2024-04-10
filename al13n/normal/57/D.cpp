#pragma comment(linker,"/STACK:228000000")
#include <vector>
#include <string.h>
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
#include <limits>
using namespace std;
#define forn(i,n) for(int i=0;i<n;++i)
#define fornr(i,n) for(int i=(n)-1;i>=0;--i)
#define forv(i,v) forn(i,(int)v.size())
#define time asdtime
#define pb push_back
#define lng long long
#define mp make_pair
#define iinf 1000000000
#define prev asdprev
#define next asdnext
#define all(v) v.begin(),v.end()
#define SQ(a) ((a)*(a))
#define eps 1e-8
#define y1 asdy1
#define y2 asdy2

char src[1100][1100];
int n,m;

void transpose(){
	swap(n,m);
	forn(i,max(n,m))
		forn(j,i)
			swap(src[i][j],src[j][i]);
}
void flip(){
	forn(i,n)
		reverse(src[i],src[i]+m);
}

int rowpos[1100];
lng count_holes(){
	memset(rowpos,-1,sizeof(rowpos));
	forn(i,n)
		forn(j,m)
			if(src[i][j]=='X')
				rowpos[i]=j;

	lng res=0;
	forn(i,n)
		for(int j=i;j<n&&rowpos[j]!=-1&&(j==i||rowpos[j]>rowpos[j-1]);++j){
			lng t=rowpos[i]*(m-1-rowpos[j]);
			if(j!=i)
				t*=2;
			res+=t;
		}

	return res;
}

int cntfree[1100];
lng sum_dists(){
	memset(cntfree,0,sizeof(cntfree));
	forn(i,n)
		forn(j,m)
			if(src[i][j]=='.')
				++cntfree[i];
	lng r=0;
	forn(i,n)
		forn(j,i)
			r+=1LL*(i-j)*cntfree[i]*cntfree[j];
	return r*2;
}

lng cnt_dists(){
	lng r=0;
	forn(i,n)
		forn(j,m)
			if(src[i][j]=='.')
				++r;
	return r*r;
}

int main(int argc,char **argv){
#ifdef __ASD__
	freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif

	cin>>n>>m;
	gets(src[0]);
	forn(i,n)
		gets(src[i]);

	lng h=0;
	lng s=0;
	s+=sum_dists();
	h+=count_holes();
	flip();
	h+=count_holes();
	transpose();
	s+=sum_dists();
	h+=count_holes();
	flip();
	h+=count_holes();

	lng c=cnt_dists();
	s+=h*2;

	printf("%.15lf",((double)s)/c);

	return 0;
}