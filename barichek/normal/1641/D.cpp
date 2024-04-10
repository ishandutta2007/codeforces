#pragma GCC optimize("Ofast", "unroll-loops")
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

const int max_n = 1e5+10, inf = 1000111222;

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

const int max_m=5;

inline bool get_bit(int mask,int bit)
{
    return (mask>>bit)&1;
}

int n,m;
int a[max_n][max_m];
int w[max_n];

int p[max_n];

int buf[max_m];
int sz_buf;

int cnt[32*max_n];

int rem_id[max_n][1ll<<max_m];

void F_clr()
{
    memset(cnt,0,sizeof(cnt));
}

void F_add(int id,int kf)
{
    for (int mask=0;mask<(1ll<<m);mask++){
        cnt[rem_id[id][mask]]+=kf;
    }
}

int F_get(int id)
{
    int res=0;
    for (int mask=0;mask<(1ll<<m);mask++){
        if (__builtin_popcountll(mask)%2==0){
            res+=cnt[rem_id[id][mask]];
        }
        else{
            res-=cnt[rem_id[id][mask]];
        }
    }
    return res;
}

ll get(int X)
{
//    cout<<"get :: "<<X<<"\n";
    F_clr();
    int pp=0;
    ll res=0;
    for (int i=0;i<n;i++){
        while (pp<i && w[i]+w[pp]>=X){
            F_add(pp,+1);
            pp++;
        }
        while (pp>0 && w[i]+w[pp-1]<X){
            pp--;
            F_add(pp,-1);
        }
        res+=F_get(i);
    }
    return res;
}
int new_a[max_n][5];
int new_w[max_n];
 
int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    n=fastio::read_int();
    m=fastio::read_int();
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            a[i][j]=fastio::read_int();
        }
        w[i]=fastio::read_int();
 
        p[i]=i;
    }
    sort(p,p+n,[&](const int& i1,const int &i2){
        return w[i1]>w[i2];
    });
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            new_a[i][j]=a[p[i]][j];
        }
        new_w[i]=w[p[i]];
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            a[i][j]=new_a[i][j];
        }
        w[i]=new_w[i];
    }

    vector<pair<ll,pii>> vh;
    for (int id=0;id<n;id++){
        for (int mask=0;mask<(1ll<<m);mask++){
            sz_buf=0;
            for (int i=0;i<m;i++){
                if (get_bit(mask,i)){
                    buf[sz_buf++]=a[id][i];
                }
            }
            sort(buf,buf+sz_buf);
            ll hh1=0;
            ll hh2=0;
            for (int i=0;i<sz_buf;i++){
                hh1=hh1*1342341211+buf[i];
                hh2=(hh2*1342341213+buf[i])%(int(1e9+7));
            }
//            cout<<id<<" "<<mask<<" :: "<<hh1<<" "<<hh2<<"\n";
            vh.pb(mp(hh1,mp(id,mask)));
        }
    }
    sort(all(vh));
    int kek=0;
    for (int i=0;i<len(vh);){
        int j=i;
        while (j<len(vh) && vh[j].fir==vh[i].fir){
            j++;
        }
        /// [i;j)

        for (int k=i;k<j;k++){
            rem_id[vh[k].sec.fir][vh[k].sec.sec]=kek;
//            cout<<"rem_id :: "<<vh[k].sec.fir<<" "<<vh[k].sec.sec<<" :: "<<len(cnt)-1<<"\n";
        }
        kek++;

        i=j;
    }

    int L=0,R=2*inf;
    ll real_pairs=get(0);
    while (R-L>0){
        int M=(1ll*L+1ll*R+1ll)/2ll;
//        cout<<M<<" :: "<<get(M)<<" "<<real_pairs<<"\n";
        if (get(M)==real_pairs){
            L=M;
        }
        else{
            R=M-1;
        }
    }
    cout<<(L>2e9 ? -1 : L)<<"\n";
}