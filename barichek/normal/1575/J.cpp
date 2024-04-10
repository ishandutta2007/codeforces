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

const int max_n = 1000+10, inf = 1000111222;

int a[max_n][max_n];

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            scanf("%d",&a[i][j]);
        }
    }

    auto is_ok=[&](int x,int y)
    {
        return 0<=x && x<n && 0<=y && y<m;
    };

    while (k--){
        int x,y;
        x=0;
        scanf("%d",&y);
        y--;

        while (is_ok(x,y)){
            int nx=x,ny=y;
            if (a[x][y]==1){
                ny++;
            }
            if (a[x][y]==2){
                nx++;
            }
            if (a[x][y]==3){
                ny--;
            }
            a[x][y]=2;
            x=nx;
            y=ny;
        }

        cout<<y+1<<" ";
    }
    cout<<"\n";
}