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

const int max_n = 600+10, inf = 1000111222;

int edge[max_n][max_n];
int dist[max_n][max_n];

bool ans[max_n][max_n];

int troyka[max_n][max_n];

int best_for_ub[max_n][max_n];

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            edge[i][j]=inf;
            dist[i][j]=inf;
        }
        dist[i][i]=0;
    }
    while (m--){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        edge[u][v]=w;
        edge[v][u]=w;

        dist[u][v]=w;
        dist[v][u]=w;
    }

    for (int k=1;k<=n;k++){
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }

    int q;
    scanf("%d",&q);
    while (q--){
        int u,v,l;
        cin>>u>>v>>l;
        troyka[u][v]=l;
        troyka[v][u]=l;
    }

    for (int u=1;u<=n;u++){
        for (int b=1;b<=n;b++){
            best_for_ub[u][b]=-inf;
            for (int v=1;v<=n;v++){
                if (troyka[u][v]){
                    best_for_ub[u][b]=max(best_for_ub[u][b],troyka[u][v]-dist[b][v]);
                }
            }
        }
    }

    for (int a=1;a<=n;a++){
        for (int b=1;b<=n;b++){
            if (edge[a][b]!=inf){
                for (int u=1;u<=n;u++){
                    if (best_for_ub[u][b]>=dist[u][a]+edge[a][b]){
                        ans[a][b]=1;
                    }
                }
            }
        }
    }

    int res=0;
    for (int i=1;i<=n;i++){
        for (int j=i+1;j<=n;j++){
            res+=(ans[i][j] || ans[j][i]);
        }
    }
    cout<<res<<"\n";
}