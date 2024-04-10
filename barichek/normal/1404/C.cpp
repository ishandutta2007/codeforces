#pragma GCC optimize("Ofast", "unroll-loops")
#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "avx")

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

const int B_size = 2000;
const int num_of_blocks = max_n / B_size + 2;

const int buf_size=4096;
static unsigned char buf[buf_size];
int buf_pos,buf_len;

inline bool is_eof()
{
    if (buf_pos==buf_len){
        buf_pos=0;
        buf_len=fread(buf,1,buf_size,stdin);
        if (buf_len==0){
            return 1;
        }
    }
    return 0;
}

inline int get_char()
{
    return is_eof()?-1:buf[buf_pos++];
}

inline int read_char()
{
    char c=get_char();
    while (c!=-1&&c<=32){
        c=get_char();
    }
    return c;
}

inline int read_int()
{
    int m=1;
    int x=0;
    char c=read_char();
    if (c=='-'){
        m=-1;
        c=get_char();
    }
    else if (c=='+'){
        c=get_char();
    }
    while ('0'<=c&&c<='9'){
        x=x*10+(c-'0');
        c=get_char();
    }
    return x*m;
}

int a[max_n];
int min_value_in_to_get_this_inc[num_of_blocks][B_size+1];
short int inc_by_value_in[num_of_blocks][max_n];

const bool debug=0;

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    cerr<<(sizeof(inc_by_value_in)>>20)<<"\n";

    int n,q;
    if (debug){
        n=3e5;
        q=3e5;
    }
    else{
//        scanf("%d%d",&n,&q);
        n=read_int();
        q=read_int();
    }
    for (int i=0;i<n;i++){
        if (debug){
            a[i]=(i+1);
        }
        else{
//            scanf("%d",&a[i]);
            a[i]=read_int();
        }
        a[i]=((i+1)-a[i]>=0 ? (i+1)-a[i] : 1e9);
    }
//    for (int i=0;i<n;i++){
//        cout<<i<<" :: "<<a[i]<<"\n";
//    }

    auto precalc=[&]()
    {
        for (int i=0;i<n;i+=B_size){
            int L=i;
            int R=min(n-1,i+B_size-1);
            /// [L;R]
            int block_id = i/B_size;

            min_value_in_to_get_this_inc[block_id][0]=0;

//            cout<<"precalc :: "<<block_id<<" "<<L<<" "<<R<<"\n";
            for (int inc=1;inc<=B_size;inc++){
                // calc min_value_in_to_get_this_inc[block_id][inc]
                int cur_ans=min_value_in_to_get_this_inc[block_id][inc-1];
                int cur_inc = 0;
                int cur_min_add=1e9;
                for (int j=L;j<=R;j++){
                    if (a[j]<=cur_ans){
                        cur_ans++;
                        cur_inc++;
                    }
                    else{
                        cur_min_add=min(cur_min_add, a[j]-cur_ans);
                    }
                }
//                cout<<"  "<<"lols :: "<<inc<<" "<<cur_inc<<" "<<cur_ans<<" "<<cur_min_add<<"\n";
                if (cur_inc>=inc){
                    min_value_in_to_get_this_inc[block_id][inc] = min_value_in_to_get_this_inc[block_id][inc-1];
                }
                else if (min_value_in_to_get_this_inc[block_id][inc-1] + cur_min_add >= n+1){
                    for (int jj=inc;jj<=B_size;jj++){
                        min_value_in_to_get_this_inc[block_id][jj]=n+1;
                    }
                    break;
                }
                else{
                    min_value_in_to_get_this_inc[block_id][inc] = min_value_in_to_get_this_inc[block_id][inc-1] + cur_min_add;
                }
//                cout<<"  "<<"result :: "<<min_value_in_to_get_this_inc[block_id][inc]<<"\n";
            }

            for (int inc=1;inc<=B_size;inc++){
                int from = min_value_in_to_get_this_inc[block_id][inc-1];
                int to = min_value_in_to_get_this_inc[block_id][inc];
                for (int j=from;j<to;j++){
                    inc_by_value_in[block_id][j] = inc-1;
                }
            }
            for (int j=min_value_in_to_get_this_inc[block_id][B_size];j<=n;j++){
                inc_by_value_in[block_id][j] = B_size;
            }
        }
    };
    auto process_blocks=[&](int l,int r,int& cur_ans)
    {
//        cout<<"process_blocks :: "<<l<<" "<<r<<" "<<cur_ans<<"\n";
        for (int i=l;i<=r;i++){
//            cout<<"inc_by_value_in["<<i<<"]["<<cur_ans<<"] :: "<<inc_by_value_in[i][cur_ans]<<"\n";
            cur_ans+=inc_by_value_in[i][cur_ans];
        }
    };
    auto get_ans=[&](int l,int r)
    {
//        cout<<"get_ans :: "<<l<<" "<<r<<"\n";
//        cerr<<"get_ans :: "<<l/B_size<<" "<<r/B_size<<"\n";
        if (l/B_size + 1 >= r/B_size){
//            cerr<<"here1"<<"\n";
            int cur_ans=0;
            for (int i=l;i<=r;i++){
//                cerr<<"lolus :: "<<i<<" "<<a[i]<<" "<<cur_ans<<"\n";
                cur_ans += (a[i]<=cur_ans);
            }
//            cerr<<"as fast result cur_ans :: "<<cur_ans<<"\n";
            return cur_ans;
        }

        int cur_ans=0;

//        while ((l&(B_size-1))!=0){
//            cur_ans+=(a[l++]<=cur_ans);
//        }
        while ((l%B_size)!=0){
            cur_ans+=(a[l++]<=cur_ans);
        }
//        cout<<"l :: "<<l<<"\n";
        int r1=r;
//        while ((r1&(B_size-1))!=B_size-1){
//            r1--;
//        }
        while ((r1%B_size)!=B_size-1){
            r1--;
        }
//        cout<<"r1 :: "<<r1<<"\n";
        process_blocks(l/B_size,r1/B_size,cur_ans);

        for (int i=r1+1;i<=r;i++){
            cur_ans+=(a[i]<=cur_ans);
        }

        return cur_ans;
    };
    precalc();

    while (q--){
        int x,y;
        if (debug){
            x=1;
            y=1;
        }
        else{
//            scanf("%d%d",&x,&y);
            x=read_int();
            y=read_int();
        }
        int l=x;
        int r=n-y-1;
        int ans=get_ans(l,r);
        cout<<ans<<"\n";
    }
}