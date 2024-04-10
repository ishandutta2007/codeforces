#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
#define forn(i,n) for(int i=0;i<n;++i)
#define pb push_back
#define lng long long



int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    int n;
    lng ind;
    cin>>n>>ind;
    lng xa1=0,xm1=1,xa2=0,xm2=1;
    lng ya1=0,ym1=1,ya2=0,ym2=1;
    lng x,y;
    cin>>x>>y;
    forn(i,n){
        lng xx,yy;
        cin>>xx>>yy;
        if(i<ind%n){
            xa1=xx*2-xa1;
            ya1=yy*2-ya1;
            xm1*=-1;
            ym1*=-1;
        }else{
            xa2=xx*2-xa2;
            ya2=yy*2-ya2;
            xm2*=-1;
            ym2*=-1;
        }
    }
    lng xa;
    lng ya;
    xa=xa1+xm1*xa2;
    ya=ya1+ym1*ya2;

    x=xa1+x*xm1;
    y=ya1+y*ym1;
    if((ind/n)%2){
        x=xa-x;
        y=ya-y;
    }
    cout<<x<<' '<<y;

    return 0;
}