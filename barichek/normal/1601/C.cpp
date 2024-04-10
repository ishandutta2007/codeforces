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

const int max_n = 2e6+10, inf = 1000111222;

namespace fast_F{
    pii f[max_n];

    int T;

    void normalize(int pos)
    {
        if (f[pos].sec<T){
            f[pos]=mp(0,T);
        }
    }

    void upd(int pos,int val)
    {
        for (int i=pos;i<max_n;i|=i+1){
            normalize(i);
            f[i].fir+=val;
        }
    }

    int get(int pos)
    {
        int res=0;
        for (int i=pos;i>=0;i&=i+1,i--){
            normalize(i);
            res+=f[i].fir;
        }
        return res;
    }

    int get(int l,int r)
    {
        if (l>r){
            return 0;
        }
        return get(r)-get(l-1);
    }
}

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

struct node
{
    int res,plus,minus;

    node()
    {
        res=0;
        plus=0;
        minus=0;
    }

    void upd_leaf(int val)
    {
        plus=(val==+1);
        minus=(val==-1);
        res=0;
    }
};

void merge(node& a,const node& b,const node& c)
{
    a.plus=b.plus+c.plus;
    a.minus=b.minus+c.minus;
    a.res=min(b.res+c.minus,b.plus+c.res);
}

struct segment_tree {
    node TT[4 * max_n / 2];

    void build(int v, int l, int r) {
        if (l == r) {
            TT[v].upd_leaf(+1);
            return;
        }
        int mid = (l + r) / 2;
        build(2 * v, l, mid);
        build(2 * v + 1, mid + 1, r);
        merge(TT[v],TT[v*2],TT[v*2+1]);
    }

    void update(int v, int l, int r, int pos, int value) {
        if (l == r) {
            TT[v].upd_leaf(value);
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid) {
            update(2 * v, l, mid, pos, value);
        } else {
            update(2 * v + 1, mid + 1, r, pos, value);
        }
        merge(TT[v],TT[v*2],TT[v*2+1]);
    }

//    node get(int v, int tl, int tr, int l, int r) {
//        if (tl == l && tr == r) {
//            return TT[v];
//        }
//        int mid = (tl + tr) / 2;
//        if (r <= mid) {
//            return get(2 * v, tl, mid, l, r);
//        } else if (l > mid) {
//            return get(2 * v + 1, mid + 1, tr, l, r);
//        }
//        node res;
//        merge(res,get(2 * v, tl, mid, l, mid), get(2 * v + 1, mid + 1, tr, mid + 1, r));
//        return res;
//    }
};

int a[max_n];
int b[max_n];

segment_tree st;

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int test;
    test=fastio::read_int();
    while (test--){
        int n,m;
        n=fastio::read_int();
        m=fastio::read_int();
        vector<int> vh;
        for (int i=0;i<n;i++){
            a[i]=fastio::read_int();
            vh.pb(a[i]);
        }
        for (int i=0;i<m;i++){
            b[i]=fastio::read_int();
            vh.pb(b[i]);
        }
        sort(all(vh));
        vh.resize(unique(all(vh))-vh.begin());
        for (int i=0;i<n;i++){
            a[i]=lower_bound(all(vh),a[i])-vh.begin();
        }
        for (int i=0;i<m;i++){
            b[i]=lower_bound(all(vh),b[i])-vh.begin();
        }

        fast_F::T++;
        ll ans_A=0;
        for (int i=0;i<n;i++){
            ans_A+=fast_F::get(a[i]+1,max_n-1);
            fast_F::upd(a[i],+1);
        }


        ll ans_B=0;
        vector<pii> events;
        for (int i=0;i<n;i++){
            events.pb(mp(a[i],max_n+i));
        }
        for (int i=0;i<m;i++){
            events.pb(mp(b[i],i));
        }
        sort(all(events));
        st.build(1,0,n-1);
        for (int i=0;i<len(events);){
            int j=i;
            while (j+1<len(events) && events[j+1].fir==events[i].fir){
                j++;
            }
            /// [i;j]
            for (int k=i;k<=j;k++){
                if (events[k].sec>=max_n){
                    st.update(1,0,n-1,events[k].sec-max_n,0);
                }
            }
            for (int k=i;k<=j;k++){
                if (events[k].sec<max_n){
                    ans_B+=st.TT[1].res;
                }
            }
            for (int k=i;k<=j;k++){
                if (events[k].sec>=max_n){
                    st.update(1,0,n-1,events[k].sec-max_n,-1);
                }
            }

            i=j+1;
        }


        fastio::write_int(ans_A+ans_B);
        fastio::write_char('\n');
    }
    fastio::write_flush();
}