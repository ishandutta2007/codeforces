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

const int max_n = 3e5+10, inf = 1000111222;

template<typename T>
struct segment_tree {
    T f[4 * max_n];
    T mx[4 * max_n];

    void build(int v, int l, int r, T a[]) {
        f[v] = 0;
        if (l == r) {
            mx[v] = a[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * v, l, mid, a);
        build(2 * v + 1, mid + 1, r, a);
        mx[v] = max(mx[2 * v], mx[2 * v + 1]);
    }

    void push(int v, int l, int r, int mid) {
        if (f[v]) {
            mx[2 * v] += f[v];
            mx[2 * v + 1] += f[v];
            f[2 * v] += f[v];
            f[2 * v + 1] += f[v];
            f[v] = 0;
        }
    }

    void update(int v, int tl, int tr, int l, int r, T value) {
        if (tl == l && tr == r) {
            f[v] += value;
            mx[v] += value;
            return;
        }
        int mid = (tl + tr) / 2;
        push(v, tl, tr, mid);
        if (r <= mid) {
            update(2 * v, tl, mid, l, r, value);
        } else if (l > mid) {
            update(2 * v + 1, mid + 1, tr, l, r, value);
        } else {
            update(2 * v, tl, mid, l, mid, value);
            update(2 * v + 1, mid + 1, tr, mid + 1, r, value);
        }
        mx[v] = max(mx[2 * v], mx[2 * v + 1]);
    }

    T get_max(int v, int tl, int tr, int l, int r) {
        if (tl == l && tr == r) {
            return mx[v];
        }
        int mid = (tl + tr) / 2;
        push(v, tl, tr, mid);
        if (r <= mid) {
            return get_max(2 * v, tl, mid, l, r);
        } else if (l > mid) {
            return get_max(2 * v + 1, mid + 1, tr, l, r);
        }
        return max(get_max(2 * v, tl, mid, l, mid), get_max(2 * v + 1, mid + 1, tr, mid + 1, r));
    }
};

segment_tree<ll> s;

int h[max_n];
int b[max_n];
ll dp[max_n];

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%d",&h[i]);
    }
    for (int i=1;i<=n;i++){
        scanf("%d",&b[i]);
    }

    vector<pii> poses;
    poses.pb(mp(-inf,0));
    dp[0]=0;
    for (int i=1;i<=n;i++){
        while (poses.back().fir>=h[i]){
            s.update(1,1,n,poses[len(poses)-2].sec+1,poses[len(poses)-1].sec,-b[poses[len(poses)-1].sec]);
            poses.pop_back();
        }
        s.update(1,1,n,poses[len(poses)-1].sec+1,i,+b[i]);
        poses.pb(mp(h[i],i));

        s.update(1,1,n,i,i,+dp[i-1]);
        dp[i]=s.get_max(1,1,n,1,i);
//        cout<<"dp["<<i<<"] :: "<<dp[i]<<"\n";
    }
    cout<<dp[n]<<"\n";
}