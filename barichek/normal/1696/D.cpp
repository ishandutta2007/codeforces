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

const int max_n = 5e5+10, inf = 1000111222;

template<typename T>
struct segment_tree_max {
    pair<T, int> mx[4 * max_n];

    void build(int v, int l, int r, T a[]) {
        if (l == r) {
            mx[v] = {a[l], l};
            return;
        }
        int mid = (l + r) / 2;
        build(2 * v, l, mid, a);
        build(2 * v + 1, mid + 1, r, a);
        mx[v] = max(mx[2 * v], mx[2 * v + 1]);
    }

    void update(int v, int l, int r, int pos, T value) {
        if (l == r) {
            mx[v] = {value, l};
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

    pair<T, int> get_max(int v, int tl, int tr, int l, int r) {
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

segment_tree_max<int> st_mx[2];

template<typename T>
struct segment_tree_min {
    pair<T, int> mn[4 * max_n];

    void build(int v, int l, int r, T a[]) {
        if (l == r) {
            mn[v] = {a[l], l};
            return;
        }
        int mid = (l + r) / 2;
        build(2 * v, l, mid, a);
        build(2 * v + 1, mid + 1, r, a);
        mn[v] = min(mn[2 * v], mn[2 * v + 1]);
    }

    void update(int v, int l, int r, int pos, T value) {
        if (l == r) {
            mn[v] = {value, l};
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

    pair<T, int> get_min(int v, int tl, int tr, int l, int r) {
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

segment_tree_min<int> st_mn[2];

int a[max_n];

int as_mx[2][max_n];
int as_mn[2][max_n];

int to_build[max_n];

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
        {
            vector<pii> vmn={mp(-inf,-1)};
            vector<pii> vmx={mp(inf,-1)};
            for (int i=0;i<n;i++){
                while (a[i]<vmn.back().fir){
                    vmn.pop_back();
                }
                while (a[i]>vmx.back().fir){
                    vmx.pop_back();
                }
                as_mn[0][i]=vmn.back().sec+1;
                as_mx[0][i]=vmx.back().sec+1;
                vmn.pb(mp(a[i],i));
                vmx.pb(mp(a[i],i));
            }
        }
        {
            vector<pii> vmn={mp(-inf,n)};
            vector<pii> vmx={mp(inf,n)};
            for (int i=n-1;i>=0;i--){
                while (a[i]<vmn.back().fir){
                    vmn.pop_back();
                }
                while (a[i]>vmx.back().fir){
                    vmx.pop_back();
                }
                as_mn[1][i]=vmn.back().sec-1;
                as_mx[1][i]=vmx.back().sec-1;
                vmn.pb(mp(a[i],i));
                vmx.pb(mp(a[i],i));
            }
        }

        for (int i=0;i<n;i++){
            to_build[i]=as_mx[1][i];
        }
        st_mx[0].build(1,0,n-1,to_build);
        for (int i=0;i<n;i++){
            to_build[i]=as_mn[1][i];
        }
        st_mx[1].build(1,0,n-1,to_build);
        for (int i=0;i<n;i++){
            to_build[i]=as_mx[0][i];
        }
        st_mn[0].build(1,0,n-1,to_build);
        for (int i=0;i<n;i++){
            to_build[i]=as_mn[0][i];
        }
        st_mn[1].build(1,0,n-1,to_build);

        vector<int> dist(n,inf);
        queue<int> q;
        auto mark_used=[&](int pos,int d)
        {
            dist[pos]=d;
            q.push(pos);

            st_mx[0].update(1,0,n-1,pos,-inf);
            st_mx[1].update(1,0,n-1,pos,-inf);
            st_mn[0].update(1,0,n-1,pos,+inf);
            st_mn[1].update(1,0,n-1,pos,+inf);
        };
        mark_used(0,0);
        while (!q.empty()){
            int now=q.front();
            q.pop();

            {
                int L=as_mn[0][now];
                int R=now;
                while (1){
                    pii kek=st_mx[0].get_max(1,0,n-1,L,R);
                    if (kek.fir>=now){
                        mark_used(kek.sec,dist[now]+1);
                    }
                    else{
                        break;
                    }
                }
            }
            {
                int L=as_mx[0][now];
                int R=now;
                while (1){
                    pii kek=st_mx[1].get_max(1,0,n-1,L,R);
                    if (kek.fir>=now){
                        mark_used(kek.sec,dist[now]+1);
                    }
                    else{
                        break;
                    }
                }
            }

            {
                int L=now;
                int R=as_mn[1][now];
                while (1){
                    pii kek=st_mn[0].get_min(1,0,n-1,L,R);
                    if (kek.fir<=now){
                        mark_used(kek.sec,dist[now]+1);
                    }
                    else{
                        break;
                    }
                }
            }
            {
                int L=now;
                int R=as_mx[1][now];
                while (1){
                    pii kek=st_mn[1].get_min(1,0,n-1,L,R);
                    if (kek.fir<=now){
                        mark_used(kek.sec,dist[now]+1);
                    }
                    else{
                        break;
                    }
                }
            }
        }
        cout<<dist[n-1]<<"\n";
    }
}