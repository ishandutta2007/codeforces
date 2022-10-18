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

const int max_n = 1e5+10, inf = 1000111222;

vector<int> reb[max_n];
vector<pii> cur_dist;

void dfs(int now,int pred,int dist)
{
    cur_dist.pb(mp(dist,now));
    for (auto wh:reb[now]){
        if (wh!=pred){
            dfs(wh,now,dist+1);
        }
    }
}

void make_cur_dist(int v)
{
    cur_dist.clear();
    dfs(v,-1,0);
}

void answer(bool alice_win)
{
    if (alice_win){
        cout<<"Alice"<<"\n";
    }
    else{
        cout<<"Bob"<<"\n";
    }
}

void solve()
{
    int n,a,b,da,db;
    cin>>n>>a>>b>>da>>db;

    for (int i=1;i<=n;i++){
        reb[i].clear();
    }

    for (int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        reb[u].pb(v);
        reb[v].pb(u);
    }

    auto get_d=[&]()
    {
        make_cur_dist(1);
        make_cur_dist(max_element(all(cur_dist))->sec);
        return max_element(all(cur_dist))->fir;
    };
    int D = get_d();
    int R = (D+1)/2;
    if (da>=R){
        answer(1);
        return;
    }

    if (db<=2*da){
        answer(1);
        return;
    }

    auto get_dist=[&](int a,int b)
    {
        make_cur_dist(a);
        for (auto i:cur_dist){
            if (i.sec==b){
                return i.fir;
            }
        }
        assert(0);
    };
    if (get_dist(a,b)<=da){
        answer(1);
        return;
    }

    answer(0);
    return;
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int test;
    cin>>test;
    while (test--){
        solve();
    }
}