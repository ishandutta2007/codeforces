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

const int max_n = 500+10, inf = 1000111222;

int d[max_n][max_n];

void solve()
{
    int n,m;
    cin>>n>>m;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            d[i][j]=inf;
        }
        d[i][i]=0;
    }
    vector<pair<pii,int>> edges;
    for (int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        u--;
        v--;
        d[u][v]=1;
        d[v][u]=1;
        edges.pb(mp(mp(u,v),w));
    }
    for (int k=0;k<n;k++){
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
    ll ans=1e18;
    for (auto e:edges){
        ll min_l=1e18;
        for (int iter=0;iter<2;iter++){
            min_l=min(min_l,0ll+d[0][e.fir.fir]+1+d[e.fir.sec][n-1]);
            for (int i=0;i<n;i++){
                min_l=min(min_l,0ll+d[0][i]+d[i][n-1]+d[i][e.fir.fir]+1+1);
            }
            swap(e.fir.fir,e.fir.sec);
        }
        if (min_l<1e9){
            ans=min(ans,min_l*e.sec);
        }
    }
    cout<<ans<<"\n";
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int test;
    cin>>test;
    while (test--){
        solve();
    }
}


/*
1
5 4
1 2 100
2 3 100
3 4 1
1 5 100
*/