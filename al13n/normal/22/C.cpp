#pragma comment(linker,"/STACK:256000000")
//#pragma comment(linker,"/STACK:536870912")
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <cstring>
#include <ctime>
#include <memory.h>
using namespace std;

#define lng long long
#define PB push_back
#define pii pair<int,int>
#define MPII make_pair<int,int>
#define PLL pair<lng,lng>
#define MPLL make_pair<lng,lng>
#define PI 3.1415926535897932384626433832795
#define DEG2RAD (PI/180.0)
#define RAD2DEG (1.0/DEG2RAD)
#define pb push_back
#define mp make_pair
#define VI vector<int>
#define VS vector<string>
#define VD vector<double>
#define forn(i,n) for(int i=0;i<n;++i)
#define fornr(i,n) for(int i=n-1;i>=0;--i)
#define forn1(i,n) for(i=0;i<n;++i)
#define forv(i,v) for(int i=0;i<v.size();++i)
#define forvr(i,v) for(int i=v.size()-1;i>=0;--i)
#define fors(i,s) for(int i=0;i<s.length();++i)
#define EPS 1e-12
#define eps EPS
#define ABS(a) ((a)<0?-(a):(a))
#define EQ(a,b) (ABS((a)-(b))<EPS)
#define iinf 1000000000
#define linf 100000000000000000LL
#define maxll ((1LL<<62)-1+(1LL<<62))
#define dinf 10000000000000000000000.0
#define SQ(a) ((a)*(a))
#define SWAP(t,a,b) {t ____tmpasdasdasd=(a);(a)=(b);(b)=____tmpasdasdasd;}
#define left _left
#define y1 asdy1
#define y2 asdy2
#define y0 asdy0
#define abs(a) ((a)<0?-(a):(a))
#define mat _mat
#define ALL(a) (a).begin(),(a).end()
#ifdef __TRATATA__
//#include "my.h"
#endif

int v;
void out1(int a){
    if(a==v)
        cout<<2;
    else if(a==2)
        cout<<v;
    else
        cout<<a;
}
void out(int a,int b){
    ++a;
    ++b;
    out1(a);
    cout<<' ';
    out1(b);
    cout<<endl;
}

int main(){
#ifdef __TRATATA__
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    int n,m;
    cin>>n>>m>>v;
    if(m<n-1||m>(n-1)*(n-2)/2+1){
        cout<<-1;
        return 0;
    }
    forn(i,n-1)
        out(i,i+1);
    m-=n-1;
    for(int i=1;m;++i){
        for(int j=i+2;j<n&&m;++j){
            out(i,j);
            --m;
        }
    }

    return 0;
}