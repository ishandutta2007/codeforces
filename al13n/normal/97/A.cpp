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
#include <windows.h>
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
#define left asdleft
#define prev asdprev
#define eps 1e-10
#define y1 asdy1
#define y2 asdy2
#define EQ(a,b) abs((a)-(b))<eps
#define PI 3.1415926535897932384626433832795
#define DEG2RAD PI/180
void mytimer(string task){
#ifdef __ASD__
    static LARGE_INTEGER prev;  LARGE_INTEGER cur,freq; QueryPerformanceCounter(&cur);  QueryPerformanceFrequency(&freq);   if(task!="")        cout<<task<<" took "<<(cur.QuadPart-prev.QuadPart)*1.0/freq.QuadPart<<endl; prev=cur;
#endif
}

int n,m;
string src[100];
int id[100][100];

int gra[28];
int grb[28];

int col[14];

int cnt;

void ext(int c){
#ifdef __ASD__
    exit(c);
#endif
}

pair<int,int> ar[28];

bool check(){
    forn(i,28){
        pair<int,int> t(col[gra[i]],col[grb[i]]);
        if(t.second<t.first)
            swap(t.first,t.second);
        ar[i]=t;
    }
    sort(ar,ar+28);
    return unique(ar,ar+28)-ar==28;
}

bool twice[7];
bool done;
int res;
char resm[100][100];

void doit(int a,int c){
    if(a==14){
        if(check()){
            ++res;
            if(!done){
                forn(i,n){
                    forn(j,m){
                        if(src[i][j]=='.')
                            resm[i][j]='.';
                        else
                            resm[i][j]='0'+col[id[i][j]];
                    }
                }
            }
        }
        return;
    }
    if(col[a]!=-1){
        doit(a+1,c);
        return;
    }
    if(c<7){
        col[a]=c;
        doit(a+1,c+1);
        col[a]=-1;
    }
    forn(i,c){
        if(twice[i])
            continue;
        col[a]=i;
        twice[i]=true;
        doit(a+1,c);
        twice[i]=false;
        col[a]=-1;
    }
}

int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif

    cin>>n>>m;
    forn(i,n)
        cin>>src[i];

    memset(id,-1,sizeof(id));

    int cur=0;
    forn(i,n){
        forn(j,m){
            if(src[i][j]=='.'||id[i][j]!=-1)
                continue;
            if(id[i+1][j]!=-1||id[i+1][j+1]!=-1||id[i][j+1]!=-1||src[i+1][j]=='.'||src[i+1][j+1]=='.'||src[i][j+1]=='.')
                ext(123);
            id[i][j]=id[i+1][j]=id[i+1][j+1]=id[i][j+1]=cur++;
        }
    }
    if(cur!=14)
        ext(98);

    forn(i,n){
        forn(j,m){
            if(src[i][j]=='.')
                continue;
            if(id[i][j]==-1)
                ext(321);
            if(i+1<n&&src[i][j]==src[i+1][j]){
                gra[cnt]=id[i][j];
                grb[cnt]=id[i+1][j];
                ++cnt;
            }
            if(j+1<m&&src[i][j]==src[i][j+1]){
                gra[cnt]=id[i][j];
                grb[cnt]=id[i][j+1];
                ++cnt;
            }
        }
    }
    if(cnt!=28)
        ext(2323);

    memset(col,-1,sizeof(col));

    doit(0,0);

    cout<<res*5040<<endl;
    forn(i,n)
        cout<<resm[i]<<endl;

    return 0;
}