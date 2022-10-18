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

const int max_lev = 18;

template<typename T, int z = 1> // z = -1 for maximum
struct sparse_table {
    T mn[max_lev][max_n];

    void init(int n, T a[]) {
        for (int i = 0; i < n; ++i) {
            mn[0][i] = z * a[i];
        }
        for (int i = 1; i < max_lev; ++i) {
            for (int j = 0; j + (1 << i) <= n; ++j) {
                mn[i][j] = min(mn[i - 1][j], mn[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    T get_min(int l, int r) const {
        if (l > r) {
            return z * inf;
        }
        const int lev = 31 - __builtin_clz(r - l + 1);
        return z * min(mn[lev][l], mn[lev][r - (1 << lev) + 1]);
    }
};

sparse_table<ll, 1> st_min;
sparse_table<ll, -1> st_max;

int a[max_n];
ll pref[max_n];

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int n,q;
    scanf("%d%d",&n,&q);
    for (int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for (int i=0;i<n;i++){
        int b;
        scanf("%d",&b);
        a[i]-=b;
    }
    for (int i=0;i<n;i++){
        if (i){
            pref[i]=pref[i-1];
        }
        pref[i]+=a[i];
//        cout<<"pref["<<i<<"] :: "<<pref[i]<<"\n";
    }
    st_min.init(n,pref);
    st_max.init(n,pref);
    while (q--){
        int l,r;
        scanf("%d%d",&l,&r);
        l--;
        r--;

        if ((pref[r]-(l==0 ? 0 : pref[l-1]))!=0){
            cout<<-1<<"\n";
            continue;
        }
        ll ans=0;
        ans=max(ans,-(st_min.get_min(l,r)-(l==0 ? 0 : pref[l-1])));
        ans=max(ans,(st_max.get_min(l,r)-(l==0 ? 0 : pref[l-1])));
        cout<<ans<<"\n";
    }
}