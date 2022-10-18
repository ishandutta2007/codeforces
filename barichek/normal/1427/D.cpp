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

const int max_n = -1, inf = 1000111222;

int n;
int a[100];
int b[100];

vector<vector<int>> ans;

void do_op(vector<int> op)
{
    assert(len(op)>=2);
    int sum=0;
    for (auto i:op){
        sum+=i;
    }
    assert(sum==n);

    ans.pb(op);

    int cur_pos=0;
    for (int i=len(op)-1;i>=0;i--){
        int d=op[i];
        for (int j=1;j<=d;j++){
            b[cur_pos+j]=a[n-cur_pos-d+j];
        }
        cur_pos+=d;
    }
    for (int i=1;i<=n;i++){
        a[i]=b[i];
    }
}

void add_op(vector<int>& op,int mod_d)
{
//    cout<<"add+op :: "<<mod_d<<"\n";
    assert(mod_d>0);
    op.pb(mod_d);
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    bool is_reversed_now = 0;
    for (int iter=1;iter<n;iter++){
        int pos=-1;
        int cur_value_to_find = n-iter+1;
        for (int i=1;i<=n;i++){
            if (a[i]==cur_value_to_find){
                pos=i;
            }
        }

//        cout<<"iter :: "<<iter<<" :: ";
//        for (int i=1;i<=n;i++){
//            cout<<a[i]<<" ";
//        }
//        cout<<"\n";

        if (!is_reversed_now){
            if (cur_value_to_find==n && pos==1){
                is_reversed_now ^= 1;
            }
            else{
                vector<int> op;
                if (pos!=1){
                    add_op(op,pos-1);
                }
                add_op(op,cur_value_to_find-pos+1);
                for (int j=cur_value_to_find+1;j<=n;j++){
                    add_op(op,1);
                }
                do_op(op);

                is_reversed_now^=1;
            }
        }
        else{
            vector<int> op;
            for (int j=cur_value_to_find+1;j<=n;j++){
                add_op(op,1);
            }
            add_op(op,pos-len(op));
            if (pos!=n){
                add_op(op,n-pos);
            }
            do_op(op);

            is_reversed_now^=1;
        }
    }

    if (is_reversed_now){
        vector<int> op;
        for (int j=1;j<=n;j++){
            add_op(op,1);
        }
        do_op(op);
    }

    for (int i=1;i<=n;i++){
        assert(a[i]==i);
    }

    cout<<len(ans)<<"\n";
    for (auto op:ans){
        cout<<len(op)<<" ";
        for (auto i:op){
            cout<<i<<" ";
        }
        cout<<"\n";
    }
}