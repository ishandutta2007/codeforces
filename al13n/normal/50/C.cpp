#pragma comment(linker,"/STACK:228000000")
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
using namespace std;
#define all(a) a.begin(),a.end()
#define forn(i,n) for(int i=0;i<(n);++i)
#define fornr(i,n) for(int i=(n)-1;i>=0;--i)
#define lng long long
#define PI 3.1415926535897932384626433832795
#define SQ(a) ((a)*(a))
#define sqr(a) ((a)*(a))
#define VI vector<int>
#define VD vector<double>
#define VS vector<string>
#define forv(i,v) for(int i=0;i<(int)v.size();++i)
#define forvr(i,v) for(int i=(int)v.size()-1;i>=0;--i)
#define PII pair<int,int>
#define mp make_pair
#define pb push_back
#define ABS(a) ((a)<0?-(a):(a))
#define EQ(a,b) (ABS((a)-(b))<eps)
#define iinf 1000000000
#define dinf 100000000000000000000.0
#define linf 1000000000000000000LL
#define y1 asdy1
#define y2 asdy2
#define DEG2RAD 0.01745329251994329576923690768489
#define eps 1e-12
#define prev asdprev
#define left asdleft
#define fixed asdfixed
#define time asdtime
#define free asdfree
#define ends asdends
inline lng abs(lng a){return a<0?-a:a;}
#ifdef __ASD__
//#include "my.h" // project euler thingy
#endif



int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif

    int x1,x2,y1,y2,p1,p2,q1,q2;
    x1=y1=p1=q1=iinf;
    x2=y2=p2=q2=-iinf;
    int n;
    cin>>n;
    forn(i,n){
        int x,y;
        scanf("%d%d",&x,&y);
        x1=min(x1,x-1);
        x2=max(x2,x+1);
        y1=min(y1,y-1);
        y2=max(y2,y+1);
        int p=x+y;
        int q=x-y;
        p1=min(p1,p-1);
        p2=max(p2,p+1);
        q1=min(q1,q-1);
        q2=max(q2,q+1);
    }
    int res=0;

    int a[]={2*(x2-x1),2*(y2-y1),x2+y2-p2,p1-x1-y1,x2-y1-q2,q1-x1+y2};
    forn(i,6){
        if(a[i]<=0)
            exit(i+1);
        if(i>=2)
            a[i]*=-1;
        res+=a[i];
    }
    cout<<res;

    return 0;
}