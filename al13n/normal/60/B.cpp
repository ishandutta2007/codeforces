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
#define ulng unsigned long long
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
#define y0 asdy0
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

char src[20][20][20];
bool was[20][20][20];
int k,n,m;
int res;

void dfs(int a,int b,int c){
    if(a<0||a>=k||b<0||b>=n||c<0||c>=m||was[a][b][c]||src[a][b][c]=='#')
        return;
    ++res;
    was[a][b][c]=true;
    const int da[6]={0,0,0,0,-1,1};
    const int db[6]={0,0,-1,1,0,0};
    const int dc[6]={-1,1,0,0,0,0};
    forn(i,6)
        dfs(a+da[i],b+db[i],c+dc[i]);
}

int main(int argc,char **argv){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif

    cin>>k>>n>>m;
    gets(src[0][0]);
    forn(i,k){
        gets(src[i][0]);
        forn(j,n)
            gets(src[i][j]);
    }
    int a,b;
    cin>>a>>b;
    --a;--b;
    dfs(0,a,b);
    cout<<res;

    return 0;
}