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

const int max_n = -1, inf = 1000111222;

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int test;
    cin>>test;
    while (test--){
        int n;
        cin>>n;
        vector<ll> a(n);
        vector<ll> g(2,0);
        for (int i=0;i<n;i++){
            cin>>a[i];
            g[i%2]=__gcd(g[i%2],a[i]);
        }
        bool flag=0;
        for (int ans=0;ans<2;ans++){
            bool ok=1;
            for (int i=0;i+1<n;i++){
                if ((a[i]%g[ans]==0)==(a[i+1]%g[ans]==0)){
                    ok=0;
                }
            }
            if (ok){
                cout<<g[ans]<<"\n";
                flag=1;
                break;
            }
        }
        if (!flag){
            cout<<0<<"\n";
        }
    }
}