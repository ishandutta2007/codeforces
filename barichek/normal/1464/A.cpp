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

int p[max_n];

int f(int v)
{
    return p[v]==v?v:p[v]=f(p[v]);
}

bool union_set(int u,int v)
{
    u=f(u);
    v=f(v);
    if (u==v){
        return 0;
    }

    p[u]=v;
    return 1;
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int test;
    scanf("%d",&test);
    while (test--){
        int n,m;
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++){
            p[i]=i;
        }
        int ans=0;
        for (int i=0;i<m;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            if (x==y){
                continue;
            }
            if (union_set(x,y)){
                ans+=1;
            }
            else{
                ans+=2;
            }
        }
        cout<<ans<<"\n";
    }
}