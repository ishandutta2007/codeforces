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
inline lng abs(lng a){return a<0?-a:a;}
#ifdef __ASD__
//#include "my.h"
#endif

vector<pair<pair<int,int>,int> > sv;

int main()
{
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif

    int v,d;
    int mx;
    int n;
    cin>>n>>v>>d;
    mx=v;
    sv.resize(n);
    forn(i,n){
        cin>>sv[i].first.second>>sv[i].first.first;
        sv[i].second=i;
    }
    sort(all(sv));
    reverse(all(sv));
    int res=0;
    vector<pair<int,int> > resv;
    while(v>0){
        v+=d;
        v=min(v,mx);
        if(v<=0)
            break;
        bool f=false;
        forv(i,sv){
            if(sv[i].first.second*mx<v*100)
                continue;
            d-=sv[i].first.first;
            resv.pb(mp(res,sv[i].second+1));
            sv.erase(sv.begin()+i);
            f=true;
            break;
        }
        if(!f&&d>=0){
            cout<<"NO";
            exit(0);
        }
        ++res;
    }
    cout<<"YES\n"<<res<<' '<<resv.size();
    forv(i,resv)
        cout<<'\n'<<resv[i].first<<' '<<resv[i].second;

    return 0;
}