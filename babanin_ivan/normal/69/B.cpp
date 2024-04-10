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

int n,m;

pair< pair < int, int> , int> a[200];

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    scanf("%d %d",&n,&m);
    
    for (int i=1;i<=n;++i)
        a[i].first.first=inf;

    for (int i=0;i<m;++i){
        int l,r,t,c;
        scanf("%d %d %d %d",&l,&r,&t,&c);
        pair < pair<int,int> ,int> tek;
        tek.first.first=t;
        tek.first.second=i+1;
        tek.second=c;
        for (int j=l;j<=r;++j)
            a[j]=min(a[j],tek);
    }
    int64 ans=0;
    for (int i=1;i<=n;++i)
        ans+=a[i].second;
    cout<<ans<<endl;
    return 0;
}