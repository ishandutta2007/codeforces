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

const int max_n = 100+10, inf = 1000111222;

int ans[max_n][max_n];

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            ans[i][j]=-1;
        }
    }
    for (int iter=0;iter<n*n;iter++){
        int a;
        cin>>a;
        a--;
        bool flag=0;
        for (int i=0;!flag && i<n;i++){
            for (int j=0;!flag && j<n;j++){
                if (ans[i][j]==-1 && (i+j)%2!=a){
                    ans[i][j]=(i+j)%2;
                    cout<<ans[i][j]+1<<" "<<i+1<<" "<<j+1<<"\n";
                    flag=1;
                }
            }
        }
        if (!flag){
            for (int i=0;!flag && i<n;i++){
                for (int j=0;!flag && j<n;j++){
                    if (ans[i][j]==-1){
                        ans[i][j]=2;
                        cout<<ans[i][j]+1<<" "<<i+1<<" "<<j+1<<"\n";
                        flag=1;
                    }
                }
            }
        }
        fflush(stdout);
    }
}