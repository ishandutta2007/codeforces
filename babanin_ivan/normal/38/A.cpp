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

int n,a,b;
int d[200];

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    scanf("%d",&n);
    for (int i=0;i<n-1;++i)
        scanf("%d",&d[i]);
    scanf("%d %d",&a,&b);
    --a;
    --b;
    int ans=0;
    for (int i=a;i<b;++i)
        ans+=d[i];
    cout<<ans<<endl;
    return 0;
}