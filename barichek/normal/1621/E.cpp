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
    T mn[4 * max_n];

    void build(int v, int l, int r) {
        f[v] = 0;
        if (l == r) {
            mn[v] = 0;
            return;
        }
        int mid = (l + r) / 2;
        build(2 * v, l, mid);
        build(2 * v + 1, mid + 1, r);
        mn[v] = max(mn[2 * v], mn[2 * v + 1]);
    }

    void push(int v, int l, int r, int mid) {
        if (f[v]) {
            mn[2 * v] += f[v];
            mn[2 * v + 1] += f[v];
            f[2 * v] += f[v];
            f[2 * v + 1] += f[v];
            f[v] = 0;
        }
    }

    void update(int v, int tl, int tr, int l, int r, T value) {
        if (tl == l && tr == r) {
            f[v] += value;
            mn[v] += value;
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
        mn[v] = max(mn[2 * v], mn[2 * v + 1]);
    }

    T get_min(int v, int tl, int tr, int l, int r) {
        if (tl == l && tr == r) {
            return mn[v];
        }
        int mid = (tl + tr) / 2;
        push(v, tl, tr, mid);
        if (r <= mid) {
            return get_min(2 * v, tl, mid, l, r);
        } else if (l > mid) {
            return get_min(2 * v + 1, mid + 1, tr, l, r);
        }
        return max(get_min(2 * v, tl, mid, l, mid), get_min(2 * v + 1, mid + 1, tr, mid + 1, r));
    }
};

segment_tree<int> st;

int a[max_n];

ll div_up(ll a,ll b)
{
    return (a+b-1)/b;
}

void solve()
{
    int n,m;
    cin>>n>>m;
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    reverse(a,a+n);
    vector<pair<ll,vector<int>>> g;
    vector<int> vh;
    for (int i=0;i<m;i++){
        vh.pb(a[i]);
    }
    for (int i=0;i<m;i++){
        int s;
        cin>>s;
        vector<int> cur;
        ll sum=0;
        for (int j=0;j<s;j++){
            int b;
            cin>>b;
            cur.pb(b);
            sum+=b;
        }
        vh.pb(div_up(sum,s));
        for (auto b:cur){
            vh.pb(div_up(sum-b,s-1));
        }
        g.pb(mp(sum,cur));
    }
    sort(all(vh));
    vh.resize(unique(all(vh))-vh.begin());
    auto get_vh_id=[&](int a)
    {
        return lower_bound(all(vh),a)-vh.begin();
    };

    st.build(1,0,len(vh)-1);
    for (int i=0;i<m;i++){
        st.update(1,0,len(vh)-1,0,get_vh_id(a[i]),-1);
    }
    for (auto gr:g){
        st.update(1,0,len(vh)-1,0,get_vh_id(div_up(gr.fir,len(gr.sec))),+1);
    }
    string ans="";
    for (auto gr:g){
        st.update(1,0,len(vh)-1,0,get_vh_id(div_up(gr.fir,len(gr.sec))),-1);
        for (auto b:gr.sec){
            st.update(1,0,len(vh)-1,0,get_vh_id(div_up(gr.fir-b,len(gr.sec)-1)),+1);
            bool cur_ans=(st.get_min(1,0,len(vh)-1,0,len(vh)-1)<=0);
            ans+=char('0'+cur_ans);
            st.update(1,0,len(vh)-1,0,get_vh_id(div_up(gr.fir-b,len(gr.sec)-1)),-1);
        }
        st.update(1,0,len(vh)-1,0,get_vh_id(div_up(gr.fir,len(gr.sec))),+1);
    }
    cout<<ans<<"\n";
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int test;
    cin>>test;
    while (test--){
        solve();
    }
}