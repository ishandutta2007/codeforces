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

const int max_n_for_st=7*max_n;

template<typename T>
struct segment_tree {
    static const T default_value = -1012345678;

    T f[4 * max_n_for_st];
    T sum[4 * max_n_for_st];

    void build(int v, int l, int r) {
        f[v] = default_value;
        if (l == r) {
            sum[v] = 0;
            return;
        }
        int mid = (l + r) / 2;
        build(2 * v, l, mid);
        build(2 * v + 1, mid + 1, r);
        sum[v] = sum[2 * v] + sum[2 * v + 1];
    }

    void push(int v, int l, int r, int mid) {
        if (f[v] != default_value) {
            sum[2 * v] = f[v] * (mid - l + 1);
            sum[2 * v + 1] = f[v] * (r - mid);
            f[2 * v] = f[v];
            f[2 * v + 1] = f[v];
            f[v] = default_value;
        }
    }

    void update(int v, int tl, int tr, int l, int r, T value) {
        if (tl == l && tr == r) {
            f[v] = value;
            sum[v] = value * (r - l + 1);
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
        sum[v] = sum[2 * v] + sum[2 * v + 1];
    }

    T get_sum(int v, int tl, int tr, int l, int r) {
        if (tl == l && tr == r) {
            return sum[v];
        }
        int mid = (tl + tr) / 2;
        push(v, tl, tr, mid);
        if (r <= mid) {
            return get_sum(2 * v, tl, mid, l, r);
        } else if (l > mid) {
            return get_sum(2 * v + 1, mid + 1, tr, l, r);
        }
        return get_sum(2 * v, tl, mid, l, mid) + get_sum(2 * v + 1, mid + 1, tr, mid + 1, r);
    }
};

segment_tree<ll> st;

int g[max_n];
int c[max_n];

int d[max_n];

ll waits_from[max_n];

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,t;
    cin>>n>>t;
    for (int i=1;i<=n;i++){
        cin>>g[i]>>c[i];
    }
    ll base_ans=0;
    for (int i=1;i<n;i++){
        int dd;
        cin>>dd;
        base_ans+=dd;
        d[i+1]=d[i]+dd;
        d[i+1]%=t;
    }

    vector<int> vh;
    for (int i=0-1;i<=0+1;i++){
        vh.pb((i+t)%t);
    }
    for (int i=(t-1)-1;i<=(t-1)+1;i++){
        vh.pb((i+t)%t);
    }
    for (int i=1;i<=n;i++){
        int to_my_fail = (t-c[i])%t;

        int my_k1 = ((to_my_fail-d[i])%t+t)%t;

        vh.pb(my_k1);

        int L=g[i],R=t-1;
        L-=d[i]+c[i];
        while (L<0){
            L+=t;
        }
        R-=d[i]+c[i];
        while (R<0){
            R+=t;
        }

        for (int i=L-1;i<=L+1;i++){
            vh.pb((i+t)%t);
        }
        for (int i=R-1;i<=R+1;i++){
            vh.pb((i+t)%t);
        }
    }
    sort(all(vh));
    vh.resize(unique(all(vh))-vh.begin());
    auto get_vh_id=[&](int x)
    {
        return lower_bound(all(vh),x)-vh.begin();
    };

    st.build(1,0,len(vh)-1);

    for (int i=n;i>=1;i--){
        int to_my_fail = (t-c[i])%t;

        int my_k1 = ((to_my_fail-d[i])%t+t)%t;

        waits_from[i]=0;

        int my_k1_vh_id=get_vh_id(my_k1);
        int j=st.get_sum(1,0,len(vh)-1,my_k1_vh_id,my_k1_vh_id);
        LOG(i,"found",j);

        if (j==0){
            waits_from[i]=0;
        }
        else{
            int time_when_there = (my_k1+d[j])%t;
            if ((time_when_there + c[j]) % t < g[j]){
                while (1){

                }
            }
            waits_from[i] = (t-(time_when_there+c[j])%t) + waits_from[j];
        }

        int L=g[i],R=t-1;
        L-=d[i]+c[i];
        while (L<0){
            L+=t;
        }
        R-=d[i]+c[i];
        while (R<0){
            R+=t;
        }

        auto add_segment=[&](int L,int R)
        {
            int id=i;
            if (L>R){
                while (1){

                }
            }
            LOG("add_segment",L,R,id);
            st.update(1,0,len(vh)-1,get_vh_id(L),get_vh_id(R),id);
        };

        if (L<=R){
            add_segment(L,R);
        }
        else{
            add_segment(0,R);
            add_segment(L,t-1);
        }
    }

    ll best_ans=1e18;
    for (int i=0;i<len(vh);i++){
        int val=st.get_sum(1,0,len(vh)-1,i,i);
        int my_start_time=vh[i];
        LOG(my_start_time,val);
        if (val==0){
            best_ans=0;
        }
        else{
            int j=val;
            int time_when_there=(my_start_time+d[j])%t;
            ll cur_ans = (t-(time_when_there+c[j])%t) + waits_from[j];
            best_ans=min(best_ans,cur_ans);
        }
    }
    cout<<base_ans+best_ans<<"\n";
}