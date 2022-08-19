#pragma comment (linker, "/STACK:90000000")
#include <string>
#include <memory.h>
#include <cassert>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <sstream>
#include <utility>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define forv(i, v) for (int i = 0; i < (int)(v.size()); ++i)
#define fors(i, s) for (int i = 0; i < (int)(s.length()); ++i)
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define lng long long
#define eps 1e-9
#define iinf 1000000000



int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif

    int x,y;
    cin>>x>>y;
    int res=1;
    while(x*100+y*10>=220&&y>=2){
        int a,b;
        if(res){
            a=min(x,2);
            b=(220-a*100)/10;
        }else{
            b=min(y,220/10);
            b=(b-2)/10*10+2;
            a=(220-b*10)/100;
        }
        if(a>x||b>y||a*100+b*10!=220)
            exit(123);
        x-=a;
        y-=b;
        res=1-res;
    }
    string asd[]={"Ciel","Hanako"};
    cout<<asd[res];

    return 0;
}