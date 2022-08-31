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
#include "my.h"
#endif

int ar[1000][1000];
int mins[1000][1000];
lng sums[1000][1000];
bool occ[1000][1000];
int tmpm[1000][1000];
lng tmps[1000][1000];
int n,m;
int a,b;



int main(){
#ifdef __TRATATA__
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    //*
    cin>>n>>m>>a>>b;
    forn(i,n){
        forn(j,m){
            scanf("%d",ar[i]+j);
        }
    }//*/
    /*
    n=100;
    m=100;
    a=10;
    b=10;
    forn(i,n){
        forn(j,m){
            ar[i][j]=rand();
            //cout<<ar[i][j]<<' ';
        }
        //cout<<endl;
    }//*/

    forn(i,n){
        stack<int> l,r;
        lng s=0;
        forn(k,b)
            s+=ar[i][k];
        forn(j,m-b+1){
            if(l.empty()){
                while(!r.empty())
                    r.pop();
                int t=iinf;
                fornr(k,b)
                    l.push(t=min(t,ar[i][j+k]));
            }
            if(r.empty())
                tmpm[i][j]=l.top();
            else
                tmpm[i][j]=min(l.top(),r.top());
            tmps[i][j]=s;
            if(j+b<m){
                s=s-ar[i][j]+ar[i][j+b];
                l.pop();
                if(r.empty())
                    r.push(ar[i][j+b]);
                else
                    r.push(min(r.top(),ar[i][j+b]));
            }
        }
    }
    forn(i,m-b+1){
        stack<int> l,r;
        lng s=0;
        forn(k,a)
            s+=tmps[k][i];
        forn(j,n-a+1){
            if(l.empty()){
                while(!r.empty())
                    r.pop();
                int t=iinf;
                fornr(k,a)
                    l.push(t=min(t,tmpm[j+k][i]));
            }
            if(r.empty())
                mins[j][i]=l.top();
            else
                mins[j][i]=min(l.top(),r.top());
            sums[j][i]=s;
            if(j+a<n){
                s=s-tmps[j][i]+tmps[j+a][i];
                l.pop();
                if(r.empty())
                    r.push(tmpm[j+a][i]);
                else
                    r.push(min(r.top(),tmpm[j+a][i]));
            }
        }
    }

    /*
    forn(i,n-a+1){
        forn(j,m-b+1){
            int m=iinf;
            lng s=0;
            forn(y,a){
                forn(x,b){
                    s+=ar[i+y][j+x];
                    m=min(m,ar[i+y][j+x]);
                }
            }
            if(s!=sums[i][j]||m!=mins[i][j])
                return i+j+1;
        }
    }
    return 0;//*/

    priority_queue<pair<lng,pair<int,int> > > qu;
    forn(i,n-a+1){
        forn(j,m-b+1){
            qu.push(mp(-(sums[i][j]-1LL*a*b*mins[i][j]),mp(-i,-j)));
        }
    }
    vector<pair<pair<int,int>,lng> > res;
    while(!qu.empty()){
        lng v=-qu.top().first;
        int y=-qu.top().second.first;
        int x=-qu.top().second.second;
        qu.pop();
        if(occ[y][x])
            continue;
        res.pb(mp(mp(y,x),v));
        for(int i=max(0,y-a+1);i<min(n,y+a);++i)
            for(int j=max(0,x-b+1);j<min(m,x+b);++j)
                occ[i][j]=true;
    }
    cout<<res.size();
    forv(i,res)
        printf("\n%d %d %lld",res[i].first.first+1,res[i].first.second+1,res[i].second);

    return 0;
}