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

const int max_n = 20, inf = 1000111222;

int ans[max_n][max_n];

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int test;
    cin>>test;
    while (test--){
        int n,m;
        cin>>n>>m;
        memset(ans,0,sizeof(ans));
        auto ok=[&](int x,int y)
        {
            return 0<=x && x<n && 0<=y && y<m;
        };
        auto try_set=[&](int x,int y)
        {
            for (int dx=-1;dx<=1;dx++){
                for (int dy=-1;dy<=1;dy++){
                    if (ok(x+dx,y+dy) && ans[x+dx][y+dy]){
                        return;
                    }
                }
            }
            ans[x][y]=1;
        };
        for (int j=0;j<m;j++){
            try_set(0,j);
        }
        for (int i=0;i<n;i++){
            try_set(i,m-1);
        }
        for (int j=m-1;j>=0;j--){
            try_set(n-1,j);
        }
        for (int i=n-1;i>=0;i--){
            try_set(i,0);
        }
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                cout<<ans[i][j];
            }
            cout<<"\n";
        }
        cout<<"\n";
    }
}