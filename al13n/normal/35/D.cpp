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
#define forn(i,n) for(int i=0;i<n;++i)
#define lng long long
#define PI 3.1415926535897932384626433832795
#define SQ(a) ((a)*(a))
#define sqr(a) ((a)*(a))
#define VI vector<int>
#define VD vector<double>
#define VS vector<string>
#define forv(i,v) for(int i=0;i<(int)v.size();++i)
#define forvr(i,v) for(int i=(int)v.size()-1;i>=0;--i)
#define all(a) (a).begin(),(a).end()
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
#define eps 1e-8
#define prev asdprev
#define left asdleft
#define fixed asdfixed
#define y0 asdy0

int where[3000];
bool occ[300];
map<string,int> s2i;

int main()
{
//#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
//#endif

    int n,x;
    cin>>n>>x;
    vector<int> v;
    forn(i,n){
        int c;
        cin>>c;
        c*=n-i;
        v.pb(c);
    }
    sort(all(v));
    int res=0;
    forv(i,v){
        x-=v[i];
        if(x<0)
            break;
        ++res;
    }
    cout<<res;

    return 0;
}