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

using namespace std;
#define all(a) a.begin(),a.end()
#define forn(i,n) for(int i=0;i<n;++i)
#define fornr(i,n) for(int i=n-1;i>=0;--i)
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
inline lng abs(lng a){return a<0?-a:a;}
#ifdef __ASD__
//#include "my.h"
#endif

int cnt[2000];
vector<string> *free;
vector<string> *res;
int need[2000];

int main()
{
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif

    /*
    forn(i,1000)
        cout<<i+1<<' ';
    return 0;//*/

    ios_base::sync_with_stdio(false);

    free=new vector<string>[2000];
    res=new vector<string>[2000];

    int n;
    cin>>n;
    vector<int> src(n);
    forn(i,n){
        int a;
        cin>>a;
        ++cnt[a];
        src[i]=a;
    }
    for(int i=1000;i>=0;--i)
        need[i]=(need[i+1]+1)/2+cnt[i];
    if(need[0]>1){
        cout<<"NO";
        return 0;
    }
    free[0].pb("");
    int c=1;
    for(int i=1;i<=1000;++i){
        if(free[i-1].size()*2<cnt[i]){
            exit(123);
        }
        int lim=need[i+1];
        for(char ch='0';ch<='1';++ch)
            for(int j=0;j<free[i-1].size()&&(cnt[i]||free[i].size()<lim);++j){
                if(cnt[i]){
                    res[i].pb(free[i-1][j]+ch);
                    --cnt[i];
                }else
                    free[i].pb(free[i-1][j]+ch);
            }
    }
    cout<<"YES";
    forn(i,n){
        cout<<'\n'<<res[src[i]].back();
        res[src[i]].pop_back();
    }

    return 0;
}