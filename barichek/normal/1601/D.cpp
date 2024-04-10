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

const int max_n = 5e5+10, inf = 1000111222;

namespace fastio {

    const int buf_size = 1 << 14, small = 30;
    char buf_read[buf_size + small];
    char buf_write[buf_size + small];
    char *ptr_read = buf_read + buf_size;
    char *ptr_write = buf_write;

    long long read_int() {
        auto getChar = []() {
            if (ptr_read == buf_read + buf_size){
                buf_read[fread(buf_read, 1, buf_size, stdin)] = 0;
                ptr_read = buf_read;
            }
            return *ptr_read++;
        };
        char c = getChar();
        while (c && (c < '0' || c > '9') && c != '-') {
            c = getChar();
        }
        long long z = 1;
        if (c == '-') {
            z = -1;
            c = getChar();
        }
        long long res = 0;
        while (c >= '0' && c <= '9'){
            res = res * 10 + (c - '0');
            c = getChar();
        }
        return z * res;
    }

    void write_flush() {
        fwrite(buf_write, 1, ptr_write - buf_write, stdout);
        ptr_write = buf_write;
    }

    void write_int(long long x) {
        if (x < 0) {
            *ptr_write++ = '-';
            x = -x;
        }
        char *start = ptr_write;
        if (!x) {
            *ptr_write++ = '0';
        }
        while (x) {
            *ptr_write++ = x % 10 + '0';
            x /= 10;
        }
        reverse(start, ptr_write);
        if (ptr_write >= buf_write + buf_size) {
            write_flush();
        }
    }

    void write_char(char c) {
        *ptr_write++ = c;
        if (ptr_write >= buf_write + buf_size) {
            write_flush();
        }
    }

}

template<typename T>
struct segment_tree {
    vector<pair<T, pair<int, int>>> all[4 * max_n];

    void build(int v, int l, int r, T a[]) {
        if (l == r) {
            all[v].push_back({a[l], {-1, -1}});
            return;
        }
        int mid = (l + r) / 2;
        build(2 * v, l, mid, a);
        build(2 * v + 1, mid + 1, r, a);
        int p1 = 0, p2 = 0;
        all[v].reserve(all[2 * v].size() + all[2 * v + 1].size());
        while (p1 < all[2 * v].size() || p2 < all[2 * v + 1].size()) {
            if (p1 == all[2 * v].size()) {
                all[v].emplace_back(all[2 * v + 1][p2].first, make_pair(p1, p2));
                ++p2;
            } else if (p2 == all[2 * v + 1].size()) {
                all[v].emplace_back(all[2 * v][p1].first, make_pair(p1, p2));
                ++p1;
            } else if (all[2 * v][p1] < all[2 * v + 1][p2]) {
                all[v].emplace_back(all[2 * v][p1].first, make_pair(p1, p2));
                ++p1;
            } else {
                all[v].emplace_back(all[2 * v + 1][p2].first, make_pair(p1, p2));
                ++p2;
            }
        }
    }

    int get_cnt_more_equal(int v, int tl, int tr, int l, int r, int pos) {
        if (pos == all[v].size()) {
            return 0;
        }
        if (tl == l && tr == r) {
            return all[v].size() - pos;
        }
        int mid = (tl + tr) / 2;
        if (r <= mid) {
            return get_cnt_more_equal(2 * v, tl, mid, l, r, all[v][pos].second.first);
        } else if (l > mid) {
            return get_cnt_more_equal(2 * v + 1, mid + 1, tr, l, r, all[v][pos].second.second);
        }
        return get_cnt_more_equal(2 * v, tl, mid, l, mid, all[v][pos].second.first) +
               get_cnt_more_equal(2 * v + 1, mid + 1, tr, mid + 1, r, all[v][pos].second.second);
    }

    int get_cnt_more_equal(int l, int r, T x) {
        const int pos = lower_bound(all[1].begin(), all[1].end(), make_pair(x, make_pair(-2, -2))) - all[1].begin();
        return get_cnt_more_equal(1, 0, all[1].size() - 1, l, r, pos);
    }
};

segment_tree<int> st;

int to_build_st[max_n];

pii b[max_n];

#define s first
#define a second

int dp[max_n];

void maximize(int& a,int b)
{
    a=max(a,b);
}

const bool local=0;

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int n,d;
    if (local){
        cin>>n>>d;
    }
    else{
        n=fastio::read_int();
        d=fastio::read_int();
    }
    int m=0;
    for (int i=0;i<n;i++){
        int s,a;
        if (local){
            cin>>s>>a;
        }
        else{
            s=fastio::read_int();
            a=fastio::read_int();
        }
        if (s>=d){
            b[m++]=mp(s,a);
        }
    }
    n=m;

    if (n==0){
        if (local){
            cout<<0<<"\n";
        }
        else{
            fastio::write_char('0');
            fastio::write_char('\n');
            fastio::write_flush();
        }

        return 0;
    }

    sort(b,b+n);
    for (int i=0;i<n;i++){
        int A=b[i].a;
        b[i].a=partition_point(b,b+n,[&](pii a){
            return a.fir<A;
        })-b;

        to_build_st[i] = -(b[i].a<=i ? b[i].a : inf);
    }

//    cout<<"to build st :: ";
//    for (int i=0;i<=n;i++){
//        cout<<to_build_st[i]<<" ";
//    }
//    cout<<"\n";

    st.build(1,0,n,to_build_st);
    for (int i=0;i<n;i++){
//        cout<<i<<" "<<b[i].s<<" "<<b[i].a<<"\n";
        if (i){
            maximize(dp[i],dp[i-1]);
        }

        if (b[i].a<=i){
            dp[i] += 1;
        }
        else{
            maximize(dp[b[i].a],dp[i] + st.get_cnt_more_equal(i,b[i].a-1,-i) + 1);
        }

//        for (int j=0;j<=n;j++){
//            cout<<"dp["<<j<<"]="<<dp[j]<<" ";
//        }
//        cout<<"\n";
    }

    if (local){
        cout<<*max_element(dp,dp+n+1)<<"\n";
    }
    else{
        fastio::write_int(*max_element(dp,dp+n+1));
        fastio::write_char('\n');
        fastio::write_flush();
    }
}