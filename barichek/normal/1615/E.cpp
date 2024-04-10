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
multiset<int, greater<int>> s[max_n];

void dfs(int now,int pred)
{
    for (auto wh:reb[now]){
        if (wh!=pred){
            dfs(wh,now);
            if (len(s[now])<len(s[wh])){
                s[now].swap(s[wh]);
            }
            for (auto i:s[wh]){
                s[now].insert(i);
            }
        }
    }

    s[now].insert(0);

    int kek=*s[now].begin();
    s[now].erase(s[now].begin());
    s[now].insert(kek+1);
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,k;
    cin>>n>>k;
    for (int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        reb[u].pb(v);
        reb[v].pb(u);
    }
    dfs(1,-1);
    ll ans=-1e18;
    ll cur_a=0;
    ll cur_b=n;
    auto get_by_cur=[&]()
    {
        ll b_optimal=min(ll(n/2),cur_b);
        return 1ll*cur_a*(n-cur_a) - 1ll*b_optimal*(n-b_optimal);
    };
//    cout<<"at start :: "<<get_by_cur()<<"\n";
    ans=max(ans,get_by_cur());
    for (int i=0;i<k;i++){
        cur_a++;
        cur_b-=*s[1].begin();
        s[1].erase(s[1].begin());
        ans=max(ans,get_by_cur());
//        cout<<"after "<<i+1<<" :: "<<get_by_cur()<<"\n";
    }
    cout<<ans<<"\n";
}