#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <ctgmath>
#include <functional>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

#define pb push_back
#define mp make_pair
#define x first
#define y second

typedef pair<long long, long long> pll;

long long ccw(pll a, pll b, pll c){
    return a.x*b.y+b.x*c.y+c.x*a.y-a.y*b.x-b.y*c.x-c.y*a.x;
}

bool compare(pll a, pll b){
    if(a.x*b.y!=a.y*b.x) return a.x*b.y>a.y*b.x;
    return a.x<a.y;
}

vector<long long> inp;
vector<pll> hul, ans;

int main(){
    int n;
    scanf("%d",&n);
    long long sm=0;
    for(int i=0;i<n;i++){
        long long t;
        scanf("%lld",&t);
        inp.pb(t);
        sm+=t;
        hul.pb(mp((long long)i+1,sm));
    }
    sort(hul.begin(),hul.end(),compare);
    ans.pb(mp(0LL,0LL));
    for(int i=0;i<hul.size();i++){
        while(ans.size()>1){
            int q=ans.size();
            if(ccw(ans[q-2],ans[q-1],hul[i])<0){
                ans.pop_back();
            }
            else{
                break;
            }
        }
        ans.pb(hul[i]);
    }
    for(int i=1;i<ans.size();i++){
        for(int j=ans[i-1].x+1;j<=ans[i].x;j++){
            printf("%.12Lf\n",(long double)(ans[i].y-ans[i-1].y)/(ans[i].x-ans[i-1].x));
        }
        if(ans[i].x==n) break;
    }
}