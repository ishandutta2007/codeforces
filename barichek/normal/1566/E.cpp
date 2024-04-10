//#pragma GCC optimize("Ofast", "unroll-loops")
//#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "avx")

#ifdef __APPLE__
# include <iostream>
# include <cmath>
# include <algorithm>
# include <stdio.h>
# include <cstdint>
# include <cstring>
# include <string>
# include <cstdlib>
# include <vector>
# include <bitset>
# include <map>
# include <queue>
# include <ctime>
# include <stack>
# include <set>
# include <list>
# include <random>
# include <deque>
# include <functional>
# include <iomanip>
# include <sstream>
# include <fstream>
# include <complex>
# include <numeric>
# include <immintrin.h>
# include <cassert>
# include <array>
# include <tuple>
# include <unordered_map>
# include <unordered_set>
# include <thread>
#else
# include <bits/stdc++.h>
#endif

#define F first
#define S second
#define MP make_pair
#define PB push_back

#define all(a) a.begin(),a.end()
#define len(a) (int)(a.size())
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

const int max_n = 2e5+10, inf = 1000111222;

vector<int> reb[max_n];

int deg_down[max_n];
int deep[max_n];
int pp[max_n];

void dfs(int now,int pred)
{
    pp[now]=pred;
    deg_down[now]=len(reb[now])-(pred==-1 ? 0 : 1);
    for (auto wh:reb[now]){
        if (wh!=pred){
            deep[wh]=deep[now]+1;
            dfs(wh,now);
        }
    }
}

void solve()
{
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        reb[i].clear();
    }
    for (int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        u--;
        v--;
        reb[u].pb(v);
        reb[v].pb(u);
    }

    deep[0]=0;
    dfs(0,-1);

    vector<pii> vv;
    for (int i=0;i<n;i++){
        vv.pb(mp(deep[i],i));
    }
    sort(all(vv));
    reverse(all(vv));
    vector<int> to_ans;
    int start=1;
    for (auto q:vv){
        int v=q.sec;
        if (deg_down[v]!=0){
            if (v==0){
                start=deg_down[v];
            }
            else{
                to_ans.pb(deg_down[v]);
                deg_down[pp[v]]-=1;
            }
        }
        else{
            // nothing
        }
    }

    int ans=start;
    for (auto i:to_ans){
        ans-=1;
        ans+=i;
    }

    cout<<ans<<"\n";
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int test;
    scanf("%d",&test);
    while (test--){
        solve();
    }
}