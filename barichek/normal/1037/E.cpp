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


namespace fastio {

    const int buf_size = 1 << 14, small = 30;
    char buf_read[buf_size + small];
    char buf_write[buf_size + small];
    char *ptr_read = buf_read + buf_size;
    char *ptr_write = buf_write;

    long long read_int() {
        ll x;
        cin>>x;
        return x;
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

vector<int> g[max_n];

pii a[max_n];

int q[max_n];
int sz[max_n];
int ans[max_n];
bool deleted[max_n];

#include <ctime>
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

    int n,m,k;
    n=fastio::read_int();
    m=fastio::read_int();
    k=fastio::read_int();

    for (int i=0;i<m;i++){
        a[i].fir=fastio::read_int();
        a[i].sec=fastio::read_int();
        a[i].fir--;
        a[i].sec--;
        sz[a[i].fir]++;
        sz[a[i].sec]++;
        g[a[i].fir].pb(i);
        g[a[i].sec].pb(i);
    }

    int L=0,R=0;
    for (int i=0;i<n;i++){
        if (sz[i]<k){
            q[R++]=i;
        }
    }
    for (int i=m-1;i>=0;i--){
        while (L<R){
            const int u=q[L++];
            for (auto edge_id:g[u]){
                if (deleted[edge_id]){
                    continue;
                }
                deleted[edge_id]=1;

                const int wh=u^(a[edge_id].fir^a[edge_id].sec);
                sz[u]--;
                if (sz[wh]--==k){
                    q[R++]=wh;
                }
            }
        }
        ans[i]=n-R;

        if (deleted[i]){
            continue;
        }
        deleted[i]=1;
        if (sz[a[i].fir]--==k){
            q[R++]=a[i].fir;
        }
        if (sz[a[i].sec]--==k){
            q[R++]=a[i].sec;
        }
    }
    
    
    

    for (int i=0;i<m;i++){
        fastio::write_int(ans[i]);
        fastio::write_char('\n');
    }

    fastio::write_flush();
}