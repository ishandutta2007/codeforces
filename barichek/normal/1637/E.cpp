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

const int max_unique_cnt = 800+3;

vector<int> reb[max_n];
int a[max_n];
set<int> best[max_unique_cnt];
int answer_for_best[max_unique_cnt];

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
        map<int,int> cur_cnt;
        for (int i=0;i<n;i++){
            a[i]=fastio::read_int();
            vh.pb(a[i]);
            cur_cnt[a[i]]++;
        }

        vector<int> cnt_values;
        for (auto i:cur_cnt){
            cnt_values.pb(i.sec);
        }
        sort(all(cnt_values));
        cnt_values.resize(unique(all(cnt_values))-cnt_values.begin());
        auto get_cnt_values_id=[&](int a)
        {
            return lower_bound(all(cnt_values),a)-cnt_values.begin();
        };

        sort(all(vh));
        vh.resize(unique(all(vh))-vh.begin());
        auto get_vh_id=[&](int a)
        {
            return lower_bound(all(vh),a)-vh.begin();
        };
        for (int i=0;i<len(vh);i++){
            reb[i].clear();
        }

        for (int i=0;i<max_unique_cnt;i++){
            best[i].clear();
        }
        for (auto i:vh){
            int cur_id=get_cnt_values_id(cur_cnt[i]);
            best[cur_id].insert(i);
            answer_for_best[cur_id]=(best[cur_id].empty()?-1 : *best[cur_id].rbegin());
        }

        for (int i=0;i<m;i++){
            int u,v;
            u=fastio::read_int();
            v=fastio::read_int();
            reb[get_vh_id(u)].pb(v);
            reb[get_vh_id(v)].pb(u);
        }

        ll ans=0;

        for (auto u:vh){
            int cur_id=get_cnt_values_id(cur_cnt[u]);
            best[cur_id].erase(u);
            answer_for_best[cur_id]=(best[cur_id].empty()?-1 : *best[cur_id].rbegin());

            for (auto v:reb[get_vh_id(u)]){
                int cur_id=get_cnt_values_id(cur_cnt[v]);
                best[cur_id].erase(v);
                answer_for_best[cur_id]=(best[cur_id].empty()?-1 : *best[cur_id].rbegin());
            }

            auto get_cur_ans=[&](int x)
            {
                ll res=0;
                int cnt_x=cur_cnt[x];
                for (int cnt_y_id=0;cnt_y_id<len(cnt_values);cnt_y_id++){
//                    cout<<"cnt_y_id :: "<<cnt_y_id<<" :: "<<cnt_values[cnt_y_id]<<"\n";
                    int cnt_y=cnt_values[cnt_y_id];
                    if (answer_for_best[cnt_y_id]!=-1){
//                        cout<<x<<" "<<answer_for_best[cnt_y_id]<<"\n";
//                        cout<<"("<<cnt_x<<" "<<cnt_y<<")\n";
                        res=max(res,1ll*(cnt_x+cnt_y)*(x+answer_for_best[cnt_y_id]));
                    }
                }
                return res;
            };
            ans=max(ans,get_cur_ans(u));

            get_cnt_values_id(cur_cnt[u]);
            best[cur_id].insert(u);
            answer_for_best[cur_id]=(best[cur_id].empty()?-1 : *best[cur_id].rbegin());

            for (auto v:reb[get_vh_id(u)]){
                int cur_id=get_cnt_values_id(cur_cnt[v]);
                best[cur_id].insert(v);
                answer_for_best[cur_id]=(best[cur_id].empty()?-1 : *best[cur_id].rbegin());
            }
        }

        fastio::write_int(ans);
        fastio::write_char('\n');
    }
    fastio::write_flush();
}