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

ll __gcd(ll a,ll b)
{
    while (a&&b){
        if (a>b){
            a%=b;
        }
        else{
            b%=a;
        }
    }
    return a+b;
}

ll a[max_n];
ll b[max_n];

const int max_lev = 19;

template<typename T>
struct sparse_table {
    T mn[max_lev][max_n];

    void init(int n, T a[]) {
        for (int i = 0; i < n; ++i) {
            mn[0][i] = a[i];
        }
        for (int i = 1; i < max_lev; ++i) {
            for (int j = 0; j + (1 << i) <= n; ++j) {
                mn[i][j] = __gcd(mn[i - 1][j], mn[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    T get_min(int l, int r) const {
        if (l > r) {
            return inf;
        }
        const int lev = 31 - __builtin_clz(r - l + 1);
        return __gcd(mn[lev][l], mn[lev][r - (1 << lev) + 1]);
    }
};

sparse_table<ll> st;

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int test;
    cin>>test;
    while (test--){
        int n;
        cin>>n;
        for (int i=0;i<n;i++){
            cin>>a[i];
        }
        for (int i=1;i<n;i++){
            b[i]=abs(a[i]-a[i-1]);
//            cout<<b[i]<<" ";
        }
//        cout<<"\n";
        st.init(n,b);
        int ans=1;
        int p=1;
        for (int i=1;i<n;i++){
            while (p<=i && st.get_min(p,i)==1){
                p++;
            }
//            cout<<p<<" "<<i<<"\n";
            ans=max(ans,i-p+1+1);
        }
        cout<<ans<<"\n";
    }
}