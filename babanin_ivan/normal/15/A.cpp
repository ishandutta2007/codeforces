#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>

using namespace std;

#define pb push_back
#define mp make_pair
#define fir first
#define fi first
#define sec second
#define int64 long long       
#define ld long double

const int inf=2000000000;

int n,t;
vector< ld > a;

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    scanf("%d %d",&n,&t);
    for (int i=0;i<n;++i){
        int x,y;
        scanf("%d %d",&x,&y);
        a.pb(ld(x)-ld(y)/2.0);
        a.pb(ld(x)+ld(y)/2.0);
    }
    sort(a.begin(),a.end());
    //int i=0;
    int ans=2;
    int i=1;
    while (i<2*n-1){
        if (a[i+1]-a[i]==t)
            ans++;
        else if (a[i+1]-a[i]>t)
                ans+=2;
        i+=2;
    }
    cout<<ans<<endl;
    return 0;
}