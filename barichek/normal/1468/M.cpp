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

const int max_n = 3e5+10, inf = 1000111222;


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

vector<int> a[max_n];
vector<int> vh;
int sz[max_n];
int p[max_n];
int pos_in_p[max_n];
bool cur_have[max_n];

void solve()
{
    int n;
    n=fastio::read_int();
    vh.clear();
    for (int i=0;i<n;i++){
        int s;
        s=fastio::read_int();
        a[i].clear();
        while (s--){
            int b;
            b=fastio::read_int();
            a[i].pb(b);
            vh.pb(b);
        }
    }
    sort(all(vh));
    vh.resize(unique(all(vh))-vh.begin());
    auto get_vh_id=[&](int a)
    {
        return lower_bound(all(vh),a)-vh.begin();
    };
    for (int i=0;i<n;i++){
        for (auto& j:a[i]){
            j=n+get_vh_id(j);
        }
    }

    int ans1=-1;
    int ans2=-1;
    const int N=n+len(vh);
    for (int i=0;i<N;i++){
        sz[i]=0;
        if (i>=n){
            a[i].clear();
        }
    }
    for (int i=0;i<n;i++){
        for (auto j:a[i]){
            sz[i]++;
            sz[j]++;

            a[j].pb(i);
        }
    }
    iota(p,p+N,0);
    sort(p,p+N,[&](const int& a,const int& b){
        return sz[a]<sz[b];
    });
    for (int i=0;i<N;i++){
        pos_in_p[p[i]]=i;
    }

    for (int i=0;i<N;i++){
        for (auto j:a[i]){
            if (pos_in_p[j]<pos_in_p[i]){
                for (auto k:a[j]){
                    if (pos_in_p[k]<pos_in_p[i]){
                        if (cur_have[k]){
                            ans1=i;
                            ans2=k;
                        }
                        else{
                            cur_have[k]=1;
                        }
                    }
                }
            }
        }
        for (auto j:a[i]){
            if (pos_in_p[j]<pos_in_p[i]){
                for (auto k:a[j]){
                    if (pos_in_p[k]<pos_in_p[i]){
                        cur_have[k]=0;
                    }
                }
            }
        }
    }
    if (ans1!=-1){
        if (ans1<n){
            fastio::write_int(ans1+1);
            fastio::write_char(' ');
            fastio::write_int(ans2+1);
            fastio::write_char('\n');
        }
        else{
            int new_ans1=-1;
            int new_ans2=-1;
            for (int i=0;i<n;i++){
                int cnt=0;
                for (auto j:a[i]){
                    if (j==ans1 || j==ans2){
                        cnt++;
                    }
                }
                assert(cnt<=2);
                if (cnt==2){
                    if (new_ans1==-1){
                        new_ans1=i;
                    }
                    else{
                        new_ans2=i;
                    }
                }
            }
            assert(new_ans1!=-1);
            assert(new_ans2!=-1);

            fastio::write_int(new_ans1+1);
            fastio::write_char(' ');
            fastio::write_int(new_ans2+1);
            fastio::write_char('\n');
        }
    }
    else{
        fastio::write_int(-1);
        fastio::write_char('\n');
    }
}

#include<ctime>
void sleep(double seconds)
{
    double start = clock();
    while ((clock() - start) / CLOCKS_PER_SEC < seconds){
        /// wait
    }
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    sleep(0.5);

    int test;
    test=fastio::read_int();
    while (test--){
        solve();
    }

    fastio::write_flush();
}