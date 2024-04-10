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

const int64 inf=2000000000000;

int n;
vector< pair< int, int> > a[100100];
bool used[100100];
int64 dp[100100],last[100100];

void dfs(int v){
    used[v]=true;
    dp[v]=0;
    last[v]=inf;
    int k=0;
    int64 maxx=-inf;
    for (int i=0;i<a[v].size();++i)
        if (!used[a[v][i].first]){
            dfs(a[v][i].first);
            dp[v]+=dp[a[v][i].first]+2*a[v][i].second;
            if (dp[a[v][i].first]+a[v][i].second-last[a[v][i].first]>maxx){
                k=i;
                maxx=dp[a[v][i].first]+a[v][i].second-last[a[v][i].first];
            }
        }
    if (maxx==-inf)
        last[v]=0;
    else last[v]=dp[v]-dp[a[v][k].first]-a[v][k].second+last[a[v][k].first];
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    scanf("%d",&n);
    for (int i=0;i<n-1;++i){
        int x,y,w;
        scanf("%d %d %d",&x,&y,&w);
        --x;
        --y;
        a[x].pb(mp(y,w));
        a[y].pb(mp(x,w));
    }
    dfs(0);
    cout<<last[0]<<endl;
    return 0;
}