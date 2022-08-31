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

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
int n;

bool go(int &x,int &y,int d){
    int xx=x+dx[d];
    int yy=y+dy[d];
    if(xx<0||xx>n||yy<0||yy>n)
        return false;
    x=xx;
    y=yy;
    return true;
}

int asd(int x,int y){
    if(!x)
        return y;
    if(y==n)
        return n+x;
    if(x==n)
        return n+n+n-y;
    if(!y)
        return n+n+n+n-x;
    exit(123);
}

int main(int argc,char **argv){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif

    int x1,y1,x2,y2;
    cin>>n>>x1>>y1>>x2>>y2;

    int r=abs(asd(x1,y1)-asd(x2,y2));

    cout<<min(r,n*4-r);

    return 0;
}