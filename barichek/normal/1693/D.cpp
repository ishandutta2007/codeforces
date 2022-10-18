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

template<typename T>
struct segment_tree1 {
    T mx[4 * max_n];

    void build(int v, int l, int r) {
        if (l == r) {
            mx[v] = -inf;
            return;
        }
        int mid = (l + r) / 2;
        build(2 * v, l, mid);
        build(2 * v + 1, mid + 1, r);
        mx[v] = max(mx[2 * v], mx[2 * v + 1]);
    }

    void update(int v, int l, int r, int pos, T value) {
        if (l == r) {
            mx[v] = value;
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid) {
            update(2 * v, l, mid, pos, value);
        } else {
            update(2 * v + 1, mid + 1, r, pos, value);
        }
        mx[v] = max(mx[2 * v], mx[2 * v + 1]);
    }

    T get_max(int v, int tl, int tr, int l, int r) {
        if (tl == l && tr == r) {
            return mx[v];
        }
        int mid = (tl + tr) / 2;
        if (r <= mid) {
            return get_max(2 * v, tl, mid, l, r);
        } else if (l > mid) {
            return get_max(2 * v + 1, mid + 1, tr, l, r);
        }
        return max(get_max(2 * v, tl, mid, l, mid), get_max(2 * v + 1, mid + 1, tr, mid + 1, r));
    }
};

template<typename T>
struct segment_tree2 {
    T mn[4 * max_n];

    void build(int v, int l, int r) {
        if (l == r) {
            mn[v] = inf;
            return;
        }
        int mid = (l + r) / 2;
        build(2 * v, l, mid);
        build(2 * v + 1, mid + 1, r);
        mn[v] = min(mn[2 * v], mn[2 * v + 1]);
    }

    void update(int v, int l, int r, int pos, T value) {
        if (l == r) {
            mn[v] = value;
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid) {
            update(2 * v, l, mid, pos, value);
        } else {
            update(2 * v + 1, mid + 1, r, pos, value);
        }
        mn[v] = min(mn[2 * v], mn[2 * v + 1]);
    }

    T get_min(int v, int tl, int tr, int l, int r) {
        if (tl == l && tr == r) {
            return mn[v];
        }
        int mid = (tl + tr) / 2;
        if (r <= mid) {
            return get_min(2 * v, tl, mid, l, r);
        } else if (l > mid) {
            return get_min(2 * v + 1, mid + 1, tr, l, r);
        }
        return min(get_min(2 * v, tl, mid, l, mid), get_min(2 * v + 1, mid + 1, tr, mid + 1, r));
    }
};

segment_tree1<int> st1;
segment_tree2<int> st2;

int p[max_n];
int ans[max_n];

int best[max_n];

vector<int> vh[max_n];
vector<int> vh2[max_n];

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>p[i];
    }
    for (int i=1;i<=n;i++){
        ans[i]=1;
    }
    auto solve2143=[&]()
    {
        for (int i=0;i<=n;i++){
            vh[i].clear();
            vh2[i].clear();
        }
        st1.build(1,1,n);
        for (int i=1;i<=n;i++){
            best[i]=st1.get_max(1,1,n,p[i],n);
            if (best[i]!=-inf){
                vh[best[i]].pb(i);
            }
            st1.update(1,1,n,p[i],i);
        }
        st2.build(1,1,n);
        for (int i=n;i>=1;i--){
            int lol=st2.get_min(1,1,n,1,p[i]);
            if (lol!=inf){
                vh2[lol].pb(i);
            }
            st2.update(1,1,n,p[i],i);
        }
        st1.build(1,1,n);
        for (int i=1;i<=n;i++){
            for (auto pos3:vh[i]){
                ans[pos3]=max(ans[pos3],st1.get_max(1,1,n,1,p[pos3])+1);
            }
            for (auto pos2:vh2[i]){
                st1.update(1,1,n,p[pos2],pos2);
            }
        }
    };
    solve2143();
    for (int i=2;i<=n;i++){
        LOG(i,ans[i]);
        ans[i]=max(ans[i],ans[i-1]);
    }
    for (int i=1;i<=n;i++){
        p[i]=n-p[i]+1;
    }
    solve2143();
    for (int i=2;i<=n;i++){
        LOG(i,ans[i]);
        ans[i]=max(ans[i],ans[i-1]);
    }
    ll res=0;
    for (int i=1;i<=n;i++){
        res+=(i-ans[i]+1);
    }
    cout<<res<<"\n";
}