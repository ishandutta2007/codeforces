//#pragma GCC optimize("Ofast", "unroll-loops")
//#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4")

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

#if __APPLE__
#define D for (bool _FLAG = true; _FLAG; _FLAG = false)
#define LOG(...) print(#__VA_ARGS__" ::", __VA_ARGS__) << endl
template <class ...Ts> auto &print(Ts ...ts) { return ((cerr << ts << " "), ...); }
#else
#define D while (false)
#define LOG(...)
#endif

const int max_n = 2e5+10, inf = 1000111222;

int cnt[max_n];
vector<int> reb[max_n];
vector<int> rreb[max_n];
int dp[max_n];

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;
    for (int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        reb[u].pb(v);
        rreb[v].pb(u);
    }
    for (int i=1;i<=n;i++){
        dp[i]=inf;
    }
    priority_queue<pii,vector<pii>,greater<pii>> q;
    auto change=[&](int v,int value)
    {
        dp[v]=value;
        for (auto wh:rreb[v]){
            cnt[wh]++;
            q.push(mp((len(reb[wh])-cnt[wh])+1+value,wh));
        }
    };
    change(n,0);
    while (!q.empty()){
        pii now=q.top();
        q.pop();
        if (dp[now.sec]!=inf){
            continue;
        }
        change(now.sec,now.fir);
    }
    cout<<dp[1]<<"\n";
}