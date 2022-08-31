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
#ifdef __ASD__
//#include <windows.h>
#endif
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
#define linf 1000000000000000000LL
#define dinf 1e200
#define left asdleft
#define prev asdprev
#define eps 1e-12
#define y1 asdy1
#define y2 asdy2
#define EQ(a,b) abs((a)-(b))<eps
#define PI 3.1415926535897932384626433832795
#define DEG2RAD PI/180
#define ulng unsigned lng
#define next asdnext
#define prev asdprev
#define PII pair<int,int> 
#define X first
#define Y second
void mytimer(string task){
#ifdef __ASD__
        //static LARGE_INTEGER prev;      LARGE_INTEGER cur,freq; QueryPerformanceCounter(&cur);  QueryPerformanceFrequency(&freq);       if(task!="")            cout<<task<<" took "<<(cur.QuadPart-prev.QuadPart)*1.0/freq.QuadPart<<endl;     prev=cur;
#endif
}
void ext(int c){
#ifdef __ASD__
        exit(c);
#endif
}

int tree[2000000];

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
	tree[k]=tree[k*2+1]+tree[k*2+2];
}

int first1(int l,int r,int a,int b,int k){
	if(!tree[k])
		return -1;
	if(b==a+1)
		return a;
	int c=(a+b)/2;
	if(r<=c)
		return first1(l,r,a,c,k*2+1);
	if(l>=c)
		return first1(l,r,c,b,k*2+2);
	int t=first1(l,c,a,c,k*2+1);
	if(t!=-1)
		return t;
	return first1(c,r,c,b,k*2+2);
}

int per;
int pos[210000];

int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif

	ios_base::sync_with_stdio(false);

	int n,m,tc;
	cin>>n>>m>>tc;
	forn(i,n){
		pos[i]=-1;
		setv(i,1,0,n,0);
	}
	int l=0;
	forn(i,n){
		if(pos[i]!=-1)
			continue;
		int p=i;
		do{
			pos[p]=l++;
			p=(p+m)%n;
		}while(p!=i);
		if(!per)
			per=l;
	}

	map<int,int> place;

	lng res=0;
	forn(qqq,tc){
		char ch;
		int id;
		cin>>ch>>id;
		if(ch=='+'){
			int h;
			cin>>h;
			h=pos[h];
			int p=first1(h,(h/per+1)*per,0,n,0);
			if(p==-1)
				p=first1(h/per*per,h,0,n,0);
			if(p==-1)
				exit(123);
			int r=p-h;
			if(r<0)
				r+=per;
			res+=r;
			setv(p,0,0,n,0);
			place[id]=p;
		}else{
			setv(place[id],1,0,n,0);
		}
	}

	cout<<res;

	return 0;
}